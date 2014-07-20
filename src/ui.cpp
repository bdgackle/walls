/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

// C++ Headers
#include <string>

// External Headers
#include <curses.h>

// Internal Headers
#include "ui.h"
#include "game_constants.h"
#include "world.h"
#include "display.h"
#include "input_handler.h"
#include "block.h"

using std::string;

namespace walls {

UserInterface::UserInterface(World* world) :
    m_world(world),
    m_display_upper_left(0,0,0) {}

UserInterface::~UserInterface()
{
    endwin(); // Undo all ncurses console configuration
}

void UserInterface::start()
{
    centerPlayer();

    while (1) {
        m_display.draw(*m_world,
                       m_display_upper_left,
                       m_input.getCursorX(),
                       m_input.getCursorY(),
                       m_input.getCursorVisible());

        doCommand(m_input.getInput());
    }
}

void UserInterface::doCommand(Command command)
{
    switch(command) {
    case PLAYER_NORTH:
        m_world->getPlayer()->move(0, -1, 0);
        adjustPlayer();
        break;

    case PLAYER_SOUTH:
        m_world->getPlayer()->move(0, 1, 0);
        adjustPlayer();
        break;

    case PLAYER_WEST:
        m_world->getPlayer()->move(-1, 0, 0);
        adjustPlayer();
        break;

    case PLAYER_EAST:
        m_world->getPlayer()->move(1, 0, 0);
        adjustPlayer();
        break;

    case CAMERA_UP:
        m_display_upper_left = m_display_upper_left.getRelative(0, 0, -1);
        break;

    case CAMERA_DOWN:
        m_display_upper_left = m_display_upper_left.getRelative(0, 0, 1);
        break;

    case ADD_WALL:
        m_world->getMap()->getBlock(getCursorLocation())->setType(WALL);
        m_world->setBoundriesDirty();
        break;

    case ADD_GROUND:
        m_world->getMap()->getBlock(getCursorLocation())->setType(GROUND);
        m_world->setBoundriesDirty();
        break;

    case ADD_DOOR:
        m_world->getMap()->getBlock(getCursorLocation())->setType(DOOR);
        m_world->setBoundriesDirty();
        break;

    case WAIT:
        // Do nothing, but world still gets updated
        break;
    }

    if (command != NO_COMMAND) 
        m_world->update(1);
}

void UserInterface::centerPlayer()
{
    MapLocation player_loc = m_world->getPlayer()->getLocation();

    m_display_upper_left = player_loc.getRelative(-m_display.getCenterX(),
                                                  -m_display.getCenterY(),
                                                  0);
}

void UserInterface::adjustPlayer()
{
    MapLocation loc = m_world->getPlayer()->getLocation();

    int move_x = 0;
    int move_y = 0;

    int min_x = (m_display.getWidth() / 4);
    int max_x = (m_display.getWidth() / 4) + m_display.getCenterX();
    int min_y = (m_display.getHeight() / 4);
    int max_y = (m_display.getHeight() / 4) + m_display.getCenterY();

    int player_x = m_display_upper_left.getDistanceX(loc);
    int player_y = m_display_upper_left.getDistanceY(loc);

    if (player_x < min_x)
        move_x = player_x - min_x;
    else if (player_x > max_x)
        move_x = player_x - max_x;

    if (player_y < min_y)
        move_y = player_y - min_y;
    else if (player_y > max_y)
        move_y = player_y - max_y;

    m_display_upper_left = m_display_upper_left.getRelative(move_x, move_y, 0);
}

void UserInterface::init()
{
    initscr();            // Initialize ncurses
    start_color();        // Use color
    cbreak();             // Place input in c-break mode
    noecho();             // Prevent getch() from echoing
    keypad(stdscr, TRUE); // Make arrow keys work

    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_YELLOW, COLOR_RED);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    
    m_display.setDimensions(COLS, LINES);
    m_input.init(COLS, LINES, 0, 2);

    centerPlayer();
}

int UserInterface::getDepth() const
{
    return m_display_upper_left.getZ();
}

MapLocation UserInterface::getCursorLocation() const
{
    int command_x = m_input.getCursorX() + m_display_upper_left.getX();
    int command_y = m_input.getCursorY() + m_display_upper_left.getY();

    return MapLocation(command_x, command_y, getDepth());
}

} // walls
