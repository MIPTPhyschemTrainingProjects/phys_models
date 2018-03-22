//
// Created by aleksei on 03.03.18.
//

#ifndef PHYSICS_MODEL_HPP
#define PHYSICS_MODEL_HPP

#include <array>
#include <algorithm>
#include <map>
#include <omp.h>
#include <unordered_map>
#include "Vector.hpp"


/**
 * Class for handling physical interaction between objects <i>Particle</i> (e.g. material dots).
 * Class of <i>Particle</i> should have <b>evolute()</b> method.
 *
 * Note: we assume that the interaction of the whole system can be split to two-particles action.
 */
template<typename Particle>
class PhysicsModel {
protected:
    std::map<unsigned long, Particle> _numerated_particles;
    unsigned long total_particles = 0;
    double _dt;

public:
    /**
     * Method that counts the force created by interaction of the two particles
     * @param p1 First particle
     * @param p2 Second particle
     * @return Array of x, y, z components of force applied to the <u>first</u> particle
     */
    virtual Vector getForce(const Particle &p1, const Particle &p2) const = 0;

    explicit PhysicsModel(double dt): _dt(dt)
    {}

    /**
     * Adds particle to the system, so that it will be considered in further evolution
     * @param p Particle to add for evoluting
     */
    void addParticle(const Particle &p) {
        _numerated_particles.insert({total_particles++, p});
    }

    /**
    * Get total number of particles in model
    * @return Number of particles (type long)
    */
    unsigned long getCount() const noexcept { return total_particles; }

    /**
     * Get particle with <b>number</b>. Numbers start with 0
     * @param number The number of a particle
     * @return Reference to the particle
     */
    Particle& getParticle(unsigned long number) { return _numerated_particles.at(number); }

    /**
     * Counts all forces between all particles in current time
     * @return Map of (number, force_array), where <b>number</b> is particle number and <b>force_array</b>
     * is array of force acting on that particle
     */
    std::unordered_map<unsigned long, Vector> _count_all_forces() const noexcept {
        std::unordered_map<unsigned long, Vector> total_forces;

        for(unsigned long i = 0; i < total_particles; i++) {
            omp_lock_t lock;
            omp_init_lock(&lock);
            #pragma omp parallel
            for(unsigned long j = i+1; j < total_particles; j++) {
                omp_set_lock(&lock);
                Vector tmp_force = getForce(_numerated_particles.at(i), _numerated_particles.at(j));

                // Add force applied to the FIRST particle
                total_forces[i] = tmp_force;
                // Change force direction and add as the force applied to the SECOND particle
                tmp_force = -1 * tmp_force;
                total_forces[j] = tmp_force;
                omp_unset_lock(&lock);
            }
            omp_destroy_lock(&lock);
        }
        return total_forces;
    }

    /**
     * Make evolution for <b>dt</b> time (which was defined during Handler creation).
     * This method counts all forces and moves all particles accordingly.
     */
    void makeEvolution(double time=1.0) {
        // Now, let's evolute all the particles
        double curr_time = 0;
        while(curr_time <= time) {
            std::unordered_map<unsigned long, Vector> total_forces =  _count_all_forces();
            #pragma omp parallel for
            for (unsigned long i = 0; i < total_particles; i++) {
                _numerated_particles.at(i).evolute(total_forces.at(i), _dt);
            }
            curr_time += _dt;
        }
    }
};



#endif //PHYSICS_MODEL_HPP
