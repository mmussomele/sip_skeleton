/*
 * vector_test.cpp
 * 
 *   Created On: July 22, 2015
 *       Author: Matthew Mussomele
 */

#include <cstdint>
#include "gtest/gtest.h"
#include "int_vector.h"

/**
 * A suite of very basic tests to ensure that the leaner's vector 
 * implementation is reasonable.
 */

namespace {

    class vector_test : public ::testing::Test {
    protected:
        vector_test() { }
        virtual ~vector_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    public:
        int_vector v;
    };

    TEST_F(vector_test, test_add_and_size) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        ASSERT_EQ(5, v.size());
        v.add(100);
        ASSERT_EQ(6, v.size());
    }

    TEST_F(vector_test, test_vectors_start_empty) {
        ASSERT_EQ(0, v.size());
    }

    TEST_F(vector_test, test_get) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        for (int32_t i = 0; i < 5; i += 1) {
            ASSERT_EQ(i, v.get(i));
        }
    }

    TEST_F(vector_test, test_get_no_element) {
        ASSERT_EQ(0, v.get(1));
    }

    TEST_F(vector_test, test_insert) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        v.insert(2, 10);
        ASSERT_EQ(6, v.size());
        ASSERT_EQ(0, v.get(0));
        ASSERT_EQ(1, v.get(1));
        ASSERT_EQ(10, v.get(2));
        ASSERT_EQ(2, v.get(3));
        ASSERT_EQ(3, v.get(4));
        ASSERT_EQ(4, v.get(5));
    }

    TEST_F(vector_test, test_set) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        v.set(2, 10);
        ASSERT_EQ(5, v.size());
        ASSERT_EQ(0, v.get(0));
        ASSERT_EQ(1, v.get(1));
        ASSERT_EQ(10, v.get(2));
        ASSERT_EQ(3, v.get(3));
        ASSERT_EQ(4, v.get(4));
    }

    TEST_F(vector_test, test_remove) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        v.remove(0);
        ASSERT_EQ(4, v.size());
        for (int32_t i = 0; i < 4; i += 1) {
            v.add(i + 1);
        }
        ASSERT_EQ(1, v.remove(0));
    }

    TEST_F(vector_test, test_clear) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        v.clear();
        ASSERT_EQ(0, v.size());
        for (int32_t i = 0; i < 5; i += 1) {
            ASSERT_EQ(0, v.get(i));
        }
    }
    TEST_F(vector_test, test_contains) {
        for (int32_t i = 0; i < 5; i += 1) {
            v.add(i);
        }
        for (int32_t i = 0; i < 5; i += 1) {
            ASSERT_TRUE(v.contains(i));
            ASSERT_FALSE(v.contains(i + 10));
        }
        v.add(10);
        ASSERT_FALSE(v.contains(5));
    }

    TEST_F(vector_test, test_resizing) {
        for (int32_t i = 0; i < 10000; i += 1) {
            v.add(i);
        }
        ASSERT_EQ(10000, v.size());
        for (int32_t i = 0; i < 10000; i += 1) {
            ASSERT_EQ(i, v.get(i));
        }
    }
    
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
