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
m_creature_count(0),
m_plant_count(0) {}

World::~World() {}

void World::update(int time)
{
    if (m_boundries_dirty) {
        m_scanner.updateBoundry();
        m_boundries_dirty = false;
    }

    list<Creature*>::iterator iter;
    for (iter = m_creatures.begin(); iter != m_creatures.end(); ++iter) {
        (*iter)->update(time);
    }

    for (iter = m_plants.begin(); iter != m_plants.end(); ++iter) {
        (*iter)->update(time);
    }

    m_time += time;
}

const Map& World::getMap() const { return m_map; }

const Player& World::getPlayer() const { return m_player; }

const list<Creature*>& World::getCreatures() const { return m_creatures; }

const list<Creature*>& World::getPlants() const { return m_plants; }

int World::getTime() const { return m_time; }

int World::getCreatureCount() const { return m_creature_count; }

int World::getPlantCount() const { return m_plant_count; }

Map* World::getMap() { return &m_map; }

Player* World::getPlayer() { return &m_player; }

list<Creature*>* World::getCreatures() { return &m_creatures; }

list<Creature*>* World::getPlants() { return &m_plants; }

void World::addCreature(Creature* creature) 
{
    m_creature_count++;
    m_creatures.push_back(creature);
    m_map.getBlock(creature->getLocation())->addCreature(creature);
}

void World::addPlant(Creature* plant) 
{
    m_plant_count++;
    m_plants.push_back(plant);
    m_map.getBlock(plant->getLocation())->addCreature(plant);
}

void World::setBoundriesDirty() { m_boundries_dirty = true; }

} // walls
