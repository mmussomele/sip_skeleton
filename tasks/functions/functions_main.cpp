/*
 * functions_main.cpp
 *
 *  Created on: June 10, 2015
 *      Author: Matthew Mussomele
 */

#include <stdio.h>
#include <cstdlib>
#include "functions.h"

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
    printf("print_joined(%d, %d): ", a, b);
    print_joined(a, b);
    printf("absolute_sum(%d, %d) = %d\n", a, b, absolute_sum(a, b));
    printf("absolute_sum(%d, %d) = %d\n", a, -b, absolute_sum(a, -b));
    printf("largest_product(%d, %d, %d) = %d\n", a, b, c, largest_product(a, b, c));
    printf("largest_prime_under(%d) = %d\n", c, largest_prime_under(c));
    printf("fact_or_fib(%d) = %d\n", a, fact_or_fib(a));
    printf("fact_or_fib(%d) = %d\n", b, fact_or_fib(b));
    printf("fact_or_fib(%d) = %d\n", c, fact_or_fib(c));
    printf("Exiting.\n");
    return 0;
}
