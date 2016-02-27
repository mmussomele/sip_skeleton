/*
 * testing_test.cpp
 * 
 *   Created On: June 10, 2015
 *       Author: Matthew Mussomele
 */

#include "gtest/gtest.h"
#include "testing.h"

namespace {

    class testing_test : public ::testing::Test {
    protected:
        testing_test() { }
        virtual ~testing_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };

    /* YOUR TESTS HERE */

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
