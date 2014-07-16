/**
 *  @author Barry Gackle
 */

// C Standard Library
#include <stdlib.h>

// External Headers
#include <ncurses.h>

// Internal Headers
#include "bunny.h"
#include "world.h"
#include "maplocation.h"

namespace walls {

Bunny::Bunny(World* world, const MapLocation& location) :
    Creature(world, location),
    m_food(100) {}

Bunny::~Bunny() {}

void Bunny::update(int time) {
    Object::update(time);


    if (m_food < 0)
        die();

    if (m_food > 200) {
        breed();
        m_food = 100;
    }

    if ((m_world->getMap()->getBlock(getLocation())->getIsEmpty())) {
        m_food--;

        MapLocation dirs[4];
        dirs[0] = getLocation().getRelative(0, -1, 0);
        dirs[1] = getLocation().getRelative(0, 1, 0);
        dirs[2] = getLocation().getRelative(1, 0, 0);
        dirs[3] = getLocation().getRelative(-1, 0, 0);

        int num = rand() % 4;
        int dir;

        for (int i = 0; i < 4; i++) {
            dir = (num + i) % 4;
            if (m_world->getMap()->exists(dirs[dir])) {
                if (!(m_world->getMap()->getBlock(dirs[dir])->getIsEmpty())) {
                    break;
                }
            }
        }

        switch(dir) {
        case 0:
            move(0, -1, 0);
            break;
        case 1:
            move(0, 1, 0);
            break;
        case 2:
            move(1, 0, 0);
            break;
        case 3:
        default:
            move(-1, 0, 0);
            break;
        }
    }
    else {
        m_world->getMap()->getBlock(getLocation())->getPlant()->die();
        m_food += 3;
    }
}

void Bunny::breed() {
    m_world->addCreature(new Bunny(m_world, getLocation()));
}

char Bunny::getDisplayChar() const { return 'b'; }

int Bunny::getDisplayColor() const { return COLOR_PAIR(5); }

} // walls
