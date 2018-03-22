//
// Created by aleksei on 24.02.18.
//

#ifndef PHYS_MODELS_MATERIAL_DOT_HPP
#define PHYS_MODELS_MATERIAL_DOT_HPP

#include <vector>
#include <array>
#include "Vector.hpp"

/**
 * Class describing material dot with mass
 */
class MaterialDot {
private:
    /// Coordinates
    Vector coordinates;
    /// Velocity
    Vector velocity;
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
    explicit MaterialDot(const double* coords, double m=1);

    /**
     * Get material dot coordinates as a <b>Vector</b>
     * @return Vector of coordinates
     */
    Vector getCoordinates() const noexcept;

    /**
     * Get material dot velocity as a <b>Vector</b>
     * @return Vector with velocitities
     */
    Vector getVelocity() const noexcept;

    /**
     * Set material dot velocity from vector
     * @param v <b>Vector</b> containing vx, vy, vz to set
     */
    void setVelocity(const Vector &v) noexcept;

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
    void evolute(const Vector &force, double t);

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
