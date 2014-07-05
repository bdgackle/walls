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

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::start(World *world, const MapLocation& start)
{
    m_world = world;
    init(start);

    while (1) {
        m_display.drawWorld();
        m_display.drawStatus();
        m_display.drawPlayer();
        m_display.drawCursor(m_input.getCursorX(),
                             m_input.getCursorY(),
                             m_input.getCursorVisible());

        world->doCommand(m_input.getInput());
    }
}

void UserInterface::init(const MapLocation& start)
{
    initscr();            // Initialize ncurses
    cbreak();             // Place input in c-break mode
    noecho();             // Prevent getch() from echoing
    keypad(stdscr, TRUE); // Make arrow keys work

    m_display.init(m_world, start);

    m_display.setDimensions(COLS, LINES);
    m_input.setDimensions(COLS, LINES);
}

} // walls
