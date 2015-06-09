/**
 *  @author Barry Gackle
 */

#ifndef PLANT_HPP
#define PLANT_HPP

// Internal Headers
#include "object.hpp"
#include "maplocation.hpp"

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

#endif // PLANT_HPP
