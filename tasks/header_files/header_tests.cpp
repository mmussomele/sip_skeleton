/*
 * header_tests.cpp
 * 
 *   Created On: July 6, 2015
 *       Author: Matthew Mussomele
 */

#include "gtest/gtest.h"
#include "q1.h"
#include "q2.h"
#include "q3.h"

namespace {

    class header_tests : public ::testing::Test {
    protected:
        header_tests() { }
        virtual ~header_tests() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };

    TEST_F(header_tests, test_q1) {
        ASSERT_DOUBLE_EQ(3, quadratic(1, 1, 1, 1));
        ASSERT_DOUBLE_EQ(6, quadratic(1, 2, 3, 1));
        ASSERT_DOUBLE_EQ(7, quadratic(1, 1, 1, 2));
        ASSERT_DOUBLE_EQ(63, quadratic(5, 5, 3, 3));
    }

    TEST_F(header_tests, test_q2) {
        ASSERT_DOUBLE_EQ(5, absolute_difference(10, 5));
        ASSERT_DOUBLE_EQ(5, absolute_difference(5, 10));
        ASSERT_DOUBLE_EQ(100, absolute_difference(-100, -200));
        ASSERT_DOUBLE_EQ(5.2, absolute_difference(10.5, 5.3));
    }

    TEST_F(header_tests, test_q3) {
        ASSERT_EQ(0, closest_x_value(1, 0, 0, 0, -5, 5));
        ASSERT_EQ(0, closest_x_value(1, 0, 0, 0, -10, 10));
        ASSERT_EQ(1, closest_x_value(1, 0, 0, 0, 1, 5));
        ASSERT_EQ(-1, closest_x_value(1, 1, 0, 0, -5, -1));
        ASSERT_EQ(2, closest_x_value(1, 0, 1, 5, 0, 10));
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
