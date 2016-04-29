/**
 *  @file game_system_type.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains enum GameSystemType
 */

#ifndef GAME_SYSTEM_TYPE_HPP
#define GAME_SYSTEM_TYPE_HPP

namespace walls {

/** Enumerates all available game systems */
enum class GameSystemType {
    PhysicalData,
	PlayerModel,
    ThermalData,
    BiologicalData,
    PreditorData,
    PreyData
}; // enum class EntityComponentType

} // namespace walls

#endif // GAME_SYSTEM_TYPE_HPP
