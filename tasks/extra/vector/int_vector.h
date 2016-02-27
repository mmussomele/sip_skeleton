/*
 * int_vector.h
 *
 *  Created on: July 22, 2015
 *      Author: Matthew Mussomele
 */

#ifndef TASKS_EXTRA_VECTOR_H_
#define TASKS_EXTRA_VECTOR_H_

#include <cstdint>

class int_vector {
 public:
    int_vector();
    ~int_vector();
    void add(int32_t);              // add the given integer to the end of the vector
    void insert(int32_t, int32_t);  // insert the second integer at the index of the first integer. Do nothing if the index is out of bounds
    void set(int32_t, int32_t);     // set the value at the index of the first integer to that of the second. Do nothing if the index is out of bounds
    int32_t remove(int32_t);        // remove the integer at the given index and return it. Return 0 if the index is invalid
    int32_t get(int32_t);           // returns the integer at the given index. Return 0 if the index is invalid
    void clear();                   // removes all elements from the vector
    bool contains(int32_t);         // returns true if the given integer exists in the vector
    int32_t size();                 // returns the size of the vector (number of elements)



 private:
    /* ADD EXTRA STUFF HERE */
    
};

#endif /* TASKS_EXTRA_VECTOR_H_ */
