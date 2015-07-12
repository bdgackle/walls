/**
 *  @author Barry Gackle
 */

// Local Headers
#include "appearance.hpp"
#include "creature_appearances.hpp"
#include "grass.hpp"
#include "world.hpp"

// C Standard Library
#include <stdlib.h>
#include <stdint.h>

namespace walls {

const int Grass::k_flower_min = 0;
const int Grass::k_flower_max = 100;
const int Grass::k_seed_max   = 150;

Grass::Grass(World* world, const MapLocation& location) :
    ObjectImp(world, location),
    m_flower(false),
    m_age(0)
{
    m_world->getMap()->addPlant(getLocation(), this);
    m_flower_time = k_flower_min + rand() % (k_flower_max - k_flower_min);
    m_seed_time = m_flower_time + (rand() % (k_seed_max - k_flower_max));
}

void Grass::update(int time)
{
    m_age++;
    if (m_age > m_seed_time)
        reproduce();
    else if (m_age > m_flower_time)
        m_flower = true;
}

Appearance Grass::appearance() const
{
    if (m_flower)
        return grass_appearance;
    else
        return grass_seed_appearance;
}

void Grass::reproduce()
{
    uint8_t random_number = rand() % 255;

    if (random_number & 0x01)
        seed(m_location.getRelative(0, -1, 0));

    if (random_number & 0x02)
        seed(m_location.getRelative(0, 1, 0));

    if (random_number & 0x04)
        seed(m_location.getRelative(1, 0, 0));

    if (random_number & 0x08)
        seed(m_location.getRelative(-1, 0, 0));

    if (random_number & 0x10)
        seed(m_location.getRelative(1, -1, 0));

    if (random_number & 0x20)
        seed(m_location.getRelative(1, 1, 0));

    if (random_number & 0x40)
        seed(m_location.getRelative(-1, -1, 0));

    if (random_number & 0x80)
        seed(m_location.getRelative(-1, 1, 0));

    die();
}

void Grass::die()
{
    m_world->getMap()->removePlant(getLocation(), this);
    setIsDead();
}

void Grass::seed(const MapLocation& location)
{
    if ((m_world->getMap()->exists(location)) &&
        (m_world->getMap()->blockType(location) == GROUND) &&
        !(m_world->getMap()->hasPlant(location))) {
        m_world->addPlant(new Grass(m_world, location));
    }
}

} // namespace walls
