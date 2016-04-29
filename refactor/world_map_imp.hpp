/**
 *  @file world_map_imp.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 9 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of class WorldMapImp
 */

#ifndef WORLD_MAP_IMP_HPP
#define WORLD_MAP_IMP_HPP

// Local Headers
#include "terrain_type.hpp"
#include "unit_types.hpp"
#include "world_map.hpp"

namespace walls {
class MapLocation;
class MapSlice;

class WorldMapImp : public WorldMap {
 public:
    WorldMapImp(MapCoordinate height,
                MapCoordinate width,
                MapCoordinate depth);

    /** Gets the terrain type at a given location */
    TerrainType terrain_type(const MapLocation& loc) const;

    /** Set the terrain type at a given location */
    void terrain_type(const MapLocation& loc, TerrainType type);

    /** Retrieves a slice of the map */
    const MapSlice& slice(const MapLocation& loc,
                          MapDelta width,
                          MapDelta height) const;

    MapCoordinate height() const;
    MapCoordinate width() const;
    MapCoordinate depth() const;

 private:
    const MapCoordinate m_height;
    const MapCoordinate m_width;
    const MapCoordinate m_depth;

}; // class WorldMapImp

} // namespace walls

#endif // WORLD_MAP_IMP_HPP
