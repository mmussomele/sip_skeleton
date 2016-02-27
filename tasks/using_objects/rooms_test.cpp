/*
 * rooms_test.cpp
 * 
 *   Created On: July 1, 2015
 *       Author: Matthew Mussomele
 */

#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include "gtest/gtest.h"
#include "rooms.h"
#include "Robot.h"

namespace {

    class rooms_test : public ::testing::Test {
    protected:
        rooms_test() { }
        virtual ~rooms_test() { }
        virtual void SetUp() { } 
        virtual void TearDown() { }
    public:
        int16_t start_x = 0;
        int16_t start_y = 0;

        // returns the unordered_set key corresponding to the coordinates
        int32_t get_key(int16_t x, int16_t y) {
            int32_t key = x;
            return (key << 16) + y;
        }

        // returns the x coordinate of a key
        int16_t get_x(int32_t key) {
            return key >> 16;
        }

        // returns the y coordinate of a key
        int16_t get_y(int32_t key) {
            return key % 65536;
        }

        // returns an unordered_set representing a square room of the given side length
        std::unordered_set<int32_t> * create_square_room(int32_t side_length) {
            return create_rectangle_room(side_length, side_length);
        }

        // returns an unordered_set representing a rectangular room of the given side lengths
        std::unordered_set<int32_t> * create_rectangle_room(int32_t length, int32_t width) {
            std::unordered_set<int32_t> * new_room = new std::unordered_set<int32_t>();
            for (int32_t i = 0; i < length; i += 1) {
                for (int32_t j = 0; j < width; j += 1) {
                    new_room->insert(get_key(i, j));
                }
            }
            srand(time(NULL));
            int32_t salt_blocks = 3 + rand() % 7;
            for (int32_t i = 0; i < salt_blocks; i += 1) {
                new_room->insert(get_key(length + 3 + (rand() % 7), width + 3 + rand() % 7)); //add salt blocks to prevent cheating
            }
            return new_room;
        }

        // returns an unordered_set representing a mystery room
        std::unordered_set<int32_t> * create_room_type_1(int32_t side_length) {
            std::unordered_set<int32_t> * new_room = new std::unordered_set<int32_t>();
            int32_t offset = 100 + (rand() % 1000);
            for (int32_t i = 0; i < side_length; i += 1) {
                for (int32_t j = 0; j < side_length - i; j += 1) {
                    new_room->insert(get_key(i + offset, j + offset));
                }
            }
            start_x = offset + (rand() % side_length);
            start_y = offset + (rand() % (side_length - start_x + offset));
            int32_t salt_blocks = 3 + rand() % 7;
            for (int32_t i = 0; i < salt_blocks; i += 1) {
                new_room->insert(get_key(rand() % 20, i)); //add salt blocks to prevent cheating
            }
            return new_room;
        }

        // returns an unordered_set representing a mystery room
        std::unordered_set<int32_t> * create_room_type_2(int32_t height, int32_t width, int32_t bottom_height, int32_t side_width) {
            std::unordered_set<int32_t> * new_room = new std::unordered_set<int32_t>();
            int32_t offset = 100 + (rand() % 1000);
            for (int32_t i = 0; i < height; i += 1) {
                int32_t end_blocks = 0;
                if (i < bottom_height) {
                    end_blocks = width;
                } else {
                    end_blocks = side_width;
                }
                for (int32_t j = 0; j < end_blocks; j += 1) {
                    new_room->insert(get_key(i + offset, j + offset));
                }
            }
            start_x = offset + (rand() % height);
            if (start_x < bottom_height) {
                start_y = offset + (rand() % width);
            } else {
                start_y = offset + (rand() % side_width);
            }
            int32_t salt_blocks = 3 + rand() % 7;
            for (int32_t i = 0; i < salt_blocks; i += 1) {
                new_room->insert(get_key(rand() % 20, i)); //add salt blocks to prevent cheating
            }
            return new_room;
        }

        // returns an unordered_set representing a mystery room
        std::unordered_set<int32_t> * create_room_type_3(int32_t side_length, int32_t shell_length) {
            std::unordered_set<int32_t> * new_room = new std::unordered_set<int32_t>();
            int32_t offset = 100 + (rand() % 1000);
            int32_t shell_start = (side_length - shell_length) / 2;
            int32_t shell_end = side_length - shell_start;
            for (int32_t i = 0; i < side_length; i += 1) {
                for (int32_t j = 0; j < side_length; j += 1) {
                    if (i <= shell_start || i > shell_end || j <= shell_start || j > shell_end) {
                        new_room->insert(get_key(i + offset, j + offset));
                    }
                }
            }
            do {
                start_x = offset + (rand() % side_length);
                start_y = offset + (rand() % side_length);
            } while (!new_room->count(get_key(start_x, start_y)));
            int32_t salt_blocks = 3 + rand() % 7;
            for (int32_t i = 0; i < salt_blocks; i += 1) {
                new_room->insert(get_key(rand() % 20, i));
            }
            return new_room;
        }

        // allows for random ordering of priority queue
        static bool Compare(int32_t x, int32_t y) {
            if (rand() % 2) {
                return false;
            }
            return true;
        }
        
        // returns an unordered_set representing a mystery room
        std::unordered_set<int32_t> * create_room_type_4(int32_t size) {
            std::unordered_set<int32_t> * new_room = new std::unordered_set<int32_t>();
            std::priority_queue<int32_t, std::vector<int32_t>, std::function<bool(int32_t, int32_t)>> to_visit(Compare);
            int32_t offset = 100 + (rand() % 1000);
            start_x = offset;
            start_y = offset;
            to_visit.push(get_key(start_x, start_y));
            while (new_room->size() < size) {
                int32_t next_square = to_visit.top();
                to_visit.pop();
                new_room->insert(next_square);
                int16_t current_x = get_x(next_square);
                int16_t current_y = get_y(next_square);
                if (!new_room->count(get_key(current_x + 1, current_y))) {
                    to_visit.push(get_key(current_x + 1, current_y));
                }
                if (!new_room->count(get_key(current_x, current_y + 1))) {
                    to_visit.push(get_key(current_x, current_y + 1));
                }
                if (!new_room->count(get_key(current_x - 1, current_y))) {
                    to_visit.push(get_key(current_x - 1, current_y));
                }
                if (!new_room->count(get_key(current_x, current_y - 1))) {
                    to_visit.push(get_key(current_x, current_y - 1));
                }
            }
            return new_room;
        }
    };

    TEST_F(rooms_test, test_square_room_top_left_small) {
        Robot rob1(create_square_room(3), 0, 2);
        Robot rob2(create_square_room(4), 0, 3);
        Robot rob3(create_square_room(5), 0, 4);
        ASSERT_EQ(9, square_room_top_left_corner(rob1));
        ASSERT_EQ(16, square_room_top_left_corner(rob2));
        ASSERT_EQ(25, square_room_top_left_corner(rob3));
    }

    TEST_F(rooms_test, test_square_room_top_left_large) {
        Robot rob1(create_square_room(10), 0, 9);
        Robot rob2(create_square_room(20), 0, 19);
        Robot rob3(create_square_room(30), 0, 29);
        ASSERT_EQ(100, square_room_top_left_corner(rob1));
        ASSERT_EQ(400, square_room_top_left_corner(rob2));
        ASSERT_EQ(900, square_room_top_left_corner(rob3));
    } 

    TEST_F(rooms_test, test_rect_room_top_left_small) {
        Robot * rob1 = new Robot(create_rectangle_room(1, 2), 0, 1);
        Robot * rob2 = new Robot(create_rectangle_room(5, 2), 0, 1);
        Robot * rob3 = new Robot(create_rectangle_room(3, 9), 0, 8);
        ASSERT_EQ(2, rectangle_room_top_left_corner(rob1));
        ASSERT_EQ(10, rectangle_room_top_left_corner(rob2));
        ASSERT_EQ(27, rectangle_room_top_left_corner(rob3));
    }

    TEST_F(rooms_test, test_rect_room_top_left_large) {
        Robot * rob1 = new Robot(create_rectangle_room(21, 17), 0, 16);
        Robot * rob2 = new Robot(create_rectangle_room(41, 57), 0, 56);
        Robot * rob3 = new Robot(create_rectangle_room(65, 92), 0, 91);
        ASSERT_EQ(357, rectangle_room_top_left_corner(rob1));
        ASSERT_EQ(2337, rectangle_room_top_left_corner(rob2));
        ASSERT_EQ(5980, rectangle_room_top_left_corner(rob3));
    }

    TEST_F(rooms_test, test_rect_room_random_small) {
        srand(time(NULL));
        Robot rob1(create_rectangle_room(7, 2), rand() % 7, rand() % 2);
        Robot rob2(create_rectangle_room(3, 9), rand() % 3, rand() % 9);
        ASSERT_EQ(14, rectangle_room_random_location(rob1));
        ASSERT_EQ(27, rectangle_room_random_location(rob2));
    }

    TEST_F(rooms_test, test_rect_room_random_large) {
        srand(time(NULL));
        Robot rob1(create_rectangle_room(21, 17), rand() % 21, rand() % 17);
        Robot rob2(create_rectangle_room(84, 53), rand() % 84, rand() % 53);
        Robot rob3(create_rectangle_room(65, 92), rand() % 65, rand() % 92);
        ASSERT_EQ(357, rectangle_room_random_location(rob1));
        ASSERT_EQ(4452, rectangle_room_random_location(rob2));
        ASSERT_EQ(5980, rectangle_room_random_location(rob3));
    }

    TEST_F(rooms_test, test_irregular_room_random_location_triangle) {
        srand(time(NULL));
        Robot rob1(create_room_type_1(3), start_x, start_y);
        Robot rob2(create_room_type_1(5), start_x, start_y);
        Robot rob3(create_room_type_1(9), start_x, start_y);
        Robot rob4(create_room_type_1(19), start_x, start_y);
        Robot rob5(create_room_type_1(46), start_x, start_y);
        ASSERT_EQ(6, irregular_room_random_location(rob1));
        ASSERT_EQ(15, irregular_room_random_location(rob2));
        ASSERT_EQ(45, irregular_room_random_location(rob3));
        ASSERT_EQ(190, irregular_room_random_location(rob4));
        ASSERT_EQ(1081, irregular_room_random_location(rob5));
    }

    TEST_F(rooms_test, test_irregular_room_random_location_L_shape) {
        srand(time(NULL));
        Robot rob1(create_room_type_2(5, 5, 2, 2), start_x, start_y);
        Robot rob2(create_room_type_2(5, 5, 3, 2), start_x, start_y);
        Robot rob3(create_room_type_2(10, 7, 4, 6), start_x, start_y);
        Robot rob4(create_room_type_2(23, 57, 12, 13), start_x, start_y);
        ASSERT_EQ(16, irregular_room_random_location(rob1));
        ASSERT_EQ(19, irregular_room_random_location(rob2));
        ASSERT_EQ(64, irregular_room_random_location(rob3));
        ASSERT_EQ(827, irregular_room_random_location(rob4));
    }

    TEST_F(rooms_test, test_irregular_room_random_location_hollow_square) {
        srand(time(NULL));
        Robot rob1(create_room_type_3(4, 2), start_x, start_y);
        Robot rob2(create_room_type_3(10, 6), start_x, start_y);
        Robot rob3(create_room_type_3(17, 3), start_x, start_y);
        Robot rob4(create_room_type_3(70, 44), start_x, start_y);
        ASSERT_EQ(12, irregular_room_random_location(rob1));
        ASSERT_EQ(64, irregular_room_random_location(rob2));
        ASSERT_EQ(280, irregular_room_random_location(rob3));
        ASSERT_EQ(2964, irregular_room_random_location(rob4));
    }

    TEST_F(rooms_test, test_irregular_room_random_location_random_room) {
        srand(time(NULL));
        int32_t size = 10 + (rand() % 100);
        Robot rob1(create_room_type_4(size), start_x, start_y);
        ASSERT_EQ(size, irregular_room_random_location(rob1));
        size += rand() % 250;
        Robot rob2(create_room_type_4(size), start_x, start_y);
        ASSERT_EQ(size, irregular_room_random_location(rob2));
        size += 2500;
        Robot rob3(create_room_type_4(size), start_x, start_y);
        ASSERT_EQ(size, irregular_room_random_location(rob3));
    }

}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
