/**
 *  @author Barry Gackle
 */

#ifndef PLANT_HPP
#define PLANT_HPP

// Local Headers
#include "object.hpp"
#include "maplocation.hpp"

namespace walls {
class World;

class Plant : public Object {
 public:
    Plant(World* world, const MapLocation& location);
    virtual ~Plant();

    virtual void die();
};

} // namespace walls

#endif // PLANT_HPP
