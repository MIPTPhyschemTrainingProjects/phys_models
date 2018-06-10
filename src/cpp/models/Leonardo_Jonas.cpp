//
// Created by aleksei on 12.03.18.
//
#include <iostream>
#include "PhysicsModel.hpp"
#include "MaterialDot.hpp"
#include <cmath>

template<typename Particle>
class LeonardoJonas: public PhysicsModel<Particle> {
private:

public:
	LeonardoJonas(double dt): PhysicsModel<Particle>(dt)
            {}

    Vector getForce(const Particle& p1, const Particle& p2) const {
        return ((p2.getCoordinates() - p1.getCoordinates()) * ((48 / pow((p1.getCoordinates() - p2.getCoordinates()).getNorm(), 15) - (24 / pow((p1.getCoordinates() - p2.getCoordinates()).getNorm(), 9)))));
    }
};

int main() {
    int i,j,k = 0;
    LeonardoJonas<MaterialDot> model(0.02);
	for (i = 1; i < 5; i++)
    {
		for (j = 1; j < 5; j++)
        {
			for (k = 1; k < 5; k++) 
			{
				MaterialDot md(i*j/2, j, i*k/2, 1);
				model.addParticle(md);
			}
        }
    }
	
    //model.makeEvolution(total_time);
    model.trackEvolution(20, true);
    model.exportStatistics();
}
