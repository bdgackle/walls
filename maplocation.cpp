/**
 *  @author Barry Gackle
 *  @author 28 June 2014
 */

// C Standard Headers
#include <stdio.h>

// Internal Headers
#include "maplocation.h"

namespace walls{

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

MapLocation MapLocation::getRelative(int x, int y, int z) const
{
    return MapLocation(getX() + x, getY() + y, getZ() + z);
}

MapLocation MapLocation::getN() const
{
    return getRelative(0, -1, 0);
}

MapLocation MapLocation::getS() const
{
    return getRelative(0, 1, 0);
}

MapLocation MapLocation::getE() const
{
    return getRelative(1, 0, 0);
}

MapLocation MapLocation::getW() const
{
    return getRelative(-1, 0, 0);
}

MapLocation MapLocation::getU() const
{
    return getRelative(0, 0, -1);
}

MapLocation MapLocation::getD() const
{
    return getRelative(0, 0, 1);
}

bool MapLocation::isNorthOf(const MapLocation& location) const
{
    if (getY() < location.getY())
        return true;
    else
        return false;
}

bool MapLocation::isSouthOf(const MapLocation& location) const
{
    if (getY() > location.getY())
        return true;
    else
        return false;
}

bool MapLocation::isEastOf(const MapLocation& location) const
{
    if (getX() > location.getX())
        return true;
    else
        return false;
}

bool MapLocation::isWestOf(const MapLocation& location) const
{
    if (getX() < location.getX())
        return true;
    else
        return false;
}

bool MapLocation::isAbove(const MapLocation& location) const
{
    if (getZ() < location.getZ())
        return true;
    else
        return false;
}

bool MapLocation::isBelow(const MapLocation& location) const
{
    if (getZ() > location.getZ())
        return true;
    else
        return false;
}

bool MapLocation::isInSpace(const MapLocation& upper_nw,
                            const MapLocation& lower_se) const
{
    if ((isNorthOf(upper_nw)) ||
        (isWestOf(upper_nw)) ||
        (isAbove(upper_nw)) ||
        (isSouthOf(lower_se)) ||
        (isEastOf(lower_se)) ||
        (isBelow(lower_se)))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int MapLocation::getIndex(int width, int height, int depth) const
{
    return getX() + getY() * width + getZ() * height * width;
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

int MapLocation::getX() const
{
    return m_x;
}

int MapLocation::getY() const
{
    return m_y;
}

int MapLocation::getZ() const
{
    return m_z;
}

} // walls
