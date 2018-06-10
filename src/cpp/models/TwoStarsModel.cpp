//
// Created by aleksei on 30.03.18.
//

#include <iostream>
#include "PhysicsModel.hpp"
#include "MaterialDot.hpp"
#include <cmath>

template<typename Particle>
class TwoStarsModel: public PhysicsModel<Particle> {
private:
    double G = 6.67*pow(10, -11);

public:
    TwoStarsModel(double dt): PhysicsModel<Particle>(dt)
    {}

    Vector getForce(const Particle& p1, const Particle& p2) const {
        return -G*p1.getMass()*p2.getMass()/pow((p1.getCoordinates()-p2.getCoordinates()).getNorm(), 3)*(p1.getCoordinates() - p2.getCoordinates());
    }
};

int main() {
    MaterialDot md1(0, 0, 0, 2*pow(10, 30));
    double r[3] = {-1000000, 20000000, 0};
    MaterialDot md2(r, 3*pow(10, 10));
    md2.setVelocity({1000000, 1000000, 0});
    TwoStarsModel<MaterialDot> model(0.0001);
    double total_time = 100;
    model.addParticle(md1);
    model.addParticle(md2);
    //model.makeEvolution(total_time);
    model.trackEvolution(total_time, true);
    model.exportStatistics();
}
