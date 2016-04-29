/**
 *  @file map_slice.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of class MapSlice
 */

#ifndef MAP_SLICE_HPP
#define MAP_SLICE_HPP

// Local Headers
#include "terrain_type.hpp"
#include "unit_types.hpp"

namespace walls {
class MapLocation;

/** Public interface to two dimensional map portion */
class MapSlice {
 public:
    /** Gets world map location of north west corner */
    virtual const MapLocation& world_location() const = 0;

    /** Gets the  east-west size of slice in voxels */
    virtual MapDelta width() const = 0;

    /** Gets the north-west size of slice in voxels */
    virtual MapDelta height() const = 0;

    /**
     *  Gets the terrain type of a single voxel by coordinates, expressed as a
     *  delta from the slice's world coordinates
     */
    virtual TerrainType terrain_type(MapDelta x, MapDelta y) const = 0;
}; // class MapSlice

} // namespace walls

#endif // MAP_SLICE_HPP
