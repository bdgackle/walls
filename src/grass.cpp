/**
 *  @author Barry Gackle
 */

// C Standard Library
#include <stdlib.h>
#include <stdint.h>

// External Headers
#include <ncurses.h>

// Internal Headers
#include "grass.h"
#include "block.h"
#include "world.h"

namespace walls {

const int Grass::k_flower_min = 1000;
const int Grass::k_flower_max = 2000;
const int Grass::k_seed_max   = 2200;

Grass::Grass(World* world, const MapLocation& location) :
    m_flower(false),
    Plant(world, location) {
    m_flower_time = k_flower_min + rand() % (k_flower_max - k_flower_min);
    m_seed_time = m_flower_time + (rand() % (k_seed_max - k_flower_max));
}

Grass::~Grass() {}

void Grass::update(int time) {
    Object::update(time);

    if (m_age > m_seed_time)
        reproduce();
    else if (m_age > m_flower_time)
        m_flower = true;
}

char Grass::getDisplayChar() const {
    if (m_flower)
        return ';';
    else
        return ',';
}

int Grass::getDisplayColor() const {
    if (m_flower)
        return COLOR_PAIR(4);
    else
        return COLOR_PAIR(3);
}

void Grass::reproduce() {
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

void Grass::seed(const MapLocation& location) {
    if ((m_world->getMap()->exists(location)) &&
        (m_world->getMap()->getBlock(location)->getType() == GROUND) &&
        (m_world->getMap()->getBlock(location)->getIsEmpty())) {
        m_world->addPlant(new Grass(m_world, location));
    }
}

} // walls
