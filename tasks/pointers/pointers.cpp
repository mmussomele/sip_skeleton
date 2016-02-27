/**
 * pointers.cpp
 * 
 *   Created On: June 12, 2015
 *       Author: Matthew Mussomele   
 */
 
#include <cstdint>
 
////////////////////////////////////////////////////////////////////////////////////////////////
// In any of the following questions, you may not assume that the given pointers aren't null. //
// If a null pointer is given, simply return 0 or the given pointer, whichever is             //
// contextually appropriate.                                                                  //
// This task has no main file. You may write one if you wish, but it is not required.         //
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Question 1: Write a short function to take the pointer and return the value that it points to.
 * 
 * @brief gets the value of the variable a points to
 * 
 * @param a the pointer who's value to get
 * @return the value in the address a points to
 */
int32_t get_value(int32_t * a) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * Question 2: Write a short function to take the pointer and change the value of the variable it points to.
 * 
 * @brief sets the value of what a points to to new_value
 * 
 * @param a the pointer who's value to change
 * @param new_value the new number to set the memory address's content to
 */
void set_value(int32_t * a, int32_t new_value) {
    /* YOUR CODE HERE */
}

/**
 * Question 3: Write a short function to take in a double pointer and dereference it completely.
 * 
 * @brief gets the value of the variable pointed to by the pointer that the given pointer points to
 * 
 * @param a the double pointer to dereference
 * @return the value of the variable pointed to by the pointer that the given pointer points to
 */
int32_t get_true_value(int32_t ** a) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * Question 4: Write a short function to take in a pointer and an integer. It should return a new pointer that is pointing inc memory units further in memory. You may assume the new pointer will be valid.
 * 
 * @brief Increases a given pointer's value by the given amount and returns the new value 
 * 
 * @param pointer the pointer value to change
 * @param inc the amount to change the pointer by
 * 
 * @return a new pointer pointing inc memory units away
 */
int32_t * move_pointer(int32_t * pointer, int32_t inc) {
    /* YOUR CODE HERE */
    return 0;
}

/**
 * Question 5: Write a short function to take in a pointer and an integer. It should return the integer that is inc units further in memory than pointer. You may assume the new pointer will be valid.
 * 
 * @brief returns the value stored at a location inc away from the given pointer
 * 
 * @param pointer the pointer value to start at
 * @param inc the amount to move in memory
 * 
 * @return the value at the memory location that is inc units away
 */
int32_t get_shifted_value(int32_t * pointer, int32_t inc) {
    /* YOUR CODE HERE */
    return 0;
} 

/**
 * Question 6: Fill out the following function. 
 *             It's first argument should take a pointer to any function which takes
 *             in an int32_t and returns one.
 *             Its second argument should take an int32_t.
 *             It should then return the result of calling the function on the integer.
 * 
 * @brief Calls a given function on a given input and returns the result.
 * 
 * @param fn the function to call
 * @param n the input to the function
 * 
 * @return the result of calling fn(n)
 */
int32_t apply(/* YOUR CODE HERE */) {
    /* YOUR CODE HERE */
    return 0;
}
