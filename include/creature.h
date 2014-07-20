/**
 *  @author Barry Gackle
 */

#ifndef CREATURE_H
#define CREATURE_H

// Internal Headers
#include "object.h"
#include "maplocation.h"

namespace walls {
    class World;
}

namespace walls {

class Creature : public Object {
 public:
    Creature(World* world, const MapLocation& location, bool is_prey);
    virtual ~Creature();

    virtual void update(int time);

    virtual void die();
    virtual bool getIsPrey();
    MapLocation getTarget();

 protected:
    virtual void moveRandom();
    virtual void moveTowardClosestPrey(int range);
    virtual void move(int d_x, int d_y, int d_z);

    virtual MapLocation findClosestPrey(int range);
    MapLocation m_target;
    const bool m_is_prey;
};

} // walls

#endif // CREATURE_H
