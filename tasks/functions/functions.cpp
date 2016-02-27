/**
 * functions.cpp
 * 
 *   Created On: June 10, 2015
 *       Author: Matthew Mussomele   
 */

#include <iostream>
#include <cstdint>
#include <math.h>

/**
 * Question 1: Given two integers, print them on a single line, with no spaces,
 *             followed by a newline. 
 *             If the second number is negative, make it positive when joining.
 *             Example:
 *                 print_joined(500, 0)     prints 5000
 *                 print_joined(1283, 9123) prints 12839123
 *                 print_joined(-3, 15)     prints -315
 *                 print_joined(3, -15)     prints 315
 * 
 * @brief prints two integers concatenated as strings
 * 
 * @param a The first integer to print
 * @param b The second integer to print
 */
void print_joined(int32_t a, int32_t b) {
    /* YOUR CODE HERE */
}
 
/**
 * Question 2: Find the absolute value of the sum of two numbers.
 * 
 * @brief returns the absolute value of (a + b)
 * 
 * @param a the first integer to sum
 * @param b the second integer to sum
 * 
 * @return the absolute value of the sum of the two integers
 */
int32_t absolute_sum(int32_t a, int32_t b) {
    /* YOUR CODE HERE */
    return 0;
}

int32_t min_of_three(int32_t a, int32_t b, int32_t c); //forward declaration for min_of_three

/**
 * Question 3: Find the largest product of any two numbers from three given positive integers.
 *      Bonus: Complete this question using only a single statement.
 *       HINT: The helper function below, min_of_three, might come in handy
 * @brief returns the largest product that can be made with any two of the integers
 * 
 * @param a the first integer
 * @param b the second integer
 * @param c the third integer
 * @return the largest product of any two of the given integers.
 */
int32_t largest_product(int32_t a, int32_t b, int32_t c) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * @brief Finds the smallest of three integers
 * 
 * @param a the first integer
 * @param b the second integer
 * @param c the third integer
 * @return the minimum of a, b and c
 */
int32_t min_of_three(int32_t a, int32_t b, int32_t c) {
    return std::min(a, std::min(b, c));
}

/**
 * NOTE: This function is complete. Use it to do question 4.
 * @brief checks if the given number is prime
 *
 * @param n the number to check
 * @return true if the given number is prime
 */
bool is_prime(int32_t n) {
    if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    } else {
        int32_t max_check = (int32_t) (sqrt(n) + 1);
        for (int32_t i = 3; i <= max_check; i += 2) {
            if ((n % i) == 0) {
                return false;
            } 
        }
        return true;
    }
}

/**
 * Question 4: Complete the largest_prime_under function. It should take in an integer and return the 
 *             largest prime number less than or equal to it. If there are no prime numbers less than
 *             or equal to the given number, return the given number.
 *
 * @brief finds the largest prime number less than or equal to the given integer
 *
 * @param n the number to find the closest prime to
 * @return the largest prime less than n, or n if there is no such prime
 */
int32_t largest_prime_under(int32_t n) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * Question 5: If n is odd, return n!. If n is even, return the nth fibonacci number. If n is negative, return 1
 *             
 *             Factorial:
 *                 n! is defined as n * (n - 1) * ... * 1   if n >= 1
 *                                  1                       if n < 1
 *             Fibonacci:
 *                 Let fib(n) calculate the nth fibonacci number. The fibonacci function
 *                 is undefined for inputs less than 0.
 *                 fib(n) = n                       if n < 2
 *                 fib(n) = fib(n-1) + fib(n-2)     if n >= 2
 * 
 * @brief Calculates either n! or the nth fibonacci number
 * 
 * @param n the number to run calculations on
 * @return either n! or fibonacci(n)
 */
int32_t fact_or_fib(int32_t n){
    /* YOUR CODE HERE */
    return 0;
}
