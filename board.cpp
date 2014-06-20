/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// C Standard Headers
#include <stddef.h>

// Internal Headers
#include "board.h"
#include "square.h"
#include "wall_map.h"

namespace walls{

Board::Board(size_t width, size_t height) :
m_squares(NULL),
m_width(width),
m_height(height)
{
    m_squares = new Square*[m_height * m_width];

    for (size_t i = 0; i < m_height * m_width; i++)
    {
        m_squares[i] = new Square;
    }

    for (size_t x = 0; x < m_width; x++)
    for (size_t y = 0; y < m_height; y++)
    {
        getSquare(x,y)->setX(x);
        getSquare(x,y)->setY(y);

        if (x > 0)
            getSquare(x,y)->setWest(getSquare(x - 1, y));
        if (x < (width - 1))
            getSquare(x,y)->setEast(getSquare(x + 1, y));
        if (y > 0)
            getSquare(x,y)->setNorth(getSquare(x, y - 1));
        if (y < (height - 1))
            getSquare(x,y)->setSouth(getSquare(x, y + 1));
    }
}

Board::~Board()
{
    for (size_t i = 0; i < m_height * m_width; i++)
    {
        if (m_squares[i] != NULL)
            delete m_squares[i];
    }

    if (m_squares != NULL)
        delete m_squares;
}

void Board::setWalls(const WallMap& map)
{
    for (size_t x = 0; x < m_width; x++)
    for (size_t y = 0; y < m_height; y++)
    {
        getSquare(x,y)->setWall(map.isWall(x,y));
    }
}

bool Board::scan()
{
    bool changed = false;

    for (size_t x = 0; x < m_width; x++)
    for (size_t y = 0; y < m_height; y++)
    {
        if (!(getSquare(x,y)->isWall()) &&
            !(getSquare(x,y)->isOutside()))
        {
            if (getSquare(x,y)->checkNeighbors())
            {
                getSquare(x,y)->setOutside(true);
                changed = true;
            }
        }
    }

    return changed;
}

} // walls
