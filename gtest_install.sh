#!/bin/bash

# Use this install script at your own risk. I cannot guarentee it will work with your OS,
# so skim it and make sure that you are ok with it before running it

echo Installing Google Test...
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip gtest-1.7.0.zip
rm gtest-1.7.0.zip
cd gtest-1.7.0
echo Configuring Google Test...
./configure
make
echo Copying binaries to include...
sudo cp -a include/gtest /usr/include/
sudo cp -a lib/.libs/* /usr/lib/
echo Cleaning up...
cd ..
sudo rm -r gtest-1.7.0

cat > testf.cpp <<- EOM
#include "gtest/gtest.h"

namespace {
    class testf : public ::testing::Test {
    protected:
        testf() { }
        virtual ~testf() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    };

    TEST_F(testf, add) {
        ASSERT_EQ(13, 3 + 10);
    }
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
EOM

EXPECTED="[  PASSED  ] 1 test."

g++ -std=c++11 -Wall testf.cpp -lgtest -pthread -lgtest_main -o testf
if [ -e testf ]; then
    OUTPUT=$(./testf)
    if [[ "$OUTPUT" == *"$EXPECTED" ]]; then
        echo "Google Test successfully installed."
    else
        echo -e "Google Test encountered a runtime error:\n$OUTPUT"
    fi
else
    echo "Google Test was not properly installed."
fi
rm testf*
