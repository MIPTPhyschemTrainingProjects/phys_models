//
// Created by aleksei on 22.03.18.
//

#include <array>
#include <cmath>
#include "Vector.hpp"

Vector::Vector(double x, double y, double z) noexcept: _x(x), _y(y), _z(z), _norm(sqrt(x*x+y*y+z*z))
{}

Vector::Vector(const std::array<double, 3> &vec) noexcept: _x(vec.at(0)), _y(vec.at(1)), _z(vec.at(2)),
                                                           _norm(sqrt(_x*_x+_y*_y+_z*_z))
{}

Vector::Vector(const double* coords) {
    _x = *coords;
    _y = *(coords+1);
    _z = *(coords+2);
    _norm = sqrt(_x*_x+_y*_y+_z*_z);
}

Vector::Vector(): _x(0), _y(0), _z(0), _norm(0)
{}

double Vector::getNorm() const noexcept { return _norm; }

double Vector::getX() const noexcept { return _x; }

double Vector::getY() const noexcept { return _y; }

double Vector::getZ() const noexcept { return _z; }

std::array<double, 3> Vector::toArray() const noexcept {
    std::array<double, 3> res = {_x, _y, _z};
    return res;
}
