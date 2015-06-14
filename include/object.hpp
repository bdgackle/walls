/*
 *  @author Barry Gackle
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

// Local Headers
#include "maplocation.hpp"

namespace walls {
class World;

class Object {
 public:
    Object(World* world, const MapLocation& location);
    virtual ~Object();

    virtual void update(int time);

    virtual char getDisplayChar() const = 0;
    virtual int getDisplayColor() const = 0;
    int getId() const;
    int getAge() const;
    bool getIsDead() const;

    MapLocation getLocation() const;

    void setIsDead();

    virtual void die() = 0;
 protected:
    void setLocation(const MapLocation& location);

    World* m_world;
    MapLocation m_location;
    int m_age;
    int m_id;
    bool m_is_dead;

    static int m_next_id;
};

} // namespace walls

#endif // OBJECT_HPP
