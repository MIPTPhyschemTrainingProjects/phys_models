//
// Created by aleksei on 04.03.18.
//
#include <gtest/gtest.h>
#include "PhysicsHandler.hpp"
#include "MaterialDot.hpp"

TEST(PhysicsHandler, SimpleCreation) {
    // First argument -- total time, second -- dt for each iteration
    ASSERT_NO_THROW(PhysicsHandler<MaterialDot> h(20, 0.2));
    ASSERT_ANY_THROW(PhysicsHandler h1(20, 12));
}