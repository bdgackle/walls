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

class Object {
 public:
    Object(World* world, const MapLocation& location);
    virtual ~Object();

    virtual void update(int time);

    virtual char getDisplayChar() const = 0;
    virtual int getDisplayColor() const = 0;
    int getId() const;
    bool getIsDead() const;

    MapLocation getLocation() const;

 protected:
    void setLocation(const MapLocation& location);
    void setIsDead();

    World* m_world;
    MapLocation m_location;
    int m_age;
    int m_id;
    bool m_is_dead;

    static int m_next_id;
};

} // walls

#endif // OBJECT_H
