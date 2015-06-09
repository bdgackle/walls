/**
 *  @author Barry Gackle
 *  @author 28 June 2014
 */

// C Standard Headers
#include <stdio.h>

// Internal Headers
#include "maplocation.hpp"

namespace walls {

MapLocation::MapLocation() :
    m_x(0),
    m_y(0),
    m_z(0) {}

MapLocation::MapLocation(int x, int y, int z) :
    m_x(x),
    m_y(y),
    m_z(z) {}

MapLocation::MapLocation(const MapLocation& other) :
    m_x(other.getX()),
    m_y(other.getY()),
    m_z(other.getZ()) {}

MapLocation::~MapLocation() {}

MapLocation& MapLocation::operator= (const MapLocation& other)
{
    m_x = other.getX();
    m_y = other.getY();
    m_z = other.getZ();
    return *this;
}

bool operator== (const MapLocation& lh, const MapLocation& rh)
{
    if ((lh.getX() == rh.getX()) &&
        (lh.getY() == rh.getY()) &&
        (lh.getZ() == rh.getZ())) {
        return true;
    }
    else {
        return false;
    }
}

MapLocation MapLocation::getRelative(int x, int y, int z) const
{
    return MapLocation(getX() + x, getY() + y, getZ() + z);
}

int MapLocation::getRelativeIndex(int index, int x, int y, int z)
{
    return index + x + y * m_map_width + z * m_map_width * m_map_height;
}

void MapLocation::setDimensions(int width, int height, int depth)
{
    m_map_width = width;
    m_map_height = height;
    m_map_depth = depth;
}

int MapLocation::getIndex() const
{
    return m_x + m_y * m_map_width + m_z * m_map_height * m_map_width;
}

int MapLocation::getDistanceX(const MapLocation& location) const
{
    return location.getX() - m_x;
}

int MapLocation::getDistanceY(const MapLocation& location) const
{
    return location.getY() - m_y;
}

int MapLocation::getDistanceZ(const MapLocation& location) const
{
    return location.getZ() - m_z;
}

int MapLocation::getX() const { return m_x; }

int MapLocation::getY() const { return m_y; }

int MapLocation::getZ() const { return m_z; }

int MapLocation::m_map_width = 0;
int MapLocation::m_map_height = 0;
int MapLocation::m_map_depth = 0;

} // walls
