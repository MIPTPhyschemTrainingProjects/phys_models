//
// Created by aleksei on 12.03.18.
//
#include <iostream>
#include "PhysicsModel.hpp"
#include "MaterialDot.hpp"

template<typename Particle>
class SpringModel: public PhysicsModel<Particle> {
private:
    double _k = 0;

public:
    SpringModel(double k, double dt): PhysicsModel<Particle>(dt), _k(k)
            {}

    Vector getForce(const Particle& p1, const Particle& p2) const {
        return -_k*(p1.getCoordinates()-p2.getCoordinates());
    }
};

int main() {
    MaterialDot md1(1, 1, 1, 2);
    double r[3] = {-1, 2, 5};
    MaterialDot md2(r, 3);
    SpringModel<MaterialDot> model(0.2, 0.01);
    double total_time = 1.2;
    model.addParticle(md1);
    model.addParticle(md2);
    //model.makeEvolution(total_time);
    model.trackEvolution(100, true);
    std::cout << model.getParticle(0).getCoordinates().toArray().at(0) << std::endl;
}