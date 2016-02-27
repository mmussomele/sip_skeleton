/*
 * pointers_test.cpp
 * 
 *   Created On: June 12, 2015
 *       Author: Matthew Mussomele
 */

#include <cmath>
#include <iostream>
#include "gtest/gtest.h"
#include "pointers.h"

namespace {

    class pointers_test : public ::testing::Test {
    protected:
        pointers_test() { }
        virtual ~pointers_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };

    /* Checks if a given integer is prime. */
    int32_t is_prime(int32_t n) {
        if (n == 2) { 
            return 1; 
        } else if (n % 2 == 0) {
            return 0;
        } else {
            int32_t l_max_check = (int32_t) (sqrt(n) + 1);
            for (int32_t i = 3; i < l_max_check; i += 2) {
                if (!(n % i)) { return 0; }
            }
            return 1;
        }
    }

    /* Finds the length of the hailstone sequence starting at n */
    int32_t hailstone(int n) {
        int32_t count = 1;
        while (n != 1) {
            if (n % 2) {
                n = 3 * n + 1;
            } else {
                n /= 2;
            }
            count += 1;
        }
        return count;
    } 

    TEST_F(pointers_test, test_get_value_basic) {
        int32_t a = 10; 
        int32_t b = 20;
        int32_t c = -12;
        ASSERT_EQ(10, get_value(&a));
        ASSERT_EQ(20, get_value(&b));
        ASSERT_EQ(-12, get_value(&c));
    } 

    TEST_F(pointers_test, test_get_value_null) {
        int32_t * null = 0;
        ASSERT_EQ(0, get_value(null));
    }

    TEST_F(pointers_test, test_set_value_basic) {
        int32_t a = 10; 
        int32_t b = 20;
        set_value(&a, 20);
        ASSERT_EQ(a, b);
        set_value(&b, -20);
        ASSERT_EQ(a, -b);
    }

    TEST_F(pointers_test, test_set_value_extra) {
        int32_t a = 100;
        int32_t * b = &a;
        int32_t ** c = &b;
        set_value(*c, 10);
        ASSERT_EQ(10, a);
    }

    TEST_F(pointers_test, test_get_true_value) {
        int32_t a = 100;
        int32_t * b = &a;
        int32_t ** c = &b;
        ASSERT_EQ(100, get_true_value(c));
    }

    TEST_F(pointers_test, test_move_pointer) {
        int32_t a[] = {1, 2, 3, 4, 5};
        int32_t * b = &a[0];
        b = move_pointer(b, 3);
        ASSERT_EQ(4, *b);
        b = move_pointer(b, -2);
        ASSERT_EQ(2, *b);
        b = move_pointer(b, 3);
        ASSERT_EQ(5, *b);
    }

    TEST_F(pointers_test, test_move_pointer_null) {
        int32_t * null = 0;
        ASSERT_EQ(null, move_pointer(null, 1));
    }

    TEST_F(pointers_test, test_get_shifted_value) {
        int32_t a[] = {1, 2, 3, 4, 5};
        int32_t * b = &a[0];
        ASSERT_EQ(4, get_shifted_value(b, 3));
        b = move_pointer(b, 3);
        ASSERT_EQ(2, get_shifted_value(b, -2));
    }

    TEST_F(pointers_test, test_get_shifted_value_null) {
        int32_t * null = 0;
        ASSERT_EQ(0, get_shifted_value(null, 1));
    }

    TEST_F(pointers_test, test_apply) {
        ASSERT_EQ(0, apply(is_prime, 10));
        ASSERT_EQ(0, apply(is_prime, 15));
        ASSERT_EQ(1, apply(is_prime, 7));
        ASSERT_EQ(1, apply(is_prime, 71));
        ASSERT_EQ(7, apply(hailstone, 10));
        ASSERT_EQ(20, apply(hailstone, 9));
        ASSERT_EQ(13, apply(hailstone, 17));
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
