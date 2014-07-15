/*
 *  @author Barry Gackle
 */

#ifndef OBJECT_H
#define OBJECT_H

// Internal Headers
#include "maplocation.h"

// Forward Declarations
namespace walls {
    class World;
}

namespace walls {

class Object
{
 public:
    Object(World* world, const MapLocation& location);
    virtual ~Object();

    virtual void update(int time);

    virtual char getDisplayChar() const = 0;
    virtual int getDisplayColor() const = 0;

    MapLocation getLocation() const;
    World* getWorld();

    void setLocation(const MapLocation& location);

 protected:
    World* m_world;
    MapLocation m_location;
    int m_age;
};

} // walls

#endif // OBJECT_H
