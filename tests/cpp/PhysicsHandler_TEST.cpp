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
    std::array<float, 3> res_force = {3*0.4, 6*0.4, 8*0.4};
    ASSERT_EQ(ph1.getForce(d1, d2), res_force);
}

/*
TEST(PhysicsHandler, ParticleMovement) {
    MaterialDot d1(2, 4, 5, 2);
    MaterialDot d2(-1, -2, -3, 5);
    PhysicsHandler<MaterialDot> ph1(10, 0.1);
    ph1.addParticle(d1);
    ph1.addParticle(d2);
    ph1.makeEvolution();
}
 */