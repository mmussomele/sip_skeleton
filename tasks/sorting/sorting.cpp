/**
 * sorting.cpp
 * 
 *   Created On: June 17, 2015
 *       Author: Matthew Mussomele
 */
 
#include <cstdint>
#include <stdlib.h>
#include <time.h>

/**
 * Question 1: Given an array and two indices within it, swap the elements at the indices in the original array.
 * 
 * @brief swaps two elements in an array
 * 
 * @param array the array to swap inside of
 * @param first the index of the first thing to swap
 * @param second the index of the second thing to swap
 */
void swap(int32_t array[], int32_t first, int32_t second) {
    /* YOUR CODE HERE */
}

/**
 * Question 2: Implement the bubble sort algorithm to sort the given array in place. Consult the slides if you need a refresher.
 * 
 * @brief sorts the given array using bubble sort
 * 
 * @param array the array to sort
 */
void bubble_sort(int32_t array[], int32_t size) {
    /* YOUR CODE HERE */
}

/**
 * Question 3: Implement the selection sort algorithm to sort the given array in place. Consult the slides if you need a refresher.
 * 
 * @brief sorts the given array using selection sort
 * 
 * @param array the array to sort
 */
void selection_sort(int32_t array[], int32_t size) {
    /* YOUR CODE HERE */
}

/**
 * Question 4: Implement the insertion sort algorithm to sort the given array in place. Consult the slides if you need a refresher.
 * 
 * @brief sorts the given array using insertion sort
 * 
 * @param array the array to sort
 */
void insertion_sort(int32_t array[], int32_t size) {
    /* YOUR CODE HERE */
}

/////////////////////////////////////////////////////////////////
// You are not expected to understand anything below this line //
/////////////////////////////////////////////////////////////////

void merge(int32_t * array, int32_t low, int32_t middle, int32_t high); // forward declaration for merge

/**
 * @brief sorts the given array from low to high using mergesort
 * 
 * @param array the array to sort
 * @param low the index to start sorting at
 * @param high the index to end the sorting at
 */
void mergesort(int32_t * array, int32_t low, int32_t high) {
    if (low >= high) {
        return;
    } else {
        int32_t middle = low + (high - low) / 2;
        mergesort(array, low, middle);
        mergesort(array, middle + 1, high);
        merge(array, low, middle, high);
    }
}

/**
 * @brief merges two sorted subsections of an array
 * 
 * @param array the array to merge subsections of
 * @param low the index that the first subsection begins at
 * @param middle the index that ends the first and starts the second subsection
 * @param high the index that ends the second subsection
 */
void merge(int32_t * array, int32_t low, int32_t middle, int32_t high) {
    int32_t main_index = 0;
    int32_t left_index = low;
    int32_t right_index = middle + 1;
    int32_t merged[high - low + 1];
    while (left_index <= middle && right_index <= high) {
        merged[main_index++] = array[left_index] < array[right_index] ? array[left_index++] : array[right_index++];
    }
    while (left_index <= middle) {
        merged[main_index++] = array[left_index++];
    }
    while (right_index <= high) {
        merged[main_index++] = array[right_index++];
    }
    for (int i = 0; i < main_index; i += 1) {
        array[i + low] = merged[i];
    }
}

/**
 * @brief sorts the given array from low to high using quicksort
 * 
 * @param array the array to sort
 * @param low the index to start sorting at
 * @param high the index to stop sorting at
 */
void quicksort(int32_t array[], int32_t low, int32_t high) {
    int32_t pivot = array[low + (high - low) / 2];
    int32_t i = low;
    int32_t j = high;
    while (low < j || i < high) {
        while (array[i] < pivot) {
            i += 1;
        }
        while (array[j] > pivot) {
            j -= 1;
        }
        if (i <= j) {
            swap(array, i++, j--);
        } else {
            if (low < j) {
                quicksort(array, low, j);
            }
            if (i < high) {
                quicksort(array, i, high);
            }
            return;
        }
    }
}

/**
* @brief returns a randomly generated integer array with size elements
* 
* @param size the number of elements to have in the array.
* @return the new array
*/
int32_t * get_random_array_of_size(int32_t size) {
    srand(time(NULL));
    int32_t * new_array = new int32_t[size];
    for (int32_t i = 0; i < size; i += 1) {
        new_array[i] = rand() % size;
    }
    return new_array;
}

