/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

// C++ Standard Headers
#include <string>

using std::string;

namespace walls{

enum BlockType {
    NOT_ON_MAP,
    GROUND,
    ROCK,
    SAPLING,
    WALL,
    DOOR,
    FLOOR,
    SLOPE
};

enum PlayerStatus {
    NONE,
    HAPPY,
    VENGEFUL,
    SMELLS_FERRET,
    INVADE_FERRET
};

enum Command {
    NO_COMMAND,
    PLAYER_NORTH,
    PLAYER_SOUTH,
    PLAYER_EAST,
    PLAYER_WEST,
    CAMERA_UP,
    CAMERA_DOWN,
    ADD_WALL,
    ADD_GROUND,
    ADD_DOOR,
    ADD_SLOPE,
    ADD_GRASS,
};

// Display Characters
extern const char INVALID_CHAR;
extern const char PLAYER_CHAR;
extern const char NOT_ON_MAP_CHAR;
extern const char GROUND_CHAR;
extern const char ROCK_CHAR;
extern const char SAPLING_CHAR;
extern const char WALL_CHAR;
extern const char DOOR_CHAR;
extern const char FLOOR_CHAR;
extern const char SLOPE_UP_CHAR;
extern const char SLOPE_DOWN_CHAR;

// Display Colors
extern const char INVALID_COLOR;
extern const char PLAYER_COLOR;
extern const char NOT_ON_MAP_COLOR;
extern const char GROUND_COLOR;
extern const char ROCK_COLOR;
extern const char SAPLING_COLOR;
extern const char WALL_COLOR;
extern const char DOOR_COLOR;
extern const char FLOOR_COLOR;
extern const char SLOPE_UP_COLOR;
extern const char SLOPE_DOWN_COLOR;

// Display Strings
extern const string PLAYER_STATUS_NONE_STRING;
extern const string PLAYER_STATUS_HAPPY_STRING;
extern const string PLAYER_STATUS_VENGEFUL_STRING;
extern const string PLAYER_STATUS_SMELLS_FERRET_STRING;
extern const string PLAYER_STATUS_INVADE_FERRET_STRING;

// Input Keys
// These need to be #defines because I need literal constants for case labels
#define DOWN_1          'j'
#define DOWN_2          KEY_DOWN
#define UP_1            'k'
#define UP_2            KEY_UP
#define LEFT_1          'h'
#define LEFT_2          KEY_LEFT
#define RIGHT_1         'l'
#define RIGHT_2         KEY_RIGHT
#define INCREASE_DEPTH  '>'
#define DECREASE_DEPTH  '<'
#define DOOR_1          'd'
#define DOOR_2          'D'
#define GROUND_1        's'
#define GROUND_2        'S'
#define WATER_1         'w'
#define WATER_2         'W'
#define GRASS           'g'
#define SLOPE           'G'
#define WALL_1          'f'
#define WALL_2          'F'
#define MODE_TOGGLE_1   ' '
#define MODE_TOGGLE_2   'a'

} // walls

#endif // GAME_CONSTANTS_H
