/*
 * functions_test.cpp
 * 
 *   Created On: June 10, 2015
 *       Author: Matthew Mussomele
 */

#include "gtest/gtest.h"
#include "functions.h"

namespace {

    class function_test : public ::testing::Test {
    protected:
        function_test() { }
        virtual ~function_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };

    /**
     * @brief gets a stringstream object containing output to stdout
     * @return a stringstream object that acts as stdout (print statements will go there)
     */
    std::stringstream get_cout_redirect() {
        std::stringstream buffer;
        std::cout.rdbuf(buffer.rdbuf());
        return buffer;
    }
    
    TEST_F(function_test, test_print_joined_basic) {
        std::stringstream buffer = get_cout_redirect();
        print_joined(1, 23);
        ASSERT_STREQ("123\n", buffer.str().c_str());
    }

    TEST_F(function_test, test_print_joined_neg_basic) {
        std::stringstream buffer = get_cout_redirect();
        print_joined(-1, 23);
        ASSERT_STREQ("-123\n", buffer.str().c_str());
    }

    TEST_F(function_test, test_print_joined_no_middle_neg) {
        std::stringstream buffer = get_cout_redirect();
        print_joined(314, -413);
        ASSERT_STREQ("314413\n", buffer.str().c_str());
    }

    TEST_F(function_test, test_print_joined_no_overflow) {
        std::stringstream buffer = get_cout_redirect();
        print_joined(12438234, 321948230);
        ASSERT_STREQ("12438234321948230\n", buffer.str().c_str());
    }

    TEST_F(function_test, test_absolute_sum_basic) {
        ASSERT_EQ(10, absolute_sum(5, 5));
        ASSERT_EQ(10, absolute_sum(-5, -5));
    }

    TEST_F(function_test, test_absolute_sum_correct_abs) {
        ASSERT_EQ(10, absolute_sum(-5, 15));
        ASSERT_EQ(10, absolute_sum(5, -15));
        ASSERT_EQ(0, absolute_sum(1500000000, -1500000000));
    } 

    TEST_F(function_test, test_largest_product_irrelevant_order) {
        ASSERT_EQ(12, largest_product(2, 3, 4));
        ASSERT_EQ(12, largest_product(3, 2, 4));
        ASSERT_EQ(12, largest_product(4, 3, 2));
    }

    TEST_F(function_test, test_largest_product_duplicates) {
        ASSERT_EQ(8, largest_product(2, 2, 4));
        ASSERT_EQ(12, largest_product(3, 3, 4));
        ASSERT_EQ(16, largest_product(4, 4, 4));
    }

    TEST_F(function_test, test_largest_prime_under_valid) {
        ASSERT_EQ(17, largest_prime_under(17));
        ASSERT_EQ(17, largest_prime_under(18));
        ASSERT_EQ(2, largest_prime_under(2));
        ASSERT_EQ(3, largest_prime_under(3));
        ASSERT_EQ(97, largest_prime_under(100));
        ASSERT_EQ(79, largest_prime_under(81));
        ASSERT_EQ(31, largest_prime_under(32));
    }

    TEST_F(function_test, test_largest_prime_under_noprime) {
        ASSERT_EQ(1, largest_prime_under(1));
        ASSERT_EQ(0, largest_prime_under(0));
        ASSERT_EQ(-2000, largest_prime_under(-2000));
    }

    TEST_F(function_test, test_fact_or_fib_fact) {
        ASSERT_EQ(6, fact_or_fib(3));
        ASSERT_EQ(5040, fact_or_fib(7));
        ASSERT_EQ(39916800, fact_or_fib(11));
        ASSERT_EQ(1, fact_or_fib(-3));
    }

    TEST_F(function_test, test_fact_or_fib_fib) {
        ASSERT_EQ(0, fact_or_fib(0));
        ASSERT_EQ(1, fact_or_fib(2));
        ASSERT_EQ(8, fact_or_fib(6));
        ASSERT_EQ(46368, fact_or_fib(24));
        ASSERT_EQ(832040, fact_or_fib(30));
        ASSERT_EQ(102334155, fact_or_fib(40));
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
