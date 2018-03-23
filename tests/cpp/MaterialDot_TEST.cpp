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
        ASSERT_EQ(a.getCoordinates().toArray().at(i), coords[i]);
    }
}

TEST(MaterialDot, createWith_array) {
    double p[3] = {-2, 100, -33};
    MaterialDot dot(p);
    std::array<double, 3> res = {-2, 100, -33};
    ASSERT_EQ(dot.getCoordinates().toArray(), res);
}

TEST(MaterialDot, createWith_std_array) {
    std::array<double, 3> a = {1, 2, 3};
    MaterialDot d1(a);
    Vector res = {1, 2, 3};
    ASSERT_EQ(d1.getCoordinates(), res);
    MaterialDot d2(res);
    ASSERT_EQ(d2.getCoordinates(), res);
}

TEST(MaterialDot, getVelocity_and_setVelocity) {
    double p[3] = {-5, 10, -20};
    MaterialDot dot(p);
    std::array<double, 3> v = {-11, 52, -22};
    dot.setVelocity(v);
    ASSERT_TRUE(dot.getVelocity().toArray() == v);
}

TEST(MaterialDot, getMass) {
    MaterialDot dot(5, 3, 2, 95);
    ASSERT_EQ(dot.getMass(), 95);
}

TEST(MaterialDot, evoluteFromZeroVelocity) {
    MaterialDot dot(5, 5, 5, 1);
    std::array<double, 3> force = {-1, -2, -3};
    dot.evolute(force, 2);
    std::array<double, 3> res_coords = {3, 1, -1};
    std::array<double, 3> res_vel = {-2, -4, -6};
    ASSERT_EQ(dot.getCoordinates().toArray(), res_coords);
    ASSERT_EQ(dot.getVelocity().toArray(), res_vel);

    MaterialDot dot1(-1, -2, -3, 5);
    std::array<double, 3> force1 = {5, 2, -4};
    double t = 5;
    std::array<double, 3> res_coords1 = {11.5, 3, -13};
    std::array<double, 3> res_velocity1 = {5, 2, -4};
    dot1.evolute(Vector(force1), t);
    ASSERT_EQ(dot1.getVelocity().toArray(), res_velocity1);
    ASSERT_EQ(dot1.getCoordinates().toArray(), res_coords1);
}

TEST(MaterialDot, checkEquality) {
    MaterialDot d1(2, 3, -5, 9.9);
    MaterialDot d2(-3, 5, 2, 2.9);
    MaterialDot d3(2, 3, -5, 9.9);

    ASSERT_EQ(d1, d3);
    ASSERT_NE(d1, d2);
}

TEST(MaterialDot, hashing) {
    MaterialDot d1(2, -5, 92, 12);
    ASSERT_NO_THROW(std::hash<MaterialDot>()(d1));
}