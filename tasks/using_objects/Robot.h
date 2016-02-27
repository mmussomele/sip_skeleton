/*
 * Robot.h
 *
 *  Created on: June 7, 2015
 *      Author: Matthew Mussomele
 */

#ifndef TASKS_USING_OBJECTS_ROBOT_H_
#define TASKS_USING_OBJECTS_ROBOT_H_

#include <unordered_set>
#include <cstdint>

using namespace std;

class Robot {
 public:
    Robot(unordered_set<int32_t> * maze, int16_t x, int16_t y);
    ~Robot();
    void move_left();
    bool can_move_left();
    void move_right();
    bool can_move_right();
    void move_up();
    bool can_move_up();
    void move_down();
    bool can_move_down();
    void move_to(int16_t x, int16_t y);
    bool can_move_to(int16_t x, int16_t y);
    int32_t get_count();
    int32_t has_visited(int16_t x, int16_t y);
    void set_count(int32_t c);
    int32_t get_position_key();

 private:
    int32_t position(int16_t delta_x, int16_t delta_y);
    int32_t get_key(int16_t x, int16_t y);
    bool exists(int16_t x, int16_t y);
    void log_current_location();
    unordered_set<int32_t> * squares;
    unordered_set<int32_t> * visited;
    int32_t health;
    int16_t x_pos;
    int16_t y_pos;
    int32_t step_count;
};

#endif /* TASKS_USING_OBJECTS_ROBOT_H_ */
