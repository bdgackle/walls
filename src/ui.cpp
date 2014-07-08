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

UserInterface::UserInterface() :
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
    switch(command)
    {
        case PLAYER_NORTH:
            m_world->getPlayer()->move(0, -1, 0);
            centerPlayer();
            break;

        case PLAYER_SOUTH:
            m_world->getPlayer()->move(0, 1, 0);
            centerPlayer();
            break;

        case PLAYER_WEST:
            m_world->getPlayer()->move(-1, 0, 0);
            centerPlayer();
            break;

        case PLAYER_EAST:
            m_world->getPlayer()->move(1, 0, 0);
            centerPlayer();
            break;

        case ADD_WALL:
            m_world->getMap()->getBlock(getCursorLocation())->setType(WALL);
            break;

        case ADD_GROUND:
            m_world->getMap()->getBlock(getCursorLocation())->setType(GROUND);
            break;

        case ADD_DOOR:
            m_world->getMap()->getBlock(getCursorLocation())->setType(DOOR);
            break;
    }

    m_world->update(1);
}

void UserInterface::centerPlayer()
{
    MapLocation player_loc = m_world->getPlayer()->getLocation();

    m_display_upper_left = player_loc.getRelative(-m_display.getCenterX(),
                                                  -m_display.getCenterY(),
                                                  0);
}

void UserInterface::init(World* world)
{
    m_world = world;

    initscr();            // Initialize ncurses
    cbreak();             // Place input in c-break mode
    noecho();             // Prevent getch() from echoing
    keypad(stdscr, TRUE); // Make arrow keys work

    m_display.setDimensions(COLS, LINES);
    m_input.init(COLS, LINES, 0, 2);

    m_display_upper_left = m_display_upper_left.getRelative(0, 1, 0);
}

int UserInterface::getDepth() const { return m_display_upper_left.getZ(); }

MapLocation UserInterface::getCursorLocation() const
{
        int command_x = m_input.getCursorX() + m_display_upper_left.getX();
        int command_y = m_input.getCursorY() + m_display_upper_left.getY();

        return MapLocation(command_x, command_y, getDepth());
}

} // walls
