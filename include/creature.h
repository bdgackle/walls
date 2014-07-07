/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

#ifndef CREATURE_H
#define CREATURE_H

// Internal Headers
#include "map.h"
#include "maplocation.h"

namespace walls{

class Creature
{
 public:

    Creature();
    virtual ~Creature();

    virtual void init(MapLocation location, Map* map) = 0;
    void setLocation(MapLocation location);
    MapLocation getLocation() const;

    virtual void update() = 0;

    virtual char getDisplayChar() const = 0;

 protected:
    Map* m_map;
    MapLocation m_location;

};

} // walls

#endif // CREATURE_H
