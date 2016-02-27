/*
 * pointers.h
 *
 *  Created on: June 12, 2015
 *      Author: Matthew Mussomele
 */

#include <cstdint>

#ifndef TASKS_POINTERS_POINTERS_H
#define TASKS_POINTERS_POINTERS_H

int32_t get_value(int32_t * a);
void set_value(int32_t * a, int32_t new_value);
int32_t get_true_value(int32_t ** a);
int32_t * move_pointer(int32_t * pointer, int32_t inc);
int32_t get_shifted_value(int32_t * pointer, int32_t inc);
int32_t apply(int32_t (* fn)(int32_t), int32_t n);

#endif /* TASKS_POINTERS_POINTERS_H */