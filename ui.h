/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef UI_H
#define UI_H

// Internal Headers
#include "world.h"

namespace walls
{

class UserInterface
{
 public:
    UserInterface();
    virtual ~UserInterface();

    void setWorld(World* world) { m_world = world; }

    int getHeight() { return m_height; }
    int getWidth() { return m_width; }

    void init();
    void start();

 protected:
    void drawWorld();
    void waitForInput();

    void processInputNormal(int input);
    void processInputEdit(int input);
    void processInputCommon(int input);

 private:
    World* m_world;
    int m_last_input;

    int m_height;
    int m_width;

    int m_mode;

    char* m_last_frame;

    static const int MODE_NORMAL = 1;
    static const int MODE_EDIT   = 2;
};

} // walls

#endif // UI_H
