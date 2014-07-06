/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef MAPLOCATION_H
#define MAPLOCATION_H

namespace walls{

/**
 *  This class encapsulates a cartesian coordiante system.  Note that it will
 *  return values that are geometrically correct, but not guaranteed to exist.
 *  It is the responsibility of the caller to verify that the coordinates
 *  actually exist in the world that they refer to.
 */
class MapLocation
{
 public:
    MapLocation();
    MapLocation(int x, int y, int z);
    MapLocation(const MapLocation& other);
    virtual ~MapLocation();
    MapLocation& operator= (const MapLocation& other);

    MapLocation getRelative(int x, int y, int z) const;

    MapLocation getN() const;
    MapLocation getS() const;
    MapLocation getE() const;
    MapLocation getW() const;
    MapLocation getU() const;
    MapLocation getD() const;

    bool isNorthOf(const MapLocation& location) const;
    bool isSouthOf(const MapLocation& location) const;
    bool isEastOf(const MapLocation& location) const;
    bool isWestOf(const MapLocation& location) const;
    bool isAbove(const MapLocation& location) const;
    bool isBelow(const MapLocation& location) const;

    bool isInSpace(const MapLocation& upper_nw,
                   const MapLocation& lower_se) const;

    int getIndex(int width, int height, int depth) const;

    int getDistanceX(const MapLocation& location) const;
    int getDistanceY(const MapLocation& location) const;
    int getDistanceZ(const MapLocation& location) const;

    int getX() const;
    int getY() const;
    int getZ() const;
private:

    int m_x;
    int m_y;
    int m_z;
};

} // walls

#endif // MAPLOCATION_H
