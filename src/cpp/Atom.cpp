//
// Created by aleksei on 24.02.18.
//

#include "Atom.hpp"
Atom::Atom(float x, float y, float z) {
    _x = x;
    _y = y;
    _z = z;
}

std::vector<float> Atom::getCoordinates() {
    std::vector<float> res = std::vector<float>();
    res.push_back(_x);
    res.push_back(_y);
    res.push_back(_z);
    return res;
}
