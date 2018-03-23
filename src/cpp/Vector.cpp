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

Vector::Vector(const double* coords): _x(*coords++), _y(*coords++), _z(*coords), _norm(sqrt(_x*_x+_y*_y+_z*_z))
{}

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

Vector Vector::operator+(const Vector &other) const noexcept {
    return {_x + other._x, _y + other._y, _z + other._z};
}

Vector Vector::operator-(const Vector &other) const noexcept {
    return {_x - other._x, _y - other._y, _z - other._z};
}

double Vector::operator*(const Vector &other) const noexcept {
    return _x*other._x + _y*other._y + _z*other._z;
}

Vector Vector::operator^(const Vector &other) const noexcept {
    return {_y*other._z - _z*other._y, _z*other._x - _x*other._z, _x*other._y - _y*other._x};
}

Vector Vector::operator*(double k) const noexcept {
    return {_x*k, _y*k, _z*k};
}

Vector operator*(double k, const Vector &v) noexcept {
    return {v.getX()*k, v.getY()*k, v.getZ()*k};
}

bool Vector::operator==(const Vector &other) const noexcept {
    return (_x == other._x)&(_y == other._y)&(_z == other._z);
}

bool Vector::operator!=(const Vector &other) const noexcept {
    return !((*this) == other);
}

Vector Vector::operator+=(const Vector &other) noexcept {
    (*this) = (*this) + other;
    return *this;
}

Vector Vector::operator-=(const Vector &other) noexcept {
    *this = (*this) - other;
    return *this;
}

Vector Vector::operator*=(double k) noexcept {
    *this = (*this)*k;
    return *this;
}
