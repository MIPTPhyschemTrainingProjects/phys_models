//
// Created by aleksei on 22.03.18.
//

#include <gtest/gtest.h>
#include "Vector.hpp"
#include <cmath>

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

TEST(Vector_to_other_types, toArray) {
    Vector v1 = {3, -1, 2};
    std::array<double, 3> arr = {3, -1, 2};
    ASSERT_EQ(v1.toArray(), arr);
}

TEST(Vector_arithmetics, sumVectors) {
    Vector v1 = {2, 5, 1};
    Vector v2 = {-12, 3, -52};
    Vector res = {-10, 8, -51};
    ASSERT_EQ(v1 + v2, res);
    ASSERT_EQ(v2 + v1, res);
}

TEST(Vector_arithmetics, subVectors) {
    Vector v1 = {2, 5, 1};
    Vector v2 = {-12, 3, -52};
    Vector res1 = {14, 2, 53};
    Vector res2 = {-14, -2, -53};
    ASSERT_EQ(v1 - v2, res1);
    ASSERT_EQ(v2 - v1, res2);
}

TEST(Vector_arithmetics, multVectors) {
    Vector v1 = {2, 5, 1};
    Vector v2 = {-12, 3, -52};
    double res = -61;
    ASSERT_EQ(v1*v2, res);
    ASSERT_EQ(v2*v1, res);
}

TEST(Vector_arithmetics, multVector_by_double) {
    Vector v1 = {2, 5, 1};
    double k = 2;
    Vector res = {4, 10, 2};
    ASSERT_EQ(v1*k, res);
}

TEST(Vector_arithmetics, mult_double_by_vector) {
    Vector v1 = {2, 5, 1};
    double k = -2;
    Vector res = {-4, -10, -2};
    ASSERT_EQ(k*v1, res);
}

TEST(Vector_arithmetics, vecMultVec) {
    Vector v1 = {2, 5, 1};
    Vector v2 = {1, 2, 3};
    Vector res = {15-2, 1-6, 4-5};
    ASSERT_EQ(v1^v2, res);
}

TEST(Vector_arithmetics, vecCoolOperators) {
    Vector v1 = {2, 5, 3};
    Vector v2 = {1, 2, 3};
    ASSERT_EQ(v1 *= 2, Vector(4, 10, 6));
    ASSERT_EQ(v1, Vector(4, 10, 6));
    ASSERT_EQ(v1 += v2, Vector(5, 12, 9));
    ASSERT_EQ(v1, Vector(5, 12, 9));
    ASSERT_EQ(v1 -= v2, Vector(4, 10, 6));
    ASSERT_EQ(v1, Vector(4, 10, 6));
}
