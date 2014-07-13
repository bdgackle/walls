/**
 *  @author Barry Gackle
 */

// External Headers
#include <stdio.h>

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
m_boundries_dirty(true),
m_player(this),
m_time(0),
m_creature_count(0) {}

World::~World() {}

void World::update(int time)
{
    if (m_boundries_dirty) {
        m_scanner.updateBoundry();
        m_boundries_dirty = false;
    }

    for (int i = 0; i < m_creatures.size(); i++) {
        m_creatures.at(i)->update(time);
    }

    m_time += time;
}

const Map& World::getMap() const { return m_map; }

const Player& World::getPlayer() const { return m_player; }

const vector<Creature*>& World::getCreatures() const { return m_creatures; }

int World::getTime() const { return m_time; }

int World::getCreatureCount() const { return m_creature_count; }

Map* World::getMap() { return &m_map; }

Player* World::getPlayer() { return &m_player; }

vector<Creature*>* World::getCreatures() { return &m_creatures; }

void World::addCreature(Creature* creature) 
{
    m_creature_count++;
    m_creatures.push_back(creature);
    m_map.getBlock(creature->getLocation())->addCreature(creature);
}

void World::setBoundriesDirty() { m_boundries_dirty = true; }

} // walls
