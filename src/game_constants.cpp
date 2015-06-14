/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

// External Headers
#include <ncurses.h>

// C++ Standard Headers
#include <string>

using std::string;

// Since we've wrapped these constants in a namespace, we'll need to explicitly
// declare external linkage to keep them visible outside this file.
namespace walls {

// Mapping of display character types to actual display characters
extern const char INVALID_CHAR          = 'B';
extern const char PLAYER_CHAR           = '@';
extern const char NOT_ON_MAP_CHAR       = '0';
extern const char GROUND_CHAR           = ' ';
extern const char ROCK_CHAR             = 'o';
extern const char SAPLING_CHAR          = '|';
extern const char WALL_CHAR             = 'X';
extern const char DOOR_CHAR             = '=';
extern const char FLOOR_CHAR            = '.';

// Mapping of colors to color integer codes
extern const int INVALID_COLOR          = COLOR_PAIR(8);
extern const int PLAYER_COLOR           = COLOR_PAIR(8);
extern const int NOT_ON_MAP_COLOR       = COLOR_PAIR(8);
extern const int GROUND_COLOR           = COLOR_PAIR(8);
extern const int ROCK_COLOR             = COLOR_PAIR(5);
extern const int SAPLING_COLOR          = COLOR_PAIR(8);
extern const int WALL_COLOR             = COLOR_PAIR(8);
extern const int DOOR_COLOR             = COLOR_PAIR(8);
extern const int FLOOR_COLOR            = COLOR_PAIR(8);

// Value of display strings
extern const string PLAYER_STATUS_NONE_STRING =
    "                                                    ";
extern const string PLAYER_STATUS_HAPPY_STRING =
    "Little guy is happy.                                ";
extern const string PLAYER_STATUS_VENGEFUL_STRING =
    "Little guy is alone and scared.                     ";
extern const string PLAYER_STATUS_SMELLS_FERRET_STRING =
    "Little guy smells ferrets.  They are wafting.       ";
extern const string PLAYER_STATUS_INVADE_FERRET_STRING =
    "FERRETS IN HOUSE! FERRETS IN HOUSE! Ferrets are bad.";
} // namespace walls
