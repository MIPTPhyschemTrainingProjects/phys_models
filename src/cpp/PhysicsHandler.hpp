//
// Created by aleksei on 03.03.18.
//

#ifndef MATERIALDOT_TEST_PHYSICSHANDLER_HPP
#define MATERIALDOT_TEST_PHYSICSHANDLER_HPP

#include <array>
#include <unordered_set>
#include <algorithm>
#include <list>


/**
 * Class for handling physical interaction between objects <i>Particle</i> (e.g. material dots).
 * Class of <i>Particle</i> should have <b>evolute()</b> method.
 *
 * Note: we assume that the interaction of the whole system can be split to two-particles action.
 */
template<typename Particle>
class PhysicsHandler {
private:
    std::list<Particle> _all_particles;
    float _dt;
    float _total_time;

public:
    /**
     * Method that counts the force created by interaction of the two particles
     * @param p1 First particle
     * @param p2 Second particle
     * @return Array of x, y, z components of force applied to the <u>first</u> particle
     */
    virtual std::array<float, 3> getForce(Particle p1, Particle p2) = 0;

    PhysicsHandler(float total_time, float dt): _total_time(total_time), _dt(dt)
    {}

    /**
     * Adds particle to the system, so that it will be considered in further evolution
     * @param p Particle to add for evoluting
     */
    void addParticle(const Particle &p) {
        _all_particles.insert(_all_particles.end(), p);
    }

    // TODO: Сделать проход в цикле: для всех элементов из _all_particles
    // TODO: подсчитать их силу взаимодействия с остальными, сохранить ее.
    // TODO: После этого, уже в другом цикле: для всех частиц вызвать evolute() с высчитанной силой
    // TODO: и временем, заданным при создании модели
    // Чит код для паралелльного подсчета вот такой:
    // #pragma omp parallel for
    void makeEvolution() {

    }
};



#endif //MATERIALDOT_TEST_PHYSICSHANDLER_HPP
