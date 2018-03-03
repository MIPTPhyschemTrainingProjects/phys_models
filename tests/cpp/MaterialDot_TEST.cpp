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

TEST(MaterialDot, createWith_vector) {
    std::vector<float> a = std::vector<float>();
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);
    MaterialDot dot(a);
    ASSERT_EQ(dot.getCoordinates(), a);
}

TEST(MaterialDot, createWith_array) {
    float p[3] = {-2, 100, -33};
    MaterialDot dot(p);
    std::vector<float> c(p, sizeof(p)/sizeof(p[0]) + p);
    ASSERT_EQ(dot.getCoordinates(), c);
}

TEST(MaterialDot, getVelocity_and_setVelocity) {
    float p[3] = {-5, 10, -20};
    MaterialDot dot(p);
    std::vector<float> c(p, sizeof(p) / sizeof(p[0]) + p);
    dot.setVelocity(c);
    ASSERT_EQ(dot.getVelocity(), c);
}