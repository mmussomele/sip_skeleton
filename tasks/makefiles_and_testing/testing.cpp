/**
 * testing.cpp
 * 
 *   Created On: June 11, 2015
 *       Author: Matthew Mussomele   
 */

#include <cstdint>

/////////////////////////////////////////////////////////////////////////////////////////////
// This assignment is a little different than most. You won't be writing any               //
// whole functions yourself. Instead, you will take the mostly correct functions           //
// in this file and find the bugs in them and correct them.                                //
// You have not been given any header files! Write your own so testing_main.cpp compiles!  //
// You will also notice that there is no makefile for this task. Write your own!           //
// Note: Some of the functions may have more than one bug!                                 //
// Hint: Write test cases to try and find the bugs! (The harder ones will be edge cases)   //
/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Question 1: Fix the factorial function. You may assume all inputs are positive.
 * 
 * @brief calculate the factorial of n
 * 
 * @param n the number to find the factorial of
 * @return n!
 */
int32_t factorial(int32_t n) {
    for (int32_t i = 1; i <= n; i += 1) {
        n *= i;
    }
    return n;
}

/**
 * Question 2: Fix the bound function. You may not assume inputs are positive.
 * 
 * @brief Bounds a to be in the range [lower, upper]
 * 
 * @param a the number to bound
 * @param lower the lower bound of the range
 * @param upper the upper bound of the range
 * @return either a or one of the two bounds
 */
int32_t bound(int32_t a, int32_t lower, int32_t upper) {
    if (upper > a) {
        return upper;
    } else if (lower < a) {
        return lower;
    } else {
        return a;
    }
}

/**
 * Question 3: Fix the fibonacci function. You may assume all inputs are positive.
 * 
 * @brief calculates the nth fibonacci number
 * 
 * @param n the fibonacci number to calculate
 * @return the nth fibonacci number
 */
int32_t fibonacci(int32_t n) {
    int32_t prev = 0;
    int32_t cur = 1;
    for (int32_t i = 0; i < n; i += 1) {
        cur += prev;
        prev = cur;
    }
    return cur;
}

/**
 * Question 4: Fix the contains_even_digit function. You may assume all inputs are positive.
 *       Note: The operation (digit >> 1) effectively divides a number by two, rounding down.
 *       
 * @brief checks whether n contains an even digit
 * 
 * @param n the number to check
 * @return true if n contains an even digit
 */
bool contains_even_digit(int32_t n) {
    while (n > 0) {
        int32_t digit = n % 10;
        if (digit / 2 == digit >> 1) {
            return true;
        }
        n /= 10;
    }
    return false;
}

/**
 * Question 5: Fix the average function. You may not assume inputs are positive.
 * 
 * @brief calculates the average of two integers, rounded down to the closet integer
 * 
 * @param a the first number 
 * @param b the second number
 * 
 * @return the truncated average of two integers
 */
int32_t average(int32_t a, int32_t b) {
    return (a + b) / 2;
}
