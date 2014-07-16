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

Grass::Grass(World* world, const MapLocation& location) :
    m_flower(false),
    Plant(world, location) {
    m_flower_time = rand() % 1000;
    m_seed_time = rand() % 200;
}

Grass::~Grass() {}

void Grass::update(int time) {
    Object::update(time);

    if (m_age > m_flower_time)
        m_flower = true;
    else if (m_age > m_seed_time)
        reproduce();
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
