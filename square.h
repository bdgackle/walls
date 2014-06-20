#ifndef SQUARE_H
#define SQUARE_H

namespace walls{

class Square
{
 public:
    Square();
    virtual ~Square() {}

    void setNorth(Square* north) { m_north = north; }
    void setSouth(Square* south) { m_south = south; }
    void setEast(Square* east) { m_east = east; }
    void setWest(Square* west) { m_west = west; }
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    void setWall(bool wall) { m_is_wall = wall; }
    void setOutside(bool outside) { m_is_outside = outside; }

    Square* getNorth() const { return m_north; }
    Square* getSouth() const { return m_south; }
    Square* getEast() const { return m_east; }
    Square* getWest() const { return m_west; }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    bool isWall() const { return m_is_wall; }
    bool isOutside() const { return m_is_outside; }

    bool checkNeighbors();

 private:
    Square* m_north;
    Square* m_south;
    Square* m_east;
    Square* m_west;

    int m_x;
    int m_y;

    bool m_is_wall;
    bool m_is_outside;
};

} // walls

#endif // SQUARE_H
