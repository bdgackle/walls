/**
 *  @file application.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 6 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains class Application
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

namespace walls {
class UserInterface;
class WorldModel;

/** Top level application class */
class Application {
 public:
    /** Perform dependency injection */
    virtual void init(UserInterface* user_interface,
                      WorldModel* world_model) = 0;

    /** Execute one iteration of the game loop */
    virtual void execute_game_loop() = 0;
}; // class Application

} // namespace walls

#endif // APPLICATION_HPP
