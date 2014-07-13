/**
 *  @author Barry Gackle
 */

#ifndef THING_H
#define THING_H

// Internal Headers
#include "maplocation.h"

namespace walls{

class World;

class Thing
{
 public:
    Thing();
    virtual ~Thing();

    virtual void init(const MapLocation& location, World* world) = 0;

    MapLocation getLocation() const;
    void setLocation(const MapLocation& location);

    virtual void update(int time) = 0;

    virtual char getDisplayChar() const = 0;

 protected:
    World* m_world;
    MapLocation m_location;
};

} // walls

#endif // THING_H
