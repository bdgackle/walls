/**
 *  @author Barry Gackle
 */

#ifndef THING_H
#define THING_H

// Internal Headers
#include "maplocation.h"
#include "game_constants.h"

namespace walls{

class World;

class Thing
{
 public:
    Thing();
    virtual ~Thing();

    virtual void init(const MapLocation& location, World* world) = 0;

    MapLocation getLocation() const;
    bool getValid();
    ThingType getType();
    virtual char getDisplayChar() const = 0;
    Thing* getNext();
    void addNext(Thing* thing);

    void setLocation(const MapLocation& location);
    virtual void update(int time) = 0;

 protected:
    World* m_world;
    MapLocation m_location;
    bool m_valid;
    ThingType m_type;
    Thing* m_next;
};

} // walls

#endif // THING_H
