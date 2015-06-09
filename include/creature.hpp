/**
 *  @author Barry Gackle
 */

#ifndef CREATURE_HPP
#define CREATURE_HPP

// Internal Headers
#include "object.hpp"
#include "maplocation.hpp"

namespace walls {
    class World;
}

namespace walls {

class Creature : public Object {
 public:
    Creature(World* world,
             const MapLocation& location,
             bool is_prey,
             int initial_food);

    virtual ~Creature();

    virtual void update(int time);

    virtual void die();
    virtual bool getIsPrey();
    int getFood() const;
    MapLocation getTarget();

 protected:
    virtual void moveRandom();
    virtual void moveTowardClosestPrey(int range);
    virtual void move(int d_x, int d_y, int d_z);

    virtual MapLocation findClosestPrey(int range);
    MapLocation m_target;
    const bool m_is_prey;
    int m_food;
};

} // walls

#endif // CREATURE_HPP
