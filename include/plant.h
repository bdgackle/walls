/**
 *  @author Barry Gackle
 */

#ifndef PLANT_H
#define PLANT_H

// Internal Headers
#include "object.h"
#include "maplocation.h"

namespace walls{
    class World;
}

namespace walls {

class Plant : public Object {
 public:
    Plant(World* world, const MapLocation& location);
    virtual ~Plant();

    virtual void die();
};

} // walls

#endif // PLANT_H
