/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

// C++ Standard Headers
#include <string>

// External Headers
#include <ncurses.h>

using std::string;

// Since we've wrapped these constants in a namespace, we'll need to explicitly
// declare external linkage to keep them visible outside this file.
namespace walls{

// Mapping of display character types to actual display characters
extern const char INVALID_CHAR    = 'B';
extern const char NOT_ON_MAP_CHAR = '0';
extern const char PLAYER_CHAR     = '@';
extern const char GROUND_CHAR     = ' ';
extern const char WALL_CHAR       = 'X';
extern const char DOOR_CHAR       = '=';
extern const char FLOOR_CHAR      = '.';

// Value of display strings
extern const string PLAYER_STATUS_HAPPY_STRING =
    "Little guy is happy.           ";
extern const string PLAYER_STATUS_VENGEFUL_STRING =
    "Little guy is alone and scared.";
extern const string PLAYER_STATUS_NONE_STRING =
    "                               ";

} // walls
