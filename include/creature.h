/**
 *  @author Barry Gackle
 */

#ifndef CREATURE_H
#define CREATURE_H

// Internal Headers
#include "thing.h"

namespace walls{

class Creature : public Thing
{
 public:
    Creature();
    virtual ~Creature();

    virtual void move(int d_x, int d_y, int d_z) = 0;
};

} // walls

#endif // CREATURE_H
