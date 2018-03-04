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
    //virtual std::array<float, 3> getForce(const Particle &p1, const Particle &p2) const = 0;

    // TODO: Это -- реализация только для тестирования.
    // TODO: Этот getForce считает силу так, будто частицы соединены пружиной жесткости 0.4
    virtual std::array<float, 3> getForce(const Particle &p1, const Particle &p2) const {
        std::array<float, 3> res = {0, 0, 0};
        std::transform(p1.getCoordinates().begin(), p1.getCoordinates().end(),
                       p2.getCoordinates().begin(), res.begin(), std::minus<float>());
        std::transform(res.begin(), res.end(), res.begin(), std::bind1st(std::multiplies<float>(), 0.4));
        return res;
    }

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
    // TODO: Проверить прагму выше. Кажется, она не работает
    // TODO: НЕ РАБОТАЕТ! НУЖНА РАБОТА!
    /*
    void makeEvolution() {
        std::vector<std::array<float, 3>> total_forces;

        for(auto& it1 = _all_particles.begin(); it1 != _all_particles.end(); ++it1) {
            #pragma omp parallel for
            std::array<float, 3> total_force = {0, 0, 0};
            for(auto& it2 = it1++; it2 != _all_particles.end(); ++it2) {
                std::array<float, 3> tmp_force = getForce(*it1, *it2);
                // Complicated std::array sum. I like C++
                std::transform(total_force.begin(), total_force.end(),
                               tmp_force.begin(), total_force.begin(), std::plus<float>());
            }
            total_forces.push_back(total_force);
        }
        // Now, let's evolute all the particles
        #pragma omp parallel for
        for(auto& it = _all_particles.end(); it != _all_particles.begin(); ++it) {
            (*it).evolute(total_forces.back(), _dt);
            total_forces.pop_back();
        }
    }
     */
};



#endif //MATERIALDOT_TEST_PHYSICSHANDLER_HPP
