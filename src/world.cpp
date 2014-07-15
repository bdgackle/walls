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
#include "grass.h"
#include "block.h"

namespace walls{

World::World(int width, int height, int depth) :
m_map(width, height, depth),
m_scanner(&m_map),
m_boundries_dirty(true),
m_player(this),
m_time(0) {}

World::~World() {}

void World::update(int time)
{
    if (m_boundries_dirty) {
        m_scanner.updateBoundry();
        m_boundries_dirty = false;
    }

    for (list<Object*>::iterator iter = m_creatures.begin();
         iter != m_creatures.end(); ++iter) {
        (*iter)->update(time);
    }

    for (list<Object*>::iterator iter = m_plants.begin();
         iter != m_plants.end(); ) {
        Object* next = *iter;
        ++iter;
        next->update(time);
    }

    m_time += time;
}

const Map& World::getMap() const { return m_map; }

const Player& World::getPlayer() const { return m_player; }

const list<Object*>& World::getCreatures() const { return m_creatures; }

const list<Object*>& World::getPlants() const { return m_plants; }

int World::getTime() const { return m_time; }

int World::getCreatureCount() const { return m_creatures.size(); }

int World::getPlantCount() const { return m_plants.size(); }

Map* World::getMap() { return &m_map; }

Player* World::getPlayer() { return &m_player; }

list<Object*>* World::getCreatures() { return &m_creatures; }

list<Object*>* World::getPlants() { return &m_plants; }

void World::addCreature(Object* creature) 
{
    m_creatures.push_back(creature);
    m_map.getBlock(creature->getLocation())->addCreature(creature);
}

void World::addPlant(Object* plant) 
{
    m_plants.push_back(plant);
    m_map.getBlock(plant->getLocation())->addPlant(plant);
}

void World::setBoundriesDirty() { m_boundries_dirty = true; }

} // walls
