/*
 * recursion_test.h
 *
 *  Created on: July 9, 2015
 *      Author: Matthew Mussomele
 */

#include "gtest/gtest.h"
#include "recursion.h"

namespace {

    class recursion_test : public ::testing::Test {
    protected:
        recursion_test() { }
        virtual ~recursion_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };

    TEST_F(recursion_test, test_mul_simple) {
        ASSERT_EQ(10, mul(2, 5));
        ASSERT_EQ(10, mul(5, 2));
        ASSERT_EQ(81, mul(9, 9));
        ASSERT_EQ(143, mul(13, 11));
    }

    TEST_F(recursion_test, test_mul_negs) {
        ASSERT_EQ(-75, mul(-15, 5));
        ASSERT_EQ(-75, mul(5, -15));
        ASSERT_EQ(100, mul(-10, -10));
    }

    TEST_F(recursion_test, test_sum_array) {
        int32_t test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ASSERT_EQ(55, sum_array(test_array, 10, 0));
        ASSERT_EQ(40, sum_array(test_array, 10, 5));
        ASSERT_EQ(0, sum_array(test_array, 10, 10));
        test_array[4] = 4;
        ASSERT_EQ(54, sum_array(test_array, 10, 0));
    }

    TEST_F(recursion_test, test_reverse_string_whole) {
        char word[23];
        strcpy(word, "Hello, my name is Alice");
        reverse_string(word, 0, 22);
        ASSERT_STREQ("ecilA si eman ym ,olleH", word);
    }

    TEST_F(recursion_test, test_reverse_string_middle) {
        char word[23];
        strcpy(word, "Hello, my name is Alice");
        reverse_string(word, 0, 22);
        reverse_string(word, 9, 12);
        ASSERT_STREQ("ecilA si name ym ,olleH", word);
        reverse_string(word, 0, 4);
        ASSERT_STREQ("Alice si name ym ,olleH", word);
        reverse_string(word, 17, 19);
        ASSERT_STREQ("Alice si name ym lo,leH", word);
        reverse_string(word, 18, 20);
        ASSERT_STREQ("Alice si name ym ll,oeH", word);
    }

    TEST_F(recursion_test, test_is_palindrome_whole) {
        ASSERT_TRUE(is_palindrome("sees", 0, 3));
        ASSERT_TRUE(is_palindrome("racecar", 0, 6));
        ASSERT_TRUE(is_palindrome("anna", 0, 3));
        ASSERT_TRUE(is_palindrome("tattarrattat", 0, 11));
        ASSERT_TRUE(is_palindrome("iuaef812218feaui", 0, 15));
        ASSERT_FALSE(is_palindrome("Hello", 0, 4));
        ASSERT_FALSE(is_palindrome("You made this? I made this.", 0, 26));
        ASSERT_FALSE(is_palindrome("asdfgefdsa", 0, 9));
    }

    TEST_F(recursion_test, test_is_palindrome_middle) {
        ASSERT_TRUE(is_palindrome("askdjftootkjsad", 6, 9));
        ASSERT_TRUE(is_palindrome("Hello, I'm bob", 11, 13));
        ASSERT_TRUE(is_palindrome("Hello, I'm bob", 2, 3));
        ASSERT_TRUE(is_palindrome("Hello, I'm bob", 1, 1));
        ASSERT_TRUE(is_palindrome("Hello, I'm bob", 6, 6));
        ASSERT_FALSE(is_palindrome("racecar", 0, 3));
        ASSERT_FALSE(is_palindrome("gerririrreg", 5, 8));
    }

    TEST_F(recursion_test, test_ways_to_make_change) {
        ASSERT_EQ(2, ways_to_make_change(7));
        ASSERT_EQ(4, ways_to_make_change(10));
        ASSERT_EQ(9, ways_to_make_change(20));
        ASSERT_EQ(77, ways_to_make_change(63));
        ASSERT_EQ(293, ways_to_make_change(100));
        ASSERT_EQ(571, ways_to_make_change(128));
        ASSERT_EQ(3248, ways_to_make_change(211));
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
