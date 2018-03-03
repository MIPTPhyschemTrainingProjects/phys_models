//
// Created by aleksei on 24.02.18.
//

#include <gtest/gtest.h>
#include "MaterialDot.hpp"

TEST(MaterialDot, createWith_3_Floats) {
    MaterialDot a(2, 5, 3);
}

TEST(MaterialDot, getCoordinates) {
    MaterialDot a(2, 3, -2);
    int coords[] = {2, 3, -2};
    for(int i = 0; i < 2; i++) {
        ASSERT_EQ(a.getCoordinates().at(i), coords[i]);
    }
}

TEST(MaterialDot, createWith_array) {
    float p[3] = {-2, 100, -33};
    MaterialDot dot(p);
    std::array<float, 3> res = {-2, 100, -33};
    ASSERT_EQ(dot.getCoordinates(), res);
}

TEST(MaterialDot, getVelocity_and_setVelocity) {
    float p[3] = {-5, 10, -20};
    MaterialDot dot(p);
    std::array<float, 3> v = {-11, 52, -22};
    dot.setVelocity(v);
    ASSERT_TRUE(dot.getVelocity() == v);
}

TEST(MaterialDot, getMass) {
    MaterialDot dot(5, 3, 2, 95);
    ASSERT_EQ(dot.getMass(), 95);
}