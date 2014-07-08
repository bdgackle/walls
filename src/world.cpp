/**
 *  @author Barry Gackle
 */

// External Headers
#include <stdio.h>
#include <stdlib.h>

// Internal Headers
#include "world.h"
#include "maplocation.h"
#include "game_constants.h"
#include "ferret.h"
#include "block.h"

namespace walls{

World::World(int width, int height, int depth) :
m_map(width, height, depth),
m_scanner(&m_map),
m_boundries_dirty(true) {}

World::~World() {}

void World::init(unsigned int seed)
{
    m_map.init();
    m_player.init(this);
    m_scanner.init(m_map.getBlockCount());

    srand(seed);

    int depth = 0;
    int width = m_map.getWidth();
    int height = m_map.getHeight();

    // Seed the world with some random rocks/trees/pebbles
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {

            int random_number = rand() % 1000;

            if (random_number < 5)
                m_map.getBlock(MapLocation(x, y, depth))->setType(ROCK);
            else if (random_number < 10)
                m_map.getBlock(MapLocation(x, y, depth))->setType(SAPLING);
            else if (random_number < 20)
                m_map.getBlock(MapLocation(x, y, depth))->setType(SMALL_ROCK);
        }
    }

    // Seed the world with some random ferrets
    for (int i = 0; i < 10; i++) {
        Ferret* ferret = new Ferret;
        ferret->init(MapLocation(5,5,0), this);
        addCreature(ferret);
    }

    // Add player to the world
    m_player.setLocation(MapLocation(height / 2, width / 2, 0));
}

void World::update(int time)
{
    if (m_boundries_dirty) {
        m_scanner.updateBoundry();
        m_boundries_dirty = false;
    }

    for (int i = 0; i < m_creatures.size(); i++) {
        m_creatures.at(i)->update(time);
    }
}

const Map& World::getMap() const { return m_map; }

const Player& World::getPlayer() const { return m_player; }

const vector<Creature*>& World::getCreatures() const { return m_creatures; }

Map* World::getMap() { return &m_map; }

Player* World::getPlayer() { return &m_player; }

vector<Creature*>* World::getCreatures() { return &m_creatures; }

void World::addCreature(Creature* creature) { m_creatures.push_back(creature); }

void World::setBoundriesDirty() { m_boundries_dirty = true; }

} // walls
