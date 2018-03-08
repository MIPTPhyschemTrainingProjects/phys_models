//
// Created by aleksei on 03.03.18.
//

#ifndef MATERIALDOT_TEST_PHYSICSHANDLER_HPP
#define MATERIALDOT_TEST_PHYSICSHANDLER_HPP

#include <array>
#include <algorithm>
#include <map>


/**
 * Class for handling physical interaction between objects <i>Particle</i> (e.g. material dots).
 * Class of <i>Particle</i> should have <b>evolute()</b> method.
 *
 * Note: we assume that the interaction of the whole system can be split to two-particles action.
 */
template<typename Particle>
class PhysicsHandler {
private:
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
    //virtual std::array<float, 3> getForce(const Particle &p1, const Particle &p2) const = 0;

    // TODO: Это -- реализация только для тестирования.
    // TODO: Этот getForce считает силу так, будто частицы соединены пружиной жесткости 0.4
    virtual std::array<float, 3> getForce(const Particle &p1, const Particle &p2) const {
        float k = 0.4;
        std::array<float, 3> res = {0, 0, 0};
        std::transform(p1.getCoordinates().begin(), p1.getCoordinates().end(),
                       p2.getCoordinates().begin(), res.begin(), std::minus<float>());
        std::transform(res.begin(), res.end(), res.begin(), std::bind1st(std::multiplies<float>(), -k));
        return res;
    }

    PhysicsHandler(float total_time, float dt): _total_time(total_time), _dt(dt)
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
            //#pragma omp parallel for
            for(long j = i+1; j < total_particles; j++) {
                std::array<float, 3> tmp_force = getForce(_numerated_particles[i], _numerated_particles[j]);

                // Add force applied to the FIRST particle
                total_forces[i] = tmp_force;
                // Change force direction and add as the force applied to the SECOND particle
                std::transform(tmp_force.begin(), tmp_force.end(), tmp_force.begin(),
                               std::bind1st(std::multiplies<float>(), -1));
                total_forces[j] = tmp_force;
            }
        }
        // Now, let's evolute all the particles
        //#pragma omp parallel for
        for(long i = 0; i < total_particles; i++) {
            _numerated_particles[i].evolute(total_forces[i], _dt);
        }
    }
};



#endif //MATERIALDOT_TEST_PHYSICSHANDLER_HPP
