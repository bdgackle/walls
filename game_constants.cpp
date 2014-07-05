/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

// C++ Standard Headers
#include <string>

// External Headers
#include <ncurses.h>

using std::string;

namespace walls{

// Mapping of display character types to actual display characters
const char INVALID_CHAR    = 'B';
const char NOT_ON_MAP_CHAR = '0';
const char PLAYER_CHAR     = '@';
const char GROUND_CHAR     = ' ';
const char WALL_CHAR       = 'X';
const char DOOR_CHAR       = '=';
const char FLOOR_CHAR      = '.';

// Value of display strings
const string PLAYER_STATUS_HAPPY_STRING = "Little guy is happy.";
const string PLAYER_STATUS_VENGEFUL_STRING = "Little guy is alone and scared.";
const string PLAYER_STATUS_NONE_STRING = "";

} // walls
