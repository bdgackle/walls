#include "board.h"
#include "square.h"
#include "wall_map.h"

namespace walls{

Board::Board(int width, int height) :
m_squares(NULL),
m_width(width),
m_height(height)
{
    m_squares = new Square*[width][height];

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < width; y++)
        {
            m_squares[x][y] = new Square;
        }
    }

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (x > 0)
                m_squares[x][y]->setWest(m_squares[x - 1][y]);
            if (x < width - 1)
                m_squares[x][y]->setEast(m_squares[i + 1][y]);
            if (y > 0)
                m_squares[x][y]->setNorth(m_squares[x][y - 1]);
            if (y < height - 1)
                m_squares[x][y]->setSouth(m_squares[x][y + 1]);
        }
    }
}

Board::~Board()
{
    for (int x = 0; x < width; x++)
    for (int y = 0; y < height; y++)
    {
        if (m_squares[x][y] != NULL)
            delete m_squares[x][y];
    }

    if (m_squares != NULL)
        delete m_squares;
}

void Board::setWalls(const WallMap& map)
{
    for (int x = 0; x < width; x++)
    for (int y = 0; y < width; y++)
    {
        m_squares[x][y] = map.isWall(x,y);
    }
}

bool Board::scan()
{
    bool changed = false;

    for (int x = 0; x < width; x++)
    for (int y = 0; y < height; y++)
    {
        if (m_squares[x][y]->checkNeighbors() )
        {
            m_squares[x][y]->setOutside(true);
            changed = true;
        }
    }

    return changed;
}

} // walls
