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