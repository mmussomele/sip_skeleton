/*
 * sorting_main.cpp
 *
 *  Created on: June 17, 2015
 *      Author: Matthew Mussomele
 */
 
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int32_t MAX_SIZE = 65536;
std::clock_t STOPWATCH;
int32_t SIZE = 16;

/**
 * @brief prints the contents of an integer array in human readable format
 * 
 * @param array the array to print
 * @param size the size of the array
 */
void print_array(int32_t array[], int32_t SIZE) {
    printf("[ ");
    for (int32_t i = 0; i < SIZE; i += 1) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void print_tabs(int32_t tabs) {
    for (int32_t tab_count = 0; tab_count < tabs; tab_count += 1) {
        printf("\t");
    }
}

void run_sort(void (*sort)(int32_t*, int32_t), int32_t * test_array, const char * sort_name) {
    (*sort)(test_array, SIZE);
    printf("The array sorted with %s sort:", sort_name);
    print_tabs(1);
    print_array(test_array, SIZE);
}

void run_task_sort(void (*sort)(int32_t*, int32_t), const char * sort_name, int32_t tabs) {
    printf("%s:", sort_name);
    print_tabs(tabs);
    for (int32_t i = 1024; i <= MAX_SIZE; i *= 2) {
        int32_t * test_array = get_random_array_of_size(i);
        STOPWATCH = std::clock();
        (*sort)(test_array, i);
        printf("%.3f\t", (std::clock() - STOPWATCH) / (double) CLOCKS_PER_SEC);
    }
    printf("\n");
}

void run_example_sort(void (*sort)(int32_t*, int32_t, int32_t), const char * sort_name) {
    printf("%s:\t\t", sort_name);
    for (int32_t i = 1024; i <= MAX_SIZE; i *= 2) {
       int32_t * test_array = get_random_array_of_size(i);
        STOPWATCH = std::clock();
        (*sort)(test_array, 0, i - 1);
        printf("%.3f\t", (std::clock() - STOPWATCH) / (double) CLOCKS_PER_SEC);
    }
    printf("\n");
}

int main(int argc, char ** argv) {
    int32_t array1[] = {2, 65, 34, 7, 1, 61, 4136, 1, 543, 613, 64, 4, 90, 936, 94, 2398};
    int32_t array2[] = {2, 65, 34, 7, 1, 61, 4136, 1, 543, 613, 64, 4, 90, 936, 94, 2398};
    int32_t array3[] = {2, 65, 34, 7, 1, 61, 4136, 1, 543, 613, 64, 4, 90, 936, 94, 2398};
    int32_t array4[] = {2, 65, 34, 7, 1, 61, 4136, 1, 543, 613, 64, 4, 90, 936, 94, 2398};
    int32_t array5[] = {2, 65, 34, 7, 1, 61, 4136, 1, 543, 613, 64, 4, 90, 936, 94, 2398};

    printf("The array before sorting:\t\t");
    print_array(array1, SIZE);

    run_sort(bubble_sort, array1, "bubble");
    run_sort(selection_sort, array2, "selection");
    run_sort(insertion_sort, array3, "insertion");

    mergesort(array4, 0, SIZE - 1);
    printf("The array sorted with mergesort:\t");
    print_array(array4, SIZE);

    quicksort(array5, 0, SIZE - 1);
    printf("The array sorted with quicksort:\t");
    print_array(array5, SIZE);

    printf("Sorting bigger arrays for runtime comparision (time in seconds)...\n");

    printf("Sort\t\t");
    for (int32_t i = 1024; i <= MAX_SIZE; i *= 2) {
        printf("%d\t", i);
    }
    printf("\n");

    run_task_sort(bubble_sort, "Bubble", 2);
    run_task_sort(selection_sort, "Selection", 1);
    run_task_sort(insertion_sort, "Insertion", 1);
    run_example_sort(mergesort, "Merge");
    run_example_sort(quicksort, "Quick");

}