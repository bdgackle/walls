/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

#ifndef BOARD_H
#define BOARD_H

// Internal Headers
#include "block.h"

namespace walls{

class WallMap;

class World
{
 public:
    static const int PLAYER_NORTH      =   1;
    static const int PLAYER_SOUTH      =   2;
    static const int PLAYER_EAST       =   3;
    static const int PLAYER_WEST       =   4;
    static const int CURSOR_NORTH      =   5;
    static const int CURSOR_SOUTH      =   6;
    static const int CURSOR_EAST       =   7;
    static const int CURSOR_WEST       =   8;
    static const int CURSOR_OFF        =   9;
    static const int CURSOR_ON         =  10;
    static const int WALL_ADD          =  11;
    static const int WALL_REMOVE       =  12;

    World(int width, int height);
    virtual ~World();

    int getHeight() const { return m_height; }
    int getWidth() const { return m_width; }
    Block* getBlock(int x, int y) { return m_blocks[getIndex(x, y)]; }
    bool isCursor() const { return m_cursor_active; }

    void updateModel(int input);

 protected:
    int getIndex(int x, int y) { return x + y * m_width; }

    void movePlayer(int delta_x, int delta_y);
    void moveCursor(int delta_x, int delta_y);
    void wallAdd();
    void wallRemove();
    void setCursor(bool c);

 private:
    Block** m_blocks;
    int m_width;
    int m_height;

    int m_player_x;
    int m_player_y;
    int m_cursor_x;
    int m_cursor_y;

    bool m_cursor_active;

};

} // walls

#endif // BOARD_H
