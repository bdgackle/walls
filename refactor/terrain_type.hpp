/**
 *  @file terrain_type.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Enumeration of available terrain types that a voxel can be
 */

#ifndef TERRAIN_TYPE_HPP
#define TERRAIN_TYPE_HPP

namespace walls {

enum class TerrainType {
    invalid,
    empty,
    air,
    dirt,
    rock
}; // enum class TerrainType

} // namespace walls

#endif // TERRAIN_TYPE_HPP
