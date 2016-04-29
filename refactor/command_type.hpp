/**
 *  @file command_type.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains enumberation CommandType
 */

#ifndef COMMAND_TYPE_HPP
#define COMMAND_TYPE_HPP

namespace walls {

/** Enumeration of available game commands */
enum class CommandType {
    MovePlayerWest,
    MovePlayerEast,
    MovePlayerNorth,
    MovePlayerSouth,
    MovePlayerUp,
    MovePlayerDown
}; // enum class CommandType

} // namespace walls

#endif // COMMAND_TYPE_HPP
