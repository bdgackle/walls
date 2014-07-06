/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef UI_H
#define UI_H

// Internal Headers
#include "display.h"
#include "input_handler.h"

class World;

namespace walls
{

using std::string;

class UserInterface
{
 public:
    UserInterface();
    virtual ~UserInterface();

    void start(World *world, const MapLocation& start);

 protected:
    void init(const MapLocation& start);
    int getDepth();

 private:
    Display m_display;
    InputHandler m_input;
    World* m_world;
    int m_depth;
};

} // walls

#endif // UI_H
