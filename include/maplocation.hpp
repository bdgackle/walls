/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef MAPLOCATION_HPP
#define MAPLOCATION_HPP

namespace walls{

/**
 *  This class encapsulates a cartesian coordiante system.  Note that it will
 *  return values that are geometrically correct, but not guaranteed to exist.
 *  It is the responsibility of the caller to verify that the coordinates
 *  actually exist in the world that they refer to.
 */
class MapLocation {
 public:
    MapLocation();
    MapLocation(int x, int y, int z);
    MapLocation(const MapLocation& other);
    virtual ~MapLocation();
    MapLocation& operator= (const MapLocation& other);

    MapLocation getRelative(int x, int y, int z) const;
    static int getRelativeIndex(int index, int x, int y, int z);
    static void setDimensions(int width, int height, int depth);

    int getIndex() const;

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

    static int m_map_height;
    static int m_map_width;
    static int m_map_depth;
};

bool operator== (const MapLocation& lh, const MapLocation& rh);

} // walls

#endif // MAPLOCATION_HPP
