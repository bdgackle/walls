/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef UI_H
#define UI_H

// Internal Headers
#include "display.h"
#include "input_handler.h"
#include "maplocation.h"

using std::string;

namespace walls {
    class World;
}

namespace walls {

class UserInterface {
 public:
    UserInterface(World* world);
    virtual ~UserInterface();

    void init();
    void start();

    void centerPlayer();
    void adjustPlayer();

 protected:
    void doCommand(Command command);
    int getDepth() const;
    MapLocation getCursorLocation() const;

 private:
    Display m_display;
    InputHandler m_input;
    World* m_world;

    MapLocation m_display_upper_left;
};

} // walls

#endif // UI_H
