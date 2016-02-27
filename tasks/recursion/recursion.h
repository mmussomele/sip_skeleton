/*
 * recursion.h
 *
 *  Created on: July 9, 2015
 *      Author: Matthew Mussomele
 */

#include <cstdint>

#ifndef TASKS_RECURSION_RECURSION_H
#define TASKS_RECURSION_RECURSION_H

int32_t mul(int32_t a, int32_t b);
int32_t sum_array(int32_t * numbers, int32_t size, int32_t index);
void reverse_string(char word[], int32_t start, int32_t end);
bool is_palindrome(const char * word , int32_t start, int32_t end);
int32_t ways_to_make_change(int32_t amount);

#endif /* TASKS_RECURSION_RECURSION_H */