/*
 * Calculator_main.cpp
 *
 *  Created on: June 24, 2015
 *      Author: Matthew Mussomele
 */

#include <stdio.h>
#include <cstdlib>
#include "Calculator.h"

int main(int argc, char ** argv) {
    double a, b, c;
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
    Calculator calc;
    calc.store(c);
    printf("%s\n", "Calculator calls:");
    printf("%.3f + %.3f = %.3f\n", a, b, calc.add(a, b));
    printf("%.3f * %.3f = %.3f\n", a, b, calc.mul(a, b));
    printf("%.3f - %.3f = %.3f\n", a, b, calc.sub(a, b));
    printf("%.3f / %.3f = %.3f\n", a, b, calc.div(a, b));
    printf("%.3f + %.3f = %.3f\n", a, c, calc.add_stored(a));
    printf("%.3f * %.3f = %.3f\n", a, c, calc.mul_stored(a));
    printf("%.3f - %.3f = %.3f\n", a, c, calc.sub_stored(a));
    printf("%.3f / %.3f = %.3f\n", a, c, calc.div_stored(a));
    printf("\n%s\n", "History lookups:");
    for (int32_t i = 7; i >= 0; i -= 1) {
        printf("%s\n", calc.get_call(i).c_str());
    }
    return 0;
}
