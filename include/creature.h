/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

#ifndef CREATURE_H
#define CREATURE_H

// Internal Headers
#include "world.h"
#include "map.h"
#include "maplocation.h"

namespace walls{

class Creature
{
 public:

    Creature();
    virtual ~Creature();

    virtual void init(const MapLocation& location, World* world) = 0;

    MapLocation getLocation() const;

    void setLocation(const MapLocation& location);

    virtual void update(int time) = 0;

    virtual char getDisplayChar() const = 0;

    virtual void move(int d_x, int d_y, int d_z) = 0;

 protected:
    World* m_world;
    MapLocation m_location;
};

} // walls

#endif // CREATURE_H
