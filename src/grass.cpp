/**
 *  @author Barry Gackle
 */

// C Standard Library
#include <stdlib.h>

// External Headers
#include <ncurses.h>

// Internal Headers
#include "grass.h"
#include "block.h"
#include "world.h"

namespace walls {

Grass::Grass(World* world, const MapLocation& location) :
    m_flower(false),
    Plant(world, location) {}

Grass::~Grass() {}

void Grass::update(int time) {
    Object::update(time);

    int random_number = rand() % 1000;

    if (m_age > random_number) {
        if (m_flower) {
            reproduce();
        }
        else {
            m_flower = true;
        }
    }
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
    seed(m_location.getRelative(0, -1, 0));
    seed(m_location.getRelative(0, 1, 0));
    seed(m_location.getRelative(1, 0, 0));
    seed(m_location.getRelative(-1, 0, 0));
    seed(m_location.getRelative(1, -1, 0));
    seed(m_location.getRelative(1, 1, 0));
    seed(m_location.getRelative(-1, -1, 0));
    seed(m_location.getRelative(-1, 1, 0));
    die();
}

void Grass::seed(const MapLocation& location) {
    int random_number = rand() % 4;

    if ((random_number == 0) &&
        (m_world->getMap()->exists(location)) &&
        (m_world->getMap()->getBlock(location)->getType() == GROUND) &&
        (m_world->getMap()->getBlock(location)->getIsEmpty())) {
        Grass* newborn = new Grass(m_world, location);
        m_world->addPlant(newborn);
    }
}

} // walls
