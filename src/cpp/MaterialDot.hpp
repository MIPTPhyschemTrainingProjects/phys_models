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
    /// Mass
    float m = 1;
public:
    /**
     * MaterialDot object
     * @param x means X-coordinate
     * @param y means Y-coordinate
     * @param z means Z-coordinate
     * @param m means mass of a dot
     */
    explicit MaterialDot(float x=0, float y=0, float z=0, float m=1);

    /**
    * MaterialDot object
    * @param coords array of floats with size 3
    * that will be considered as initial coordinates
    * @param m means mass of a dot
    */
    explicit MaterialDot(float* coords, float m=1);

    /**
     * Get material dot coordinates as an array
     * @return Array of floats with copy of x, y, z coordinates respectively
     */
    std::array<float, 3> getCoordinates() const;

    /**
     * Get material dot velocity as an array
     * @return Array of floats with copy of vx, vy, vz velocities respectively
     */
    std::array<float, 3> getVelocity() const;

    /**
     * Set material dot velocity from vector
     * @param v vector of floats containing vx, vy, vz to set
     */
    void setVelocity(std::array<float, 3> v);

    /**
     * Get material dot mass
     * @return Mass of the dot
     */
    float getMass() const;

    /**
     * Make the dot move in accordance with given <b>force</b> and <b>time</b>
     * @param force Total force that acts on the dot
     * @param t Time period of the force action
     */
    void evolute(const std::array<float, 3>& force, const float t);

    bool operator==(const MaterialDot& other) const;

    bool operator!=(const MaterialDot& other) const;

};

// Let's redefine hash function for MaterialDot object (for unordered set)
namespace std {

    template <>
    struct hash<MaterialDot>
    {
        std::size_t operator() (const MaterialDot& dot) const;
    };

    template <>
    struct hash<std::pair<MaterialDot, MaterialDot>> {
        std::size_t operator() (const std::pair<MaterialDot, MaterialDot>& pair) const;
    };

}

#endif //PHYS_MODELS_MATERIAL_DOT_HPP
