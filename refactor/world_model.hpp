/**
 *  @file world_model.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of interface to the entire game world
 */

#ifndef WORLD_MODEL_HPP
#define WORLD_MODEL_HPP

// Local Headers
#include "unit_types.hpp"

namespace walls {
class GameCommand;
class GameSystemStatus;
class MapSlice;
class MapSliceInfo;

/**
 *  Interface to the entire game world, intended to be used by app and UI
 */
class WorldModel {
 public:
    /** Make time pass in the world */
    virtual void update(TimeDelta time_delta) = 0;

    /** Respond to user input command */
    virtual void do_command(const GameCommand& cmd) = 0;

    /** Retrieve a slice of the map */
    virtual const MapSlice& read_map(const MapSliceInfo& info) const = 0;

    /** Retrieve status of a game system */
    virtual const GameSystemStatus& read_system(GameSystemType type) const = 0;

}; // class World

} // namespace walls

#endif // WORLD_MODEL_HPP
