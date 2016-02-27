/*
 * Calculator_test.cpp
 * 
 *   Created On: June 25, 2015
 *       Author: Matthew Mussomele
 */

#include "gtest/gtest.h"
#include "Calculator.h"

namespace {

    class Calculator_test : public ::testing::Test {
    protected:
        Calculator_test() { }
        virtual ~Calculator_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    public:
        Calculator calc;
    };

    TEST_F(Calculator_test, test_add) {
        ASSERT_DOUBLE_EQ(5, calc.add(2, 3));
        ASSERT_DOUBLE_EQ(10.756, calc.add(5.75, 5.006));
        ASSERT_DOUBLE_EQ(-1000, calc.add(400.5, -1400.5));
    }

    TEST_F(Calculator_test, test_mul) {
        ASSERT_DOUBLE_EQ(2.25, calc.mul(1.5, 1.5));
        ASSERT_DOUBLE_EQ(100, calc.mul(10, 10));
        ASSERT_DOUBLE_EQ(1010, calc.mul(101, 10));
    }

    TEST_F(Calculator_test, test_sub) {
        ASSERT_DOUBLE_EQ(0, calc.sub(5, 5));
        ASSERT_DOUBLE_EQ(10, calc.sub(20, 10));
        ASSERT_DOUBLE_EQ(10, calc.sub(10, 0));
        ASSERT_DOUBLE_EQ(-25.64, calc.sub(-30, -4.36));
    }

    TEST_F(Calculator_test, test_div) {
        ASSERT_DOUBLE_EQ(20, calc.div(100, 5));
        ASSERT_DOUBLE_EQ(5.5, calc.div(11, 2));
        ASSERT_DOUBLE_EQ(0, calc.div(1, 0));
        ASSERT_DOUBLE_EQ(-3, calc.div(27, -9));
    }

    TEST_F(Calculator_test, test_store_functions) {
        calc.store(10);
        ASSERT_DOUBLE_EQ(20, calc.add_stored(10));
        ASSERT_DOUBLE_EQ(31.43, calc.add_stored(21.43));
        ASSERT_DOUBLE_EQ(100, calc.mul_stored(10));
        ASSERT_DOUBLE_EQ(214.3, calc.mul_stored(21.43));
        ASSERT_DOUBLE_EQ(0, calc.sub_stored(10));
        ASSERT_DOUBLE_EQ(11.43, calc.sub_stored(21.43));
        ASSERT_DOUBLE_EQ(1, calc.div_stored(10));
        ASSERT_DOUBLE_EQ(.4, calc.div_stored(4));
    }

    TEST_F(Calculator_test, test_history_basic) {
        calc.store(10);
        calc.store(1.234);
        calc.add(10, 5);
        calc.mul(20.5, 4);
        calc.div(5, 2);
        calc.sub(9, 7.6);
        ASSERT_STREQ("9 - 7.6 = 1.4", calc.get_call(0).c_str());
        ASSERT_STREQ("5 / 2 = 2.5", calc.get_call(1).c_str());
        ASSERT_STREQ("20.5 * 4 = 82", calc.get_call(2).c_str());
        ASSERT_STREQ("10 + 5 = 15", calc.get_call(3).c_str());
        ASSERT_STREQ("Stored: 1.23", calc.get_call(4).c_str());
        ASSERT_STREQ("Stored: 10", calc.get_call(5).c_str());
        ASSERT_STREQ("Stored: 10", calc.get_call(5).c_str()); // check that history isn't modified by calls
    }

    TEST_F(Calculator_test, test_history_edge) {
        calc.store(10);
        ASSERT_STREQ("Stored: 10", calc.get_call(0).c_str());
        ASSERT_STREQ("No record", calc.get_call(1).c_str());
        calc.div(1, 0);
        ASSERT_STREQ("Stored: 10", calc.get_call(1).c_str());
        ASSERT_STREQ("Error: Divide by Zero", calc.get_call(0).c_str());
        calc.add_stored(10);
        calc.mul_stored(20.5);
        calc.div_stored(5);
        calc.sub_stored(9);
        ASSERT_STREQ("10 + 10 = 20", calc.get_call(3).c_str());
        ASSERT_STREQ("20.5 * 10 = 205", calc.get_call(2).c_str());
        ASSERT_STREQ("5 / 10 = 0.5", calc.get_call(1).c_str());
        ASSERT_STREQ("9 - 10 = -1", calc.get_call(0).c_str());
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
