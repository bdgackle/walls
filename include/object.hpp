/*
 *  @author Barry Gackle
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

// Local Headers
#include "maplocation.hpp"
#include "displayable.hpp"

namespace walls {
class World;

class Object : public Displayable {
 public:
    virtual ~Object() {}

    virtual void update(int time) = 0;
    virtual bool getIsDead() const = 0;
    virtual MapLocation getLocation() const = 0;
    virtual void setIsDead() = 0;
    virtual void die() = 0;
};

} // namespace walls

#endif // OBJECT_HPP
