//
// Created by aleksei on 24.02.18.
//

#ifndef PHYS_MODELS_MATERIAL_DOT_HPP
#define PHYS_MODELS_MATERIAL_DOT_HPP

#include <vector>
#include <array>

/**
 * Class describing material dot with mass
 */
class MaterialDot {
private:
    /// Coordinates
    std::array<float, 3> coordinates;
    /// Velocity
    std::array<float, 3> velocity;
public:

    /**
     * MaterialDot object
     * @param x means X-coordinate
     * @param y means Y-coordinate
     * @param z means Z-coordinate
     */
    explicit MaterialDot(float x=0, float y=0, float z=0);

    /**
    * MaterialDot object
    * @param coords array of floats with size 3
    * that will be considered as initial coordinates
    */
    explicit MaterialDot(float* coords);

    /**
     * Get material dot coordinates as an array
     * @return Array of floats with copy of x, y, z coordinates respectively
     */
    virtual std::array<float, 3> getCoordinates();

    /**
     * Get material dot velocity as an array
     * @return Array of floats with copy of vx, vy, vz velocities respectively
     */
    virtual std::array<float, 3> getVelocity();

    /**
     * Set material dot velocity from vector
     * @param v vector of floats containing vx, vy, vz to set
     */
    virtual void setVelocity(std::array<float, 3> v);

};


#endif //PHYS_MODELS_MATERIAL_DOT_HPP
