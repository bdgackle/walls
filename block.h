/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef BLOCK_H
#define BLOCK_H

namespace walls{

class Block
{
 public:
    Block();
    virtual ~Block() {}

    void setNorth(Block* north) { m_north = north; }
    void setSouth(Block* south) { m_south = south; }
    void setEast(Block* east) { m_east = east; }
    void setWest(Block* west) { m_west = west; }
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    void setType(int type) { m_type = type; }
    void setHasPlayer(bool p) { m_has_player p; }
    void setHasCursor(bool c) { m_has_cursor c; }

    Block* getNorth() const { return m_north; }
    Block* getSouth() const { return m_south; }
    Block* getEast() const { return m_east; }
    Block* getWest() const { return m_west; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getType() const { return m_type; }

    char getTop();

 private:
    Block* m_north;
    Block* m_south;
    Block* m_east;
    Block* m_west;

    int m_x;
    int m_y;

    char m_type;

    bool m_has_player;
    bool m_has_cursor;

    static const char WALL = 'X';
    static const char GROUND = '.';
    static const char CURSOR = '_';
    static const char PLAYER = '@';
};

} // walls

#endif // BLOCK_H
