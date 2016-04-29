/**
 *  @file game_command.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 9 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains definition of class GameCommand
 */

#ifndef GAME_COMMAND_HPP
#define GAME_COMMAND_HPP

// Local Headers
#include "command_type.hpp"

namespace walls {

/** Public interface to represention of single map point */
class GameCommand {
 public:
    virtual CommandType type() const = 0;
}; // class GameCommand

} // namespace walls

#endif // GAME_COMMAND_HPP
