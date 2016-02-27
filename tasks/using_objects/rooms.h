/*
 * rooms.h
 *
 *  Created on: July 1, 2015
 *      Author: Matthew Mussomele
 */

#ifndef TASKS_USING_OBJECTS_ROOMS_H_
#define TASKS_USING_OBJECTS_ROOMS_H_

#include <cstdint>
#include "Robot.h"

int32_t square_room_top_left_corner(Robot& robot);
int32_t rectangle_room_top_left_corner(Robot * robot);
int32_t rectangle_room_random_location(Robot& robot);
int32_t irregular_room_random_location(Robot& robot);

#endif /* TASKS_USING_OBJECTS_ROOMS_H_ */
