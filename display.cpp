/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

// External Headers
#include <curses.h>
#include <string>

// Internal Headers
#include "display.h"
#include "game_constants.h"
#include "maplocation.h"
#include "world.h"

using std::string;

namespace walls{

Display::Display() :
    m_frame(NULL) {}

Display::~Display()
{
    shutdown();
}

void Display::init(const World* world, const MapLocation& upper_left)
{
    m_world = world;
    m_upper_left = upper_left;
}

void Display::drawWorld()
{
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            setTile(x,y);
        }
    }
}

void Display::drawStatus()
{
    string status_string = getStatusString(m_world->getPlayerStatus());
    const char* cpu = m_world->getCpuTime();
    mvaddstr(0, 0, status_string.c_str());
    mvaddstr(1, 0, cpu);
}

void Display::drawPlayer()
{
    int player_x = m_upper_left.getDistanceX(m_world->getPlayerLocation());
    int player_y = m_upper_left.getDistanceY(m_world->getPlayerLocation());

    // Make sure player is actually on the screen
    if ((player_x >= 0) && (player_y < m_height) &&
        (player_y >= 0) && (player_y < m_height)) {
        drawTile(player_x, player_y, PLAYER_CHAR);
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

void Display::scrollRelative(int south, int east, int down)
{
    m_upper_left = m_upper_left.getRelative(south, east, down);
}

void Display::scrollTo(const MapLocation& upper_left)
{
    m_upper_left = upper_left;
}

int Display::getHeight() const
{
    return m_height;
}

int Display::getWidth() const
{
    return m_width;
}

void Display::setDimensions(int width, int height)
{
    m_width = width;
    m_height = height;
    createFrame();
}

void Display::setTile(int x, int y)
{
    MapLocation current = m_upper_left.getRelative(x, y, 0);
    BlockType type = m_world->getBlockType(current);
    drawTile(x, y, getDisplayChar(type));
}

void Display::drawTile(int x, int y, char tile)
{
    if (tile != m_frame[getIndex(x,y)]) {
        mvaddch(y, x, tile);
        m_frame[getIndex(x,y)] = tile;
    }
}

char Display::getDisplayChar(BlockType type) const
{
    switch(type)
    {
        case NOT_ON_MAP:
            return NOT_ON_MAP_CHAR;
            break;

        case GROUND:
            return GROUND_CHAR;
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

string Display::getStatusString(PlayerStatus status) const
{
    switch(status)
    {
        case HAPPY:
            return PLAYER_STATUS_HAPPY_STRING;
            break;

        case VENGEFUL:
            return PLAYER_STATUS_VENGEFUL_STRING;
            break;

        default:
            return PLAYER_STATUS_NONE_STRING;
    }
}

void Display::shutdown()
{
    deleteFrame();
    endwin(); // Tell ncurses to undo all console configuration
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

int Display::getIndex(int x, int y)
{
    return x + y * m_width;
}

} // walls
