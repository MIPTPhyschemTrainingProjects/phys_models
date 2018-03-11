//
// Created by aleksei on 03.03.18.
//

#ifndef PHYSICS_MODEL_HPP
#define PHYSICS_MODEL_HPP

#include <array>
#include <algorithm>
#include <map>
#include <omp.h>


/**
 * Class for handling physical interaction between objects <i>Particle</i> (e.g. material dots).
 * Class of <i>Particle</i> should have <b>evolute()</b> method.
 *
 * Note: we assume that the interaction of the whole system can be split to two-particles action.
 */
template<typename Particle>
class PhysicsModel {
protected:
    std::map<long, Particle> _numerated_particles;
    long total_particles = 0;
    float _dt;
    float _total_time;

public:
    /**
     * Method that counts the force created by interaction of the two particles
     * @param p1 First particle
     * @param p2 Second particle
     * @return Array of x, y, z components of force applied to the <u>first</u> particle
     */
    virtual std::array<float, 3> getForce(const Particle &p1, const Particle &p2) const = 0;

    PhysicsModel(float total_time, float dt): _dt(dt), _total_time(total_time)
    {}

    /**
     * Adds particle to the system, so that it will be considered in further evolution
     * @param p Particle to add for evoluting
     */
    void addParticle(const Particle &p) {
        _numerated_particles.insert({total_particles++, p});
    }

    /**
     * Counts E2-distance between two particles.
     * @param p1 First particle.
     * @param p2 Second particle.
     * @return Usual <i>Euclidean</i> distance between them.
     */
    float getParticlesDistance(const Particle& p1, const Particle& p2) const {
        return sqrt(pow(p1.getCoordinates()[0] - p2.getCoordinates()[0], 2)
                    + pow(p1.getCoordinates()[1] - p2.getCoordinates()[1], 2)
                    + pow(p1.getCoordinates()[2] - p2.getCoordinates()[2], 2));
    }

    /**
    * Get total number of particles in model
    * @return Number of particles (type long)
    */
    long getCount() const noexcept { return total_particles; }

    /**
     * Get particle with <b>number</b>. Numbers start with 0
     * @param number The number of a particle
     * @return Reference to the particle
     */
    Particle& getParticle(long number) { return _numerated_particles.at(number); }

    /**
     * Make evolution for <b>dt</b> time (which was defined during Handler creation).
     * This method counts all forces and moves all particles accordingly.
     */
    void makeEvolution() {
        std::map<long, std::array<float, 3>> total_forces;

        for(long i = 0; i < total_particles; i++) {
            omp_lock_t lock;
            omp_init_lock(&lock);
            #pragma omp parallel for
            for(long j = i+1; j < total_particles; j++) {
                omp_set_lock(&lock);
                std::array<float, 3> tmp_force = getForce(_numerated_particles[i], _numerated_particles[j]);

                // Add force applied to the FIRST particle
                total_forces[i] = tmp_force;
                // Change force direction and add as the force applied to the SECOND particle
                std::transform(tmp_force.begin(), tmp_force.end(), tmp_force.begin(),
                               std::bind1st(std::multiplies<float>(), -1));
                total_forces[j] = tmp_force;
                omp_unset_lock(&lock);
            }
            omp_destroy_lock(&lock);
        }
        // Now, let's evolute all the particles
        #pragma omp parallel for
        for(long i = 0; i < total_particles; i++) {
            _numerated_particles[i].evolute(total_forces[i], _dt);
        }
    }
};



#endif //PHYSICS_MODEL_HPP
