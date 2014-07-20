/**
 *  @author Barry Gackle
 */

// C Standard Library
#include <stdlib.h>

// External Headers
#include <ncurses.h>

// Internal Headers
#include "ferret.h"
#include "maplocation.h"
#include "world.h"

namespace walls {

Ferret::Ferret(World* world, const MapLocation& location) :
    Creature(world, location, false),
    m_visual_range(30),
    m_food(500) {}

Ferret::~Ferret() {}

void Ferret::update(int time)
{
    Creature::update(time);

    if (m_food < 0)
        die();

    if (m_food > 2500) {
        breed();
        m_food = 1000;
    }

    if ((m_world->getMap()->getBlock(getLocation())->getHasPrey())) {
        m_world->getMap()->getBlock(getLocation())->getPrey()->die();
        m_food += 100;
    }
    else {
        m_food--;
        moveTowardClosestPrey(m_visual_range);
    }

    // Prevent all ferrets from clumping on single square
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
