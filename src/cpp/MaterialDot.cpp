//
// Created by aleksei on 24.02.18.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(float x, float y, float z, float m): coordinates({x, y, z}), m(m) {}

MaterialDot::MaterialDot(float *coords, float m): coordinates({coords[0], coords[1], coords[2]}), m(m) {}

std::array<float, 3> MaterialDot::getCoordinates() {
    return coordinates;
}

std::array<float, 3> MaterialDot::getVelocity() {
    return velocity;
}

void MaterialDot::setVelocity(std::array<float, 3> v) {
    velocity = v;
}

float MaterialDot::getMass() {
    return m;
}