/**
 *  @author Barry Gackle
 */

// C Standard Headers
#include <stdlib.h>

// C++ Standard Headers
#include <list>

// Internal Headers
#include "creature.h"
#include "world.h"

using std::list;

namespace walls {

Creature::Creature(World* world,
                   const MapLocation& location,
                   bool is_prey,
                   int initial_food) :
    Object(world, location),
    m_is_prey(is_prey),
    m_target(0, 0, 0),
    m_food(initial_food)
{
    if (m_is_prey)
        m_world->getMap()->getBlock(getLocation())->addPrey(this);
    else
        m_world->getMap()->getBlock(getLocation())->addCreature(this);
}

Creature::~Creature() {}

void Creature::update(int time)
{
    Object::update(time);
}

void Creature::die() 
{
    if (m_is_prey)
        m_world->getMap()->getBlock(getLocation())->removePrey(this);
    else
        m_world->getMap()->getBlock(getLocation())->removeCreature(this);
    setIsDead();
}

bool Creature::getIsPrey()
{
    return m_is_prey;
}

int Creature::getFood() const
{
    return m_food;
}

MapLocation Creature::getTarget()
{
    return m_target;
}

void Creature::moveRandom()
{
    int dir = rand() % 4;

    if (dir == 0)
        move(-1, 0, 0);
    else if (dir == 1)
        move(1, 0, 0);
    else if (dir == 2)
        move(0, -1, 0);
    else if (dir == 3)
        move(0, 1, 0);
}

void Creature::moveTowardClosestPrey(int range)
{
    MapLocation target = findClosestPrey(range);
    m_target = target;

    // If we find no critters, just move randomly
    if (target == m_location) {
        moveRandom();
        return;
    }

    int dist_x = m_location.getDistanceX(target);
    int dist_y = m_location.getDistanceY(target);

    // Move along longest axis to create best illusion of straight line
    if (abs(dist_x) > abs(dist_y)) {
        if (dist_x > 0){
            move(1, 0, 0);
        }
        else { move(-1, 0, 0);}
    }
    else {
        if (dist_y > 0) {
            move(0, 1, 0);
        }
        else {
            move(0, -1, 0);
        }
    }
}

void Creature::move(int d_x, int d_y, int d_z)
{
    MapLocation old_loc = getLocation();
    MapLocation new_loc = old_loc.getRelative(d_x, d_y, d_z);

    if ((m_world->getMap()->exists(new_loc)) &&
        !(m_world->getMap()->getBlock(new_loc)->getIsMovementBoundry())) {
        setLocation(new_loc);
        if (m_is_prey) {
            m_world->getMap()->getBlock(old_loc)->removePrey(this);
            m_world->getMap()->getBlock(new_loc)->addPrey(this);
        }
        else {
            m_world->getMap()->getBlock(old_loc)->removeCreature(this);
            m_world->getMap()->getBlock(new_loc)->addCreature(this);
        }
    }
}

// PERF:  This function would be a lot more efficient if it searched out from
//        the center, and stopped at the first creature, since we'd search
//        a lot fewer spots.  It is more complex that way, though, so will only
//        go that route if this becomes a hot spot.
// PERF: 140, 350
MapLocation Creature::findClosestPrey(int range)
{
    for (int dist = 1; dist <= range; dist++) {
        list<MapLocation> adjacent;
        m_world->getMap()->getAdjacent(m_location, &adjacent, range);

       while (adjacent.size() > 0) {
            MapLocation loc = adjacent.back();
            adjacent.pop_back();
            if (m_world->getMap()->getBlock(loc)->getHasPrey()) {
                return loc;
            }
        }
    }

    // No prey found in range
    return m_location;

/* OLD VERSION
    m_world->getMap()->getAdjacent(m_location, &adjacent, range); //78, 101
    while (adjacent.size() > 0) {
        MapLocation loc = adjacent.back();
        adjacent.pop_back();
        Block* block = m_world->getMap()->getBlock(loc);

        if (block->getHasPrey()) {
            int distance = 0;
            distance += abs(m_location.getDistanceX(loc));
            distance += abs(m_location.getDistanceY(loc));
            if (distance < closest_critter) {
                closest_critter = distance;
                closest_critter_loc = loc;
            }
        }
    }
    return closest_critter_loc;
*/
}

} // walls
