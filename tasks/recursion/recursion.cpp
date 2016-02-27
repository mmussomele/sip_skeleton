/*
 * recursion.cpp
 *
 *  Created on: July 9, 2015
 *      Author: Matthew Mussomele
 */

#include <cstdint>

/**
 * Question 1: Write a recursive function that computes the product of two numbers 
 *             a and b. You may only use the addition and subtraction operators.
 * 
 * @brief returns the product of two integers a and b
 * @param  a the first integer
 * @param  b the second integer
 * @return   a times b
 */
int32_t mul(int32_t a, int32_t b) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * Question 2: Write a recursive function that computes the sum of all the elements in the 
 *             given array after 'index'. Do NOT use a loop of any kind.
 * 
 * @brief sums the integers in an array, starting at the given index and going to the end
 * @param  numbers the array to sum
 * @param  size    the size of the given array
 * @param  index   the index to start at
 * @return         the sum of all elements in the array after the given index
 */
int32_t sum_array(int32_t * numbers, int32_t size, int32_t index) {
    /* YOUR CODE HERE */
    return 0;
}

void swap(char[], int32_t, int32_t);

/**
 * Question 3: Write a recursive function that takes in a string and reverses it in 
 *             between the letters at start and end, inclusive. You may assume that 
 *             the start and end indices are valid.
 * 
 * @brief takes in a string and reverses it in between the given indices
 * @param word  the string to reverse
 * @param start the index to start at
 * @param end   the index to end at
 */
void reverse_string(char word[], int32_t start, int32_t end) {
    /* YOUR CODE HERE */
}

void swap(char word[], int32_t i, int32_t j) {
    char temp = word[i];
    word[i] = word[j];
    word[j] = temp;
}

/**
 * Question 4: Write a recursive function that checks if the given string is a palindrome
 *             between the letters at indices start and end, inclusive. You may assume that start 
 *             and end are valid indices in the string. You also may assume all letters are lower
 *             case.
 *
 *       Note: A palindrome is a word that reads the same forwards and backwards.
 *             Examples:
 *                       sees
 *                       racecar
 *                       anna
 *                       tattarrattat
 * 
 * @brief checks if the given string is a palindrome, considering only the letters from start to end
 * @param  word  the word to check
 * @param  start the letter to start at
 * @param  end   the letter to end at
 * @return       true if the string is a palindrome between the letters at start and end
 */
bool is_palindrome(const char * word, int32_t start, int32_t end) {
    /* YOUR CODE HERE */
    return false;
}

//uncomment the line below if you want to use the make_change_with function
//int32_t make_change_with(int32_t, int32_t);

int32_t coin_sizes[] = {1, 5, 10, 25, 50, 100};
int32_t coin_count = 6;

/**
 * Question 5: Write a recursive function to find the number of ways to make change
 *             for the given amount of money using the coin values in the coin_sizes 
 *             array. 
 *       Hint: Use the make_change_with function to do all the work, and just pass it 
 *             the correct arguments for your implementation. If you do this, only
 *             make_change_with should be recursive.
 * 
 * @brief finds the number of ways to make change for the given amount
 * @param  amount the amount to make change for
 * @return        the number of ways to make change for the given amount
 */
int32_t ways_to_make_change(int32_t amount) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * @brief returns the number of ways to make change for amount starting at the give coin_type
 * @param  amount    the amount to make change for
 * @param  coin_type the coin type to try and use to make for the amount
 * @return           the number of different ways to make change for amount
 */
int32_t make_change_with(int32_t amount, int32_t coin_type) {
    /* YOUR CODE HERE (OPTIONAL) */
    return 0;
}
