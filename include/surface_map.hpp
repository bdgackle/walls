/**
 *  @author Barry Gackle
 */

#ifndef SURFACE_MAP_HPP
#define SURFACE_MAP_HPP

// Local Headers
#include "maplocation.hpp"

namespace walls {

class SurfaceMap {
 public:
    SurfaceMap(int width, int height);
    virtual ~SurfaceMap();

    int getSurfaceDepth(const MapLocation& location) const;

    bool isOnSurface(const MapLocation& location) const;
    bool isBelowSurface(const MapLocation& location) const;
    bool isAboveSurface(const MapLocation& location) const;

 protected:
    int getDepth(int width, int height) const;
    int getDepth(int index) const;
    int getIndex(int x, int y) const;

 private:
    int* m_surface;
    int m_width;
    int m_height;
    int m_count;
};


} // namespace walls

#endif // SURFACE_MAP_HPP
