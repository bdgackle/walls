/*
 *  @author Barry Gackle
 */

#ifndef OBJECT_IMP_HPP
#define OBJECT_IMP_HPP

// Local Headers
#include "maplocation.hpp"
#include "object.hpp"

namespace walls {
class World;

class ObjectImp : public Object {
 public:
    ObjectImp(World* world, const MapLocation& location);
    virtual ~ObjectImp() {}

    bool getIsDead() const;

    MapLocation getLocation() const;

    void setIsDead();
 protected:
    void setLocation(const MapLocation& location);

    World* m_world;
    MapLocation m_location;
    bool m_is_dead;
};

} // namespace walls

#endif // OBJECT_IMP_H
