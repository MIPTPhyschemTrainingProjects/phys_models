//
// Created by aleksei on 24.02.18.
//

#include <gtest/gtest.h>
#include "Atom.hpp"

TEST(Atom, createWith_3_Floats) {
    Atom a(2, 5, 3);
}

TEST(Atom, getCoordinates) {
    Atom a(2, 3, -2);
    int coords[] = {2, 3, -2};
    for(int i = 0; i < 2; i++) {
        ASSERT_EQ(a.getCoordinates().at(i), coords[i]);
    }
}