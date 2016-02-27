/*
 * sorting.h
 *
 *  Created on: June 17, 2015
 *      Author: Matthew Mussomele
 */

#include <cstdint>

#ifndef TASKS_SORTING_SORTING_H
#define TASKS_SORTING_SORTING_H

int32_t * get_random_array_of_size(int32_t size);
void swap(int32_t array[], int32_t first, int32_t second);
void bubble_sort(int32_t array[], int32_t size);
void selection_sort(int32_t array[], int32_t size);
void insertion_sort(int32_t array[], int32_t size);
void mergesort(int32_t array[], int32_t low, int32_t high);
void quicksort(int32_t array[], int32_t low, int32_t high);

#endif /* TASKS_SORTING_SORTING_H */