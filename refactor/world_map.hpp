/**
 *  @file world_map.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of class WorldMap
 */

#ifndef WORLD_MAP_HPP
#define WORLD_MAP_HPP

// Local Headers
#include "terrain_type.hpp"
#include "unit_types.hpp"

namespace walls {
class MapLocation;
class MapSlice;

class WorldMap {
 public:
    /** Gets the terrain type at a given location */
    virtual TerrainType terrain_type(const MapLocation& loc) const = 0;

    /** Set the terrain type at a given location */
    virtual void terrain_type(const MapLocation& loc, TerrainType type) = 0;

    /** Retrieves a slice of the map */
    virtual const MapSlice& slice(const MapLocation& loc,
                                  MapDelta width,
                                  MapDelta height) const = 0;

    virtual MapCoordinate height() const = 0;
    virtual MapCoordinate width() const = 0;
    virtual MapCoordinate depth() const = 0;
}; // class WorldMap

} // namespace walls

#endif // WORLD_MAP_HPP
