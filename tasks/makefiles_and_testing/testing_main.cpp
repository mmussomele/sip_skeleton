/*
 * testing_main.cpp
 *
 *  Created on: June 11, 2015
 *      Author: Matthew Mussomele
 */

#include <stdio.h>
#include <cstdint>
#include <stdlib.h>
#include "testing.h"

int main(int argc, char ** argv) {
    int32_t a, b, c;
    if (argc != 4) {
        printf("Invalid number of args given, running with default a = 2, b = 5, c = 7.\n");
        a = 2;
        b = 5;
        c = 7;
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }
    printf("factorial(%d) = %d\n", a, factorial(a));
    printf("bound(%d, %d, %d) = %d\n", a, b, c, bound(a, b, c));
    printf("fibonacci(%d) = %d\n", a, fibonacci(a));
    printf("contains_even_digit(%d) = %s\n", a, contains_even_digit(a)? "true" : "false");
    printf("average(%d, %d) = %d\n", a, b, average(a, b));
    printf("Exiting.\n");
    return 0;
}