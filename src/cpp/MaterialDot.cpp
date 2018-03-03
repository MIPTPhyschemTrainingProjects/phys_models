//
// Created by aleksei on 24.02.18.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(float x, float y, float z): coordinates({x, y, z})
{}

MaterialDot::MaterialDot(float *coords): coordinates({coords[0], coords[1], coords[2]})
{}

std::array<float, 3> MaterialDot::getCoordinates() {
    return coordinates;
}

std::array<float, 3> MaterialDot::getVelocity() {
    return velocity;
};

void MaterialDot::setVelocity(std::array<float, 3> v) {
    velocity = v;
}