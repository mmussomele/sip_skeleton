/*
 * Robot.cpp
 *
 *  Created on: June 7, 2015
 *      Author: Matthew Mussomele
 *      
 * This task is based on the squares project, found at http://nifty.stanford.edu/2015/tychonievich-sherriff-layer-counting-squares/
 *
 * Robots simply have knowledge of a set of rooms and their own personal attributes.
 * Because tuples do not have a hash function and sets of rooms should not exceed 1000x1000, coordinates will be 16 bit integers and
 * their 'hash function' should return (x << 16) + y, creating a 32 bit representation, which will be stored in the set of rooms.
 * In order to get the coordinates back from a 32 bit integer, in pseudocode, do
 *     x = hash >> 16;
 *     y = hash % (2^16);
 */

#include <unordered_set>
#include <cstdint>
#include "Robot.h"

/**
 * @brief Creates a new Robot object for use with the Squares project
 * 
 * @param maze the set of locations that exists within the series of "rooms"
 * @param x the starting x coordinate of the Robot
 * @param y the starting y coordinate of the Robot
 */
Robot::Robot(std::unordered_set<int32_t> * maze, int16_t x, int16_t y) {
    squares = maze;
    visited = new std::unordered_set<int32_t>({ get_key(x, y) });
    x_pos = x;
    y_pos = y;
    log_current_location();
    health = 10;
    step_count = 1;
}

/**
 * @brief Deconstructs a Robot instance
 * @details Simply deletes the pointer to the rooms, and the pointer to the visited set
 */
Robot::~Robot() {
    delete squares;
    delete visited;
}

/**
 * @brief If possible, the Robot moves one room to the left.
 * @details If there is a room directly to the left, the Robot moves there. Otherwise, it loses health from running into a wall.
 */
void Robot::move_left() {
    if (can_move_left()) {
        x_pos -= 1;
        log_current_location();
    } else {
        health -= 1;
    }
}

/**
 * @brief Checks if the Robot can move the the room directly left of it
 * @details Verifies that the room directly to the left of the Robot actually exists
 * @return True if the room to the left exists
 */
bool Robot::can_move_left() {
    return exists(-1, 0);
}

/**
 * @brief Same as move_left(), but right
 */
void Robot::move_right() {
    if (can_move_right()) {
        x_pos += 1;
        log_current_location();
    } else {
        health -= 1;
    }
}

/**
 * @brief Same as can_move_left, but right
 */
bool Robot::can_move_right() {
    return exists(1, 0);
}

/**
 * @brief Same as move_left(), but up
 */
void Robot::move_up() {
    if (can_move_up()) {
        y_pos += 1;
        log_current_location();
    } else {
        health -= 1;
    }
}

/**
 * @brief Same as can_move_left, but up
 */
bool Robot::can_move_up() {
    return exists(0, 1);
}

/**
 * @brief Same as move_left(), but down
 */
void Robot::move_down() {
    if (can_move_down()) {
        y_pos -= 1;
        log_current_location();
    } else {
        health -= 1;
    }
}

/**
 * @brief Same as can_move_left, but down
 */
bool Robot::can_move_down() {
    return exists(0, -1);
}

/**
 * @brief If possible, the Robot teleports to the given room.
 * @details The robot teleports to the given room. WARNING: If the room does not exist,
 *          the robot will break and always get the wrong value when tracking room sizes.
 * 
 * @param x the x coordinate to move to
 * @param y the y coordinate to move to
 */
void Robot::move_to(int16_t x, int16_t y) {
    if (can_move_to(x, y)) {
        x_pos = x;
        y_pos = y;
        log_current_location();
    } else {
        health = 0;
    }
}

/**
 * @brief Checks if the Robot teleport to 
 * 
 * @param x the x coordinate to check
 * @param y the y coordinate to check
 * 
 * @return true if the room matching the coordinates exists
 */
bool Robot::can_move_to(int16_t x, int16_t y) {
    return exists(x - x_pos, y - y_pos);
}



/**
 * @brief Gets information on this Robot's interactions with the given coordinates
 * @details Checks if the coordinates represent an existing room, and checks if the Robot has visited it if they do
 * 
 * @param x The x coordinate of the room to check
 * @param y The y coordinate of the room to check
 * 
 * @return -1 if the room doesn't exists, 1 if the Robot has been to the room and 0 if it hasn't
 */
int32_t Robot::has_visited(int16_t x, int16_t y) {
    if (!squares->count(get_key(x, y))) {
        return -1;
    } else if (visited->count(get_key(x, y))) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Gets the key of a position relative to the Robot
 * @details Gets the key of the coordinates (x_pos + delta_x, y_pos + delta_y)  
 * 
 * @param delta_x The x distance from the Robot's current position to check
 * @param delta_y The y distance from the Robot's current position to check
 * 
 * @return A 32 bit integer repesenting the coordinates of the relative coordinates
 */
int32_t Robot::position(int16_t delta_x, int16_t delta_y) {
    return get_key(x_pos + delta_x, y_pos + delta_y);
}

/**
 * @brief Gets the key of an x, y coordinate pair
 * @details Gets a key representing a pair of 16 bit integers
 * 
 * @param x The x coordinate to include in the key
 * @param y The y coordinate to include in the key
 * 
 * @return A 32 bit integer repesenting the coording pair (x, y)
 */
int32_t Robot::get_key(int16_t x, int16_t y) {
    int32_t key = x;
    return (key << 16) + y;
}

/**
 * @brief Checks if there is a room at the position (x, y) relative to the Robot's current position
 * 
 * @param x The relative x coordinate
 * @param y The relative y coordinate
 * 
 * @return True if the room at (x, y) relative to the Robot exists
 */
bool Robot::exists(int16_t x, int16_t y) {
    return (squares->count(position(x, y))) ? true : false;
}

/**
 * @brief Gets the number of steps the Robot has taken
 * @return The number of steps the Robot has taken
 */
int32_t Robot::get_count() {
    if (health > 0) {
        return step_count;
    } else {
        return 0x1DEADB07;
    }
}

/**
 * @brief Sets the number of steps the Robot has taken
 * 
 * @param c The number to set the steps to
 */
void Robot::set_count(int32_t c) {
    step_count = c;
}

/**
 * @brief gets the key corresponding to the Robot's current location
 *
 * @return the key of the current location
 */
int32_t Robot::get_position_key() {
    return get_key(x_pos, y_pos);
}

/**
 * @brief Logs that the Robot has visited it's current location
 * @details If the Robot has not been here before, add it to the visited set. Then, regardless of the last check, add one to the number of steps taken
 */
void Robot::log_current_location() {
    if (!visited->count(get_key(x_pos, y_pos))) {
        visited->insert(get_key(x_pos, y_pos));
    }
    step_count += 1;
}
