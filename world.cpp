/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Internal Headers
#include "world.h"
#include "block.h"

namespace walls{

World::World(int width, int height) :
m_blocks(NULL),
m_width(width),
m_height(height),
m_player_x(0),
m_player_y(0),
m_cursor_x(0),
m_cursor_y(0),
is_cursor(false)
{
    m_blocks = new Block*[m_height * m_width];

    for (int i = 0; i < m_height * m_width; i++)
    {
        m_blocks[i] = new Block;
    }

    for (int x = 0; x < m_width; x++)
    for (int y = 0; y < m_height; y++)
    {
        Block* block = getBlock(x,y);
        block->setX(x);
        block->setY(y);

        if (x > 0)
            block->setWest(getBlock(x - 1, y));
        if (x < (width - 1))
            block->setEast(getBlock(x + 1, y));
        if (y > 0)
            block->setNorth(getBlock(x, y - 1));
        if (y < (height - 1))
            block->setSouth(getBlock(x, y + 1));
    }
}

World::~World()
{
    for (int i = 0; i < m_height * m_width; i++)
    {
        if (m_blocks[i] != NULL)
            delete m_blocks[i];
    }

    if (m_blocks != NULL)
        delete m_blocks;
}

void World::updateWorld(int input)
{
    switch(input)
    {
        case ACTION:
            action();
            break;

        case PLAYER_NORTH:
            movePlayer(0, -1);
            break;

        case PLAYER_SOUTH:
            movePlayer(0, 1);
            break;

        case PLAYER_WEST:
            playerWest(-1, 0);
            break;

        case PLAYER_EAST:
            movePlayer(1, 0);
            break;

        case CURSOR_NORTH:
            moveCursor(0, -1);
            break;

        case CURSOR_SOUTH:
            moveCursor(0, 1);
            break;

        case CURSOR_WEST:
            moveCursor(-1, 0);
            break;

        case CURSOR_EAST:
            moveCursor(1, 0);
            break;

        case CURSOR_OFF:
            setCursor(false);
            break;

        case CURSOR_ON:
            setCursor(true);
            break;

        case WALL_ADD:
            wallAdd();
            break;

        case WALL_REMOVE:
            wallRemove();
            break;

        default: //Do nothing
    }
}

void movePlayer(int delta_x, int delta_y)
{
        int new_x = m_player_x + delta_x;
        int new_y = m_player_y + delta_y;

        if ((new_x <= 0) || (new_x >= m_width))
            new_x = m_player_x;
        
        if ((new_y <= 0) || (new_y >= m_width))
            new_y = m_player_y;
        
        Block* oldBlock = getBlock(m_player_x, m_player_y);
        Block* newBlock = getBlock(new_x, new_y);

        oldBlock->setHasPlayer(false);
        newBlock->setHasPlayer(true);

        m_player_x = new_x;
        m_player_y = new_y;
}

void moveCursor(int delta_x, int delta_y)
{
        int new_x = m_cursor_x + delta_x;
        int new_y = m_cursor_y + delta_y;

        if ((new_x <= 0) || (new_x >= m_width))
            new_x = m_cursor_x;
        
        if ((new_y <= 0) || (new_y >= m_width))
            new_y = m_cursor_y;
        
        Block* oldBlock = getBlock(m_cursor_x, m_cursor_y);
        Block* newBlock = getBlock(new_x, new_y);

        oldBlock->setHasCursor(false);

        if (m_is_cursor)
            newBlock->setHasCursor(true);

        m_cursor_x = new_x;
        m_cursor_y = new_y;
}

void wallAdd()
{
    block = getBlock(m_cursor_x, m_cursor_y);
    block->setType("X");
}

void wallRemove()
{
    block = getBlock(m_cursor_x, m_cursor_y);
    block->setType(".");
}

void setCursor(bool c)
{
    m_is_cursor = c;

    Block* block = getBlock(m_cursor_x, m_cursor_y);
    block->setHasCursor(c);
}

} // walls
