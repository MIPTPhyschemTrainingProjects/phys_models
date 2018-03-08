//
// Created by aleksei on 04.03.18.
//
#include <gtest/gtest.h>
#include "PhysicsHandler.hpp"
#include "MaterialDot.hpp"

TEST(PhysicsHandler, SimpleCreation) {
    // First argument -- total time, second -- dt for each iteration
    ASSERT_NO_THROW(PhysicsHandler<MaterialDot> h(20, 0.2));
    ASSERT_NO_THROW(PhysicsHandler<MaterialDot> h(123, 0.12412));
}

TEST(PhysicsHandler, AddParticle) {
    MaterialDot d1(2, -12, 2, 2);
    MaterialDot d2(-12, 1512, -0.235, 124.214214);
    PhysicsHandler<MaterialDot> h1(100, 2);
    ASSERT_NO_THROW(h1.addParticle(d1));
    ASSERT_NO_THROW(h1.addParticle(d2));
}

TEST(PhysicsHandler, ParticleInteraction) {
    MaterialDot d1(2, 4, 5, 2);
    MaterialDot d2(-1, -2, -3, 5);
    PhysicsHandler<MaterialDot> ph1(100, 0.1);
    std::array<float, 3> res_force = {-3*0.4, -6*0.4, -8*0.4};
    ASSERT_EQ(ph1.getForce(d1, d2), res_force);
}

TEST(PhysicsHandler, getParticlesCount) {
    PhysicsHandler<MaterialDot> ph1(100, 0.1);
    MaterialDot m1(-2, 5, 3, 3);
    MaterialDot m2(-3, 2, 51, 2);
    MaterialDot m3(-5, 23, 124, 1512);
    ph1.addParticle(m1);
    ASSERT_EQ(ph1.getCount(), 1);
    ph1.addParticle(m2);
    ASSERT_EQ(ph1.getCount(), 2);
    ph1.addParticle(m3);
    ASSERT_EQ(ph1.getCount(), 3);
}

TEST(PhysicsHandler, getParticle) {
    PhysicsHandler<MaterialDot> ph1(100, 0.1);
    MaterialDot m1(-2, 5, 3, 3);
    MaterialDot m2(-3, 2, 51, 2);
    MaterialDot m3(-5, 23, 124, 1512);
    ph1.addParticle(m1);
    ph1.addParticle(m2);
    ph1.addParticle(m3);
    ASSERT_EQ(ph1.getParticle(0), m1);
    ASSERT_EQ(ph1.getParticle(1), m2);
    ASSERT_EQ(ph1.getParticle(2), m3);
}

TEST(PhysicsHandler, ParticleMovement) {
    MaterialDot d1(2, 4, 5, 2);
    MaterialDot d2(-1, -2, -3, 5);
    PhysicsHandler<MaterialDot> ph1(10, 0.1);
    ph1.addParticle(d1);
    ph1.addParticle(d2);
    ASSERT_NO_THROW(ph1.makeEvolution());
    std::array<float, 3> res_coords1 = {1.997, 3.994, 4.992};
    std::array<float, 3> res_coords2 = {-0.9988, -1.9976, -2.9968};
    std::array<float, 3> res_vel1 = {-0.06, -0.12, -0.16};
    std::array<float, 3> res_vel2 = {0.024, 0.048, 0.064};
    ASSERT_EQ(ph1.getParticle(0).getCoordinates(), res_coords1);
    ASSERT_EQ(ph1.getParticle(1).getCoordinates(), res_coords2);
}