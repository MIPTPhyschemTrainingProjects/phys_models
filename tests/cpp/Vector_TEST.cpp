//
// Created by aleksei on 22.03.18.
//

#include <gtest/gtest.h>
#include "Vector.hpp"

TEST(Vector_basics, SimpleCreation) {
    ASSERT_NO_THROW(Vector());
}

TEST(Vector_basics, CreateWithDifferentConstructors) {
    double b[3] = {1, 2, 3};
    Vector v1 = b;
    Vector v2 = {2, 3, 4};
    ASSERT_EQ(v1.getX(), 1);
    ASSERT_EQ(v1.getY(), 2);
    ASSERT_EQ(v1.getZ(), 3);
    ASSERT_EQ(v2.getX(), 2);
    ASSERT_EQ(v2.getY(), 3);
    ASSERT_EQ(v2.getZ(), 4);
}

TEST(Vector_basics, CalculatingNorma) {
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 89; j++) {
            for(int k = 1; k < 24; k++) {
                Vector v = {i, j, k};
                ASSERT_EQ(v.getNorm(), sqrt(i*i+j*j+k*k));
                double b[3] = {(double) i, (double) j, (double) k};
                Vector v1 = b;
                ASSERT_EQ(v1.getNorm(), sqrt(i*i+j*j+k*k));
            }
        }
    }
}