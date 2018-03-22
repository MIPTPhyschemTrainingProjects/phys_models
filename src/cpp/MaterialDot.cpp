//
// Created by aleksei on 24.02.18.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(double x, double y, double z, double m):
        coordinates({x, y, z}), velocity({0, 0, 0}), m(m) {}

MaterialDot::MaterialDot(double *coords, double m):
        coordinates({coords[0], coords[1], coords[2]}), velocity({0, 0, 0}), m(m) {}

std::array<double, 3> MaterialDot::getCoordinates() const noexcept {
    return coordinates;
}

std::array<double, 3> MaterialDot::getVelocity() const noexcept {
    return velocity;
}

void MaterialDot::setVelocity(const std::array<double, 3> &v) noexcept {
    velocity = v;
}

double MaterialDot::getMass() const noexcept {
    return m;
}

void MaterialDot::evolute(const std::array<double, 3>& force, const double t) {
    for(char i=0; i < 3; i++) {
        coordinates[i] += 0.5*force[i]/m*t*t + velocity[i]*t;
        velocity[i] += force[i]/m*t;
    }
}

bool MaterialDot::operator==(const MaterialDot &other) const {
    return (m == other.getMass()
            && velocity == other.getVelocity()
            && coordinates == other.getCoordinates());
}

bool MaterialDot::operator!=(const MaterialDot &other) const {
    return !(*this == other);
}


// Redefinition of hash function
namespace std {

        std::size_t hash<MaterialDot>::operator() (const MaterialDot& dot) const
        {
            using std::size_t;
            using std::hash;

            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:

            return ((hash<double>()(dot.getCoordinates().back())
                     ^ (hash<double>()(dot.getVelocity().back()) << 1)) >> 1)
                   ^ (hash<double>()(dot.getMass()) << 1);
        }

        std::size_t hash<std::pair<MaterialDot, MaterialDot>>::operator()(
            const std::pair<MaterialDot, MaterialDot> &pair) const {
            return std::hash<MaterialDot>()(pair.first) ^ std::hash<MaterialDot>()(pair.second);
        }
}