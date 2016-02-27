/*
 * sorting_test.cpp
 * 
 *   Created On: June 17, 2015
 *       Author: Matthew Mussomele
 */

#include <cstdint>
#include "gtest/gtest.h"
#include "sorting.h"

namespace {

    class sorting_test : public ::testing::Test {
    protected:
        sorting_test() { }
        virtual ~sorting_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };
    
    /**
     * @brief checks if an array of integers is sorted
     * 
     * @param array the array to check
     * @param size the number of elements in the array
     * 
     * @return true if the array is sorted
     */
    bool is_sorted(int32_t array[], int32_t size) {
        for (int32_t i = 1; i < size; i += 1) {
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
        return true;
    } 

    bool sort_is_working(void (*sort)(int32_t[], int32_t)) {
        for (int32_t i = 1; i <= 10; i += 1) {
            int32_t * test_array = get_random_array_of_size(i * 10);
            (*sort)(test_array, i * 10);
            if (!is_sorted(test_array, i * 10)) {
                return false;
            }
        }
        return true;
    }

    TEST_F(sorting_test, test_swap) {
        int32_t a = 1, b = 2, c = 3;
        int32_t d[] = {a, b, c};
        swap(d, 1, 2);
        swap(d, 2, 0);
        ASSERT_EQ(a, d[2]);
        ASSERT_EQ(b, d[0]);
        ASSERT_EQ(c, d[1]);
    }

    TEST_F(sorting_test, test_bubble) {
        ASSERT_TRUE(sort_is_working(bubble_sort));
    }

    TEST_F(sorting_test, test_selection) {
        ASSERT_TRUE(sort_is_working(selection_sort));
    }

    TEST_F(sorting_test, test_insertion) {
        ASSERT_TRUE(sort_is_working(insertion_sort));
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
