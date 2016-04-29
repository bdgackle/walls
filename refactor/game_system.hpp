/**
 *  @file game_system.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of class GameSystem
 */

#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

// Local Headers
#include "unit_types.hpp"

namespace walls {

/**
 *  Interface to a single game engine system
 *
 *  Interface to all systems that the game engine should regularly update as
 *  time elapses (physics, thermal model, AI, etc)
 */
class GameSystem {
 public:
    /**
     *  Update the system
     *
     *  Updates a given game system by elapsing time by the given value
     *
     *  @param [in] t: Amount of time that elapses between frames
     */
    virtual void update(TimeDelta t) = 0;
}; // class GameSystem

} // namespace walls

#endif // GAME_SYSTEM_HPP
