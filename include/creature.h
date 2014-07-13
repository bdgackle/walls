/**
 *  @author Barry Gackle
 */

#ifndef CREATURE_H
#define CREATURE_H

// Internal Headers
#include "object.h"
#include "maplocation.h"

namespace walls{
    class World;
}

namespace walls{

class Creature : public Object
{
 public:
    Creature(World* world, const MapLocation& location);
    virtual ~Creature();

    virtual char getDisplayChar() const = 0;

 protected:
    virtual void move(int d_x, int d_y, int d_z);
};

} // walls

#endif // CREATURE_H
