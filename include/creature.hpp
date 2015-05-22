/**
 *  @author Barry Gackle
 */

#ifndef CREATURE_HPP
#define CREATURE_HPP

// Local Headers
#include "object_imp.hpp"
#include "maplocation.hpp"

namespace walls {
class World;

class Creature : public ObjectImp {
 public:
    Creature(World* world,
             const MapLocation& location,
             bool is_prey,
             int initial_food);

    virtual ~Creature() {}

    virtual void die();
    int getFood() const;
    MapLocation getTarget() const;

 protected:
    virtual void moveRandom();
    virtual void moveTowardClosestPrey(int range);
    virtual void move(int d_x, int d_y, int d_z);

    virtual MapLocation findClosestPrey(int range);
    MapLocation m_target;
    const bool m_is_prey;
    int m_food;
};

} // namespace walls

#endif // CREATURE_HPP
