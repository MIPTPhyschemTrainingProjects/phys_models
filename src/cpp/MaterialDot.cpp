//
// Created by aleksei on 24.02.18.
//

#include "MaterialDot.hpp"
#include <stdexcept>

MaterialDot::MaterialDot(float x, float y, float z): _x(x), _y(y), _z(z)
{}

MaterialDot::MaterialDot(std::vector<float> coords): _x(coords.at(0)), _y(coords.at(1)), _z(coords.at(2))
{}

MaterialDot::MaterialDot(float *coords): _x(coords[0]), _y(coords[1]), _z(coords[2])
{}

std::vector<float> MaterialDot::getCoordinates() {
    std::vector<float> res = std::vector<float>();
    res.push_back(_x);
    res.push_back(_y);
    res.push_back(_z);
    return res;
}
