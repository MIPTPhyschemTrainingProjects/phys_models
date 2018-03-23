//
// Created by aleksei on 24.02.18.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(double x, double y, double z, double _m): coordinates(Vector(x, y, z)),
                                                                   velocity(Vector()), m(_m)
{}

MaterialDot::MaterialDot(const double *coords, double _m): coordinates(Vector(coords)), m(_m)
{}

Vector MaterialDot::getCoordinates() const noexcept { return coordinates; }

Vector MaterialDot::getVelocity() const noexcept { return velocity; }

void MaterialDot::setVelocity(const Vector &v) noexcept { velocity = v; }

double MaterialDot::getMass() const noexcept { return m; }

void MaterialDot::evolute(const Vector& force, const double t) {
    coordinates += 0.5/m*t*t*force + velocity*t;
    velocity += t/m*force;
}

bool MaterialDot::operator==(const MaterialDot &other) const {
    return (m == other.getMass()
            && velocity == other.getVelocity()
            && coordinates == other.getCoordinates());
}

bool MaterialDot::operator!=(const MaterialDot &other) const {
    return !(*this == other);
}

MaterialDot::MaterialDot(const std::array<double, 3> &coords, double m): coordinates(Vector(coords)), m(m)
{}

MaterialDot::MaterialDot(const Vector &v, double m): coordinates(v), m(m)
{}


// Redefinition of hash function
namespace std {

        std::size_t hash<MaterialDot>::operator() (const MaterialDot& dot) const
        {
            using std::size_t;
            using std::hash;

            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:

            return ((hash<double>()(dot.getCoordinates().toArray().back())
                     ^ (hash<double>()(dot.getVelocity().toArray().back()) << 1)) >> 1)
                   ^ (hash<double>()(dot.getMass()) << 1);
        }

        std::size_t hash<std::pair<MaterialDot, MaterialDot>>::operator()(
            const std::pair<MaterialDot, MaterialDot> &pair) const {
            return std::hash<MaterialDot>()(pair.first) ^ std::hash<MaterialDot>()(pair.second);
        }
}