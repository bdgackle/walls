/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

#ifndef BOARD_H
#define BOARD_H

// C Standard Headers
#include <stddef.h>

// Internal Headers
#include "square.h"

namespace walls{

class WallMap;

class Board
{
 public:
    Board(size_t width, size_t height);
    virtual ~Board();

    size_t getHeight() const { return m_height; }
    size_t getWidth() const { return m_width; }
    bool isWall(size_t x, size_t y) const
        { return getSquare(x,y)->isWall(); }
    bool isOutside(size_t x, size_t y) const 
        { return getSquare(x,y)->isOutside(); }

    void setWalls(const WallMap& map);
    bool scan();

 private:
    size_t getIndex(size_t x, size_t y) const 
        { return x + y * m_width; }
    Square* getSquare(size_t x, size_t y) const 
        { return m_squares[getIndex(x, y)]; }
    Square** m_squares;
    size_t m_width;
    size_t m_height;
};

} // walls

#endif // BOARD_H
