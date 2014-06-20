/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// C Standard Headers
#include <stddef.h>
#include <string.h>

// C++ Standard Headers
#include <stdexcept>

// Internal Headers
#include "wall_map.h"

namespace walls{

WallMap::WallMap(size_t height, size_t width) :
m_height(height),
m_width(width)
{
    if (m_height > M_SIZE_MAX)
        m_height = M_SIZE_MAX;

    if (m_width > M_SIZE_MAX)
        m_width = M_SIZE_MAX;

    m_map = new char[height * width];
    for (int i = 0; i < height * width; i ++)
        m_map[i] = '.';
}

WallMap::~WallMap()
{
    if (m_map != NULL)
        delete m_map;
}

void WallMap::setWall(const char * in)
{
    if (strlen(in) == m_height * m_width)
        memcpy(m_map, in, m_height * m_width);
    else
        throw std::runtime_error("Bad wall map input");
}

bool WallMap::isWall(size_t x, size_t y) const
{
        return (getWall(x,y) == M_WALL);
}

char WallMap::getWall(size_t x, size_t y) const
{
    if ((x < m_width) && (y < m_height))
        return (m_map[ y * m_width + x]);
    else
        return M_OUT_OF_BOUNDS;
}

} // walls
