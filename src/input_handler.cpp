/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

// External Headers
#include <curses.h>

// Local Headers
#include "input_handler.hpp"
#include "game_constants.hpp"

namespace walls {

InputHandler::InputHandler() :
    m_mode(NORMAL),
    m_cursor_x(0),
    m_cursor_y(0),
    m_screen_width(0),
    m_screen_height(0) {}

InputHandler::~InputHandler() {}

void InputHandler::init(int width, int height, int curs_x, int curs_y)
{
    m_screen_width = width;
    m_screen_height = height;
    moveCursor(curs_x, curs_y);
}

Command InputHandler::getInput()
{
    int raw_input = getch();
    Command command;

    switch (m_mode) {
    case EDIT:
        command = processInputEdit(raw_input);
        break;

    default:
        command = processInputNormal(raw_input);
    }

    return command;
}

int InputHandler::getCursorX() const
{
    return m_cursor_x;
}

int InputHandler::getCursorY() const
{
    return m_cursor_y;
}

bool InputHandler::getCursorVisible() const
{
    if (m_mode == EDIT)
        return true;
    else
        return false;
}

Command InputHandler::processInputNormal(int input)
{
    switch(input) {
    case DOWN_1:
    case DOWN_2:
        return PLAYER_SOUTH;

    case UP_1:
    case UP_2:
        return PLAYER_NORTH;

    case LEFT_1:
    case LEFT_2:
        return PLAYER_WEST;

    case RIGHT_1:
    case RIGHT_2:
        return PLAYER_EAST;

    default:
        return processInputCommon(input);
    }
}

Command InputHandler::processInputEdit(int input)
{
    switch(input) {
    case DOWN_1:
    case DOWN_2:
        moveCursor(0, 1);
        return NO_COMMAND;

    case UP_1:
    case UP_2:
        moveCursor(0, -1);
        return NO_COMMAND;

    case LEFT_1:
    case LEFT_2:
        moveCursor(-1, 0);
        return NO_COMMAND;

    case RIGHT_1:
    case RIGHT_2:
        moveCursor(1, 0);
        return NO_COMMAND;

    case INCREASE_DEPTH:
        return CAMERA_DOWN;

    case DECREASE_DEPTH:
        return CAMERA_UP;

    case WALL_1:
    case WALL_2:
        return ADD_WALL;

    case DOOR_1:
    case DOOR_2:
        return ADD_DOOR;

    case GROUND_1:
    case GROUND_2:
        return ADD_GROUND;

    default:
        return processInputCommon(input);
   }
}

Command InputHandler::processInputCommon(int input)
{
    switch(input) {
    case MODE_TOGGLE_1:
    case MODE_TOGGLE_2:
        if (m_mode == NORMAL) {
            m_mode = EDIT;
            return NO_COMMAND;
        }
        else {
            m_mode = NORMAL;
            return NO_COMMAND;
        }
    case WAIT_1:
        return WAIT;
    default:
        return NO_COMMAND;
    }
}

void InputHandler::moveCursor(int delta_x, int delta_y)
{
    m_cursor_x += delta_x;
    m_cursor_y += delta_y;

    if (m_cursor_x >= m_screen_width)
        m_cursor_x = m_screen_width;
    else if (m_cursor_x < 0)
        m_cursor_x = 0;

    if (m_cursor_y >= m_screen_height)
        m_cursor_y = m_screen_height;
    else if (m_cursor_y < 0)
        m_cursor_y = 0;
}

} // namespace walls
