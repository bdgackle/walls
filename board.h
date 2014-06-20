#ifndef BOARD_H
#define BOARD_H

#include "square.h"

namespace walls{

class WallMap;

class Board
{
 public:
    Board(int width, int height);
    virtual ~Board();

    int getHeight() { return m_height; }
    int getWidth() { return m_width; }

    void setWalls(const WallMap& map);
    bool scan();

 private:
    Square** m_squares;
    int m_width;
    int m_height;
};

} // walls

#endif // BOARD_H
