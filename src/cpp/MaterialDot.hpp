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
    std::array<double, 3> coordinates;
    /// Velocity
    std::array<double, 3> velocity;
    /// Mass
    double m = 1;
public:
    /**
     * MaterialDot object
     * @param x means X-coordinate
     * @param y means Y-coordinate
     * @param z means Z-coordinate
     * @param m means mass of a dot
     */
    explicit MaterialDot(double x=0, double y=0, double z=0, double m=1);

    /**
    * MaterialDot object
    * @param coords array of doubles with size 3
    * that will be considered as initial coordinates
    * @param m means mass of a dot
    */
    explicit MaterialDot(double* coords, double m=1);

    /**
     * Get material dot coordinates as an array
     * @return Array of doubles with copy of x, y, z coordinates respectively
     */
    std::array<double, 3> getCoordinates() const noexcept;

    /**
     * Get material dot velocity as an array
     * @return Array of doubles with copy of vx, vy, vz velocities respectively
     */
    std::array<double, 3> getVelocity() const noexcept;

    /**
     * Set material dot velocity from vector
     * @param v vector of doubles containing vx, vy, vz to set
     */
    void setVelocity(const std::array<double, 3> &v) noexcept;

    /**
     * Get material dot mass
     * @return Mass of the dot
     */
    double getMass() const noexcept;

    /**
     * Make the dot move in accordance with given <b>force</b> and <b>time</b>
     * @param force Total force that acts on the dot
     * @param t Time period of the force action
     */
    void evolute(const std::array<double, 3>& force, double t);

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
