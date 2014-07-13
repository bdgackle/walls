/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

// C++ Standard Headers
#include <string>
#include <vector>

// External Headers
#include <curses.h>

// Internal Headers
#include "display.h"
#include "game_constants.h"
#include "maplocation.h"
#include "map.h"
#include "player.h"
#include "creature.h"
#include "world.h"
#include "block.h"

using std::string;
using std::vector;

namespace walls{

Display::Display() :
    m_width(0),
    m_height(0),
    m_frame(NULL) {}

Display::~Display()
{
    deleteFrame();
}

void Display::draw(const World& world,
                   const MapLocation& upper_left,
                   int curs_x,
                   int curs_y,
                   bool curs_visible)
{
    const Map& map = world.getMap();
    PlayerStatus player_status = world.getPlayer().getStatus();
    MapLocation player_location = world.getPlayer().getLocation();
    const vector<Creature*>& creatures = world.getCreatures();

    drawMap(map, upper_left);
    drawCreatures(creatures, upper_left);
    drawPlayer(player_location, upper_left);
    drawStatus(player_status, world);
    drawCursor(curs_x, curs_y, curs_visible);
}

int Display::getHeight() const
{
    return m_height;
}

int Display::getWidth() const
{
    return m_width;
}

int Display::getCenterX() const
{
    return m_width / 2;
}

int Display::getCenterY() const
{
    return m_height / 2;
}

void Display::setDimensions(int width, int height)
{
    m_width = width;
    m_height = height;
    createFrame();
}

void Display::drawMap(const Map& map, const MapLocation& upper_left)
{
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            MapLocation next = upper_left.getRelative(x, y, 0);
            if (map.exists(next)) {
                const Block& block = map.getBlock(next);
                BlockType type = block.getType();
                drawTile(x, y, getDisplayChar(block.getType()));
            }
            else {
                drawTile(x, y, getDisplayChar(NOT_ON_MAP));
            }
        }
   }
}

void Display::drawStatus(PlayerStatus status, const World& world)
{
    char line_two[40];
    char line_three[40];

    string stat_string = getStatusString(status);
    mvaddstr(0, 0, stat_string.c_str());

    sprintf(line_two, "Time: %d", world.getTime());
    mvaddstr(1, 0, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(1, 0, line_two);

    sprintf(line_three, "Creatures: %d", world.getCreatureCount());
    mvaddstr(2, 0, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(2, 0, line_three);
}

void Display::drawPlayer(const MapLocation& location,
                         const MapLocation& upper_left)
{
    int player_x = upper_left.getDistanceX(location);
    int player_y = upper_left.getDistanceY(location);

    // Make sure player is actually on the screen
    if ((player_x >= 0) && (player_x < m_width) &&
        (player_y >= 0) && (player_y < m_height)) {
        drawTile(player_x, player_y, PLAYER_CHAR);
    }
}

void Display::drawCreatures(const vector<Creature*>& creatures,
                            const MapLocation& upper_left)
{
    for (int i = 0; i < creatures.size(); i++) {
        char c = creatures.at(i)->getDisplayChar();
        MapLocation m = creatures.at(i)->getLocation();

        int creature_x = upper_left.getDistanceX(m);
        int creature_y = upper_left.getDistanceY(m);

        if ((creature_x >= 0) && (creature_x < m_width) &&
            (creature_y >= 0) && (creature_y < m_height)) {
            drawTile(creature_x, creature_y, c);
        }
    }
}

void Display::drawCursor(int curs_x, int curs_y, bool visible)
{
    if (visible) {
        curs_set(1); // Cursor visible
        move(curs_y, curs_x); // Move ncurses cursor to track logical cursor
    } else {
        curs_set(0); // Cursor not visible
    }
}

void Display::drawTile(int x, int y, char tile)
{
    if (tile != m_frame[getIndex(x,y)]) {
        mvaddch(y, x, tile);
        m_frame[getIndex(x,y)] = tile;
    }
}

int Display::getIndex(int x, int y) const
{
    return x + y * m_width;
}

char Display::getDisplayChar(BlockType type)
{
    switch(type) {
        case NOT_ON_MAP:
            return NOT_ON_MAP_CHAR;
            break;

        case GROUND:
            return GROUND_CHAR;
            break;

        case ROCK:
            return ROCK_CHAR;
            break;

        case SAPLING:
            return SAPLING_CHAR;
            break;

        case WALL:
            return WALL_CHAR;
            break;

        case DOOR:
            return DOOR_CHAR;
            break;

        case FLOOR:
            return FLOOR_CHAR;
            break;

        default:
            return INVALID_CHAR;
    }
}

string Display::getStatusString(PlayerStatus status)
{
    switch(status) {
        case HAPPY:
            return PLAYER_STATUS_HAPPY_STRING;
            break;

        case VENGEFUL:
            return PLAYER_STATUS_VENGEFUL_STRING;
            break;

        case SMELLS_FERRET:
            return PLAYER_STATUS_SMELLS_FERRET_STRING;
            break;

        case INVADE_FERRET:
            return PLAYER_STATUS_INVADE_FERRET_STRING;
            break;

        default:
            return PLAYER_STATUS_NONE_STRING;
    }
}

void Display::createFrame()
{
    deleteFrame();
    m_frame = new char[m_width * m_height];
}

void Display::deleteFrame()
{
    if (m_frame != NULL)
        delete [] m_frame;
}

} // walls
