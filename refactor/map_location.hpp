/**
 *  @file map_location.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of class MapLocation
 */

#ifndef MAP_LOCATION_HPP
#define MAP_LOCATION_HPP

// Local Headers
#include "unit_types.hpp"

namespace walls {

/** Public interface to represention of single map point */
class MapLocation {
 public:
    virtual MapCoordinate x() const = 0;
    virtual MapCoordinate y() const = 0;
    virtual MapCoordinate z() const = 0;
}; // class MapLocation

} // namespace walls

#endif // MAP_LOCATION_HPP
