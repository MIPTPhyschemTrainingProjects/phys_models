//
// Created by aleksei on 24.02.18.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(float x, float y, float z, float m):
        coordinates({x, y, z}), velocity({0, 0, 0}), m(m) {}

MaterialDot::MaterialDot(float *coords, float m):
        coordinates({coords[0], coords[1], coords[2]}), velocity({0, 0, 0}), m(m) {}

std::array<float, 3> MaterialDot::getCoordinates() const {
    return coordinates;
}

std::array<float, 3> MaterialDot::getVelocity() const {
    return velocity;
}

void MaterialDot::setVelocity(std::array<float, 3> v) {
    velocity = v;
}

float MaterialDot::getMass() const {
    return m;
}

void MaterialDot::evolute(const std::array<float, 3>& force, const float t) {
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

            return ((hash<float>()(dot.getCoordinates().back())
                     ^ (hash<float>()(dot.getVelocity().back()) << 1)) >> 1)
                   ^ (hash<float>()(dot.getMass()) << 1);
        }
}