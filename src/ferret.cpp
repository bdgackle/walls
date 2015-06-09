/**
 *  @author Barry Gackle
 */

// C Standard Library
#include <stdlib.h>

// External Headers
#include <ncurses.h>

// Internal Headers
#include "ferret.hpp"
#include "maplocation.hpp"
#include "world.hpp"

namespace walls {

Ferret::Ferret(World* world, const MapLocation& location) :
    Creature(world, location, false, INITIAL_FOOD_VALUE),
    m_visual_range(VISUAL_RANGE) {}

Ferret::~Ferret() {}

void Ferret::update(int time)
{
    Creature::update(time);

    if (m_food < 0)
        die();

    if (m_food > BREED_FOOD_VALUE) {
        breed();
        m_food = POST_BREED_FOOD_VALUE;
    }

    if ((m_world->getMap()->getBlock(getLocation())->getHasPrey())) {
        m_world->getMap()->getBlock(getLocation())->getPrey()->die();
        m_food += BUNNY_NUTRITION;
    }
    else {
        m_food -= MOVE_NUTRITION;
        moveTowardClosestPrey(m_visual_range);
    }

    // Hack to prevent all ferrets from clumping on single square
    if ((m_food % 10) == 0)
        moveRandom();
}

void Ferret::breed()
{
    m_world->addCreature(new Ferret(m_world, getLocation()));
}

char Ferret::getDisplayChar() const
{ 
    return 'f'; 
}

int Ferret::getDisplayColor() const
{ 
    return COLOR_PAIR(2);
}

} // walls
