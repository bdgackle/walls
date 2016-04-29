/**
 *  @file world_map_imp.cpp
 *  
 *  @author Barry Gackle
 *  @copyright 9 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains implementation of class WorldMapImp
 */

// Local Headers
#include "terrain_type.hpp"
#include "unit_types.hpp"
#include "world_map_imp.hpp"

namespace walls {
class MapLocation;
class MapSlice;

WorldMapImp::WorldMapImp(MapCoordinate height,
                         MapCoordinate width,
                         MapCoordinate depth)
    m_height(height),
    m_width(width),
    m_depth(depth) {}

TerrainType WorldMapImp::terrain_type(const MapLocation& loc) const
{
    // TODO
    return TerrainType::invalid;
}

void WorldMapImp::terrain_type(const MapLocation& loc, TerrainType type)
{
    // TODO
}

const MapSlice& WorldMapImp::slice(const MapLocation& loc,
                                   MapDelta width,
                                   MapDelta height) const
{
    // TODO
}

MapCoordinate WorldMapImp::height() const
{
    return m_height;
}

MapCoordinate WorldMapImp::width() const
{
    return m_width;
}

MapCoordinate WorldMapImp::depth() const
{
    return m_depth;
}

} // namespace walls
