/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

// External Headers
#include <curses.h>

// Internal Headers
#include "ui.h"
#include "game_constants.h"
#include "world.h"
#include "display.h"
#include "input_handler.h"

namespace walls {

UserInterface::UserInterface() :
    m_depth(0) {}

UserInterface::~UserInterface() {}

void UserInterface::start(World *world, const MapLocation& initial_location)
{
    m_world = world;
    init(initial_location);

    while (1) {
        m_display.drawWorld();
        m_display.drawStatus();
        m_display.drawPlayer();
        m_display.drawCreatures();
        m_display.drawCursor(m_input.getCursorX(),
                             m_input.getCursorY(),
                             m_input.getCursorVisible());

        int command_x = m_input.getCursorX() + m_display.getUpperLeft().getX();
        int command_y = m_input.getCursorY() + m_display.getUpperLeft().getY();

        MapLocation location(command_x, command_y, getDepth());

        world->doCommand(m_input.getInput(), location);
    }
}

void UserInterface::init(const MapLocation& initial_location)
{
    initscr();            // Initialize ncurses
    cbreak();             // Place input in c-break mode
    noecho();             // Prevent getch() from echoing
    keypad(stdscr, TRUE); // Make arrow keys work

    m_display.init(m_world, initial_location, COLS, LINES);
    m_input.init(COLS, LINES, 0, 2);
}

int UserInterface::getDepth()
{
    return m_depth;
}

} // walls
