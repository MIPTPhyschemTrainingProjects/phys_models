//
// Created by aleksei on 24.02.18.
//

#ifndef PHYS_MODELS_MATERIAL_DOT_HPP
#define PHYS_MODELS_MATERIAL_DOT_HPP

#include <vector>

/**
 * Class describing material dot with mass
 */
class MaterialDot {
private:
    /// Coordinates
    float _x, _y, _z;
    /// Velocity
    float _vx, _vy, _vz;
public:

    /**
     * MaterialDot object
     * @param x means X-coordinate
     * @param y means Y-coordinate
     * @param z means Z-coordinate
     */
    MaterialDot(float x=0, float y=0, float z=0);

    /**
     * MaterialDot object
     * @param coords vector of floats with size 3
     * that will be considered as initial coordinates
     */
    MaterialDot(std::vector<float> coords);

    /**
    * MaterialDot object
    * @param coords array of floats with size 3
    * that will be considered as initial coordinates
    */
    MaterialDot(float* coords);

    /**
     * Get material dot coordinates as a vector
     * @return vector of floats with x, y, z coordinates respectively
     */
    virtual std::vector<float> getCoordinates();

    /**
     * Get material dot velocity as a vector
     * @return vector of floats with vx, vy, vz velocities respectively
     */
    virtual std::vector<float> getVelocity();

    /**
     * Set material dot velocity from vector
     * @param v vector of floats containing vx, vy, vz to set
     */
    virtual void setVelocity(std::vector<float> v);

};


#endif //PHYS_MODELS_MATERIAL_DOT_HPP
