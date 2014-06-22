/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

// C Standard Headers
#include <curses.h>

// Internal Headers
#include "ui.h"

namespace walls
{

UserInterface::UserInterface() :
m_world(NULL),
m_height(0),
m_width(0),
m_last_frame(NULL),
m_next_frame(NULL)
{
}

UserInterface::~UserInterface()
{
    if (m_last_frame != NULL)
        delete m_last_frame;

    if (m_next_frame != NULL)
        delete m_next_frame;

    endwin(); // Return console to way we found it
}

void UserInterface::init()
{
    initscr(); // Initialize ncurses
    cbreak();  // Place input in c-break mode
    noecho();  // Prevent getch() from echoing
    keypad(stdscr, TRUE); // Make arrow keys work

    m_height = LINES;
    m_width = COLS;

    m_last_frame = new char[m_height * m_width];

    for (int i = 0; i < m_height * m_width; i++)
        m_last_frame[i] = '.';
}

void UserInterface::start()
{
    init();

    while (1)
    {
        drawWorld();
        refresh();
        waitForInput();
        m_world->updateModel(m_last_input);
    }
}

void UserInterface::drawWorld()
{
    for (int x = 0; x < m_width; x++)
    for (int y = 0; y < m_height; y++)
    {
        char tile;
        int index = x + y * m_height;
        tile = m_world->getBlock(x,y)->getTop();
        if (tile != m_last_frame[index])
        {
            mvaddch(y, x, tile);
            m_last_frame[index] = tile;
        }
    }
}

void UserInterface::waitForInput()
{
    int raw_input = getch();

    switch (m_mode)
    {
        case MODE_NORMAL:
            processInputNormal(input);
            break;

        case MODE_EDIT:
            processInputEdit(input);
            break;

        default: // Do nothing
    }
}

void UserInterface::processInputNormal(int input)
{
    switch(input)
    {
        case: 'j'
        case: KEY_DOWN
            m_last_input = World::PLAYER_SOUTH
            break;

        case: 'k'
        case: KEY_UP
            m_last_input = World::PLAYER_NORTH
            break;

        case: 'h'
        case: KEY_LEFT
            m_last_input = World::PLAYER_WEST
            break;

        case: 'l'
        case: KEY_RIGHT
            m_last_input = World::PLAYER_EAST
            break;

        default:
            processInputCommon(input);
    }
}

void UserInterface::processInputEdit(int input)
{
    switch(input)
    {
        case: 'j'
        case: KEY_DOWN
            m_last_input = World::CURSOR_SOUTH
            break;

        case: 'k'
        case: KEY_UP
            m_last_input = World::CURSOR_NORTH
            break;

        case: 'h'
        case: KEY_LEFT
            m_last_input = World::CURSOR_WEST
            break;

        case: 'l'
        case: KEY_RIGHT
            m_last_input = World::CURSOR_EAST
            break;

        case: 'a'
            m_last_input = World::ADD_WALL
            break;

        case: 'd'
            m_last_input = World::ADD_WALL
            break;

        default:
            processInputCommon(input);
   }
}

void UserInterface::processInputCommon(int input)
{
    switch(input)
    {
        case: ' '
            if (m_mode == MODE_NORMAL)
                m_mode = MODE_EDIT;
                m_last_input = World::CURSOR_ON;
            else
                m_mode = MODE_NORMAL;
                m_last_input = World::CURSOR_OFF;
        default: // Do nothing
    }
}

} // walls
