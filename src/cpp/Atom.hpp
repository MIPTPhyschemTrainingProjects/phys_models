//
// Created by aleksei on 24.02.18.
//

#ifndef PHYS_MODELS_ATOM_HPP
#define PHYS_MODELS_ATOM_HPP

#include <vector>

/**
 * Class describing atom as a (!) material dot with mass
 */
class Atom {
private:
    /// Coordinates
    float _x, _y, _z;
    /// Velocity
    float _vx, _vy, _vz;
public:

    /**
     * Atom object (note that atom is a material dot with mass)
     * @param x means X-coordinate
     * @param y means Y-coordinate
     * @param z means Z-coordinate
     */
    Atom(float x=0, float y=0, float z=0);

    /**
     * Get atom coordinates as a vector
     * @return vector of floats with x, y, z coordinates respectively
     */
    virtual std::vector<float> getCoordinates();

};


#endif //PHYS_MODELS_ATOM_HPP
