/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

#ifndef WALL_MAP_H
#define WALL_MAP_H

// C Standard Headers
#include <stddef.h>

namespace walls{

class Board;

class WallMap
{
 public:
    WallMap(size_t height, size_t width);
    virtual ~WallMap();

    void setWall(const char * in);

    bool isWall(size_t x, size_t y) const;
    char getWall(size_t x, size_t y) const;
    size_t getHeight() const { return m_height; }
    size_t getWidth() const { return m_width; }
    char getWallChar() const { return M_WALL; }
    size_t getSizeMax() const { return M_SIZE_MAX; }
    char getOutOfBoundsChar() const { return M_OUT_OF_BOUNDS; }

 private:
    char* m_map;
    size_t m_height;
    size_t m_width;

    static const char M_WALL = 'X';
    static const char M_OUT_OF_BOUNDS = '\\';
    static const size_t M_SIZE_MAX = 1000;
};

} // walls

#endif // WALL_MAP_H
