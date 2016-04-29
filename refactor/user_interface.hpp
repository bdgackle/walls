/**
 *  @file user_interface.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 9 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains class UserInterface
 */

#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

namespace walls {
class Display;
class InputSource;
class UserInput;
class WorldModel;

/**
 *  Top level user interface
 *
 *  Encapsulates all user I/O at a high level.  Handles input from the user,
 *  translates that input into commands for the game model, and updates the
 *  display output.
 */
class UserInterface {
 public:
    /**
     *  Perform dependency injection.
     *
     *  @param [in] display: Interface to the game display
     *  @param [in] input_source: Interface to user input
     *  @param [in] world_model: Interface to game model
     */
    virtual void init(Display* display,
                      InputSource* input_source,
                      WorldModel* world_model) = 0;

    /**
     *  Handle new input from user
     *
     *  Callback for any input received from the user.
     */
    virtual void handle_input(const UserInput& input) = 0;

    /**
	 *  Refresh the display
	 *
	 *  Display the current output.
	 */
    virtual void generate_output() = 0;
}; // class UserInterface

} // namespace walls

#endif // USER_INTERFACE_HPP
