/**
 *  @author Barry Gackle
 */

// Local Headers
#include "appearance.hpp"
#include "creature_appearances.hpp"
#include "ferret.hpp"
#include "maplocation.hpp"
#include "world.hpp"

// C Standard Library
#include <stdlib.h>

namespace walls {

Ferret::Ferret(World* world, const MapLocation& location) :
    Creature(world, location, false, INITIAL_FOOD_VALUE),
    m_visual_range(VISUAL_RANGE) {}

void Ferret::update(int time)
{
    if (m_food < 0)
        die();

    if (m_food > BREED_FOOD_VALUE) {
        breed();
        m_food = POST_BREED_FOOD_VALUE;
    }

    if (m_world->getMap()->hasPrey(getLocation())) {
        m_world->getMap()->prey(getLocation())->die();
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

Appearance Ferret::appearance() const
{
    return ferret_appearance;
}

} // namespace walls
