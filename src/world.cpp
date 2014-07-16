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

namespace walls {

World::World(int width, int height, int depth) :
    m_map(width, height, depth),
    m_scanner(&m_map),
    m_boundries_dirty(true),
    m_player(this),
    m_time(0) {}

World::~World() {}

void World::update(int time) {
    if (m_boundries_dirty) {
        m_scanner.updateBoundry();
        m_boundries_dirty = false;
    }

    m_creatures.update(time);
    m_plants.update(time);

    m_time += time;
}

const Map& World::getMap() const { return m_map; }

const Player& World::getPlayer() const { return m_player; }

const ObjectList& World::getCreatures() const { return m_creatures; }

const ObjectList& World::getPlants() const { return m_plants; }

int World::getTime() const { return m_time; }

int World::getCreatureCount() const { return m_creatures.getCount(); }

int World::getPlantCount() const { return m_plants.getCount(); }

Map* World::getMap() { return &m_map; }

Player* World::getPlayer() { return &m_player; }

ObjectList* World::getCreatures() { return &m_creatures; }

ObjectList* World::getPlants() { return &m_plants; }

void World::addCreature(Object* creature) { m_creatures.addObject(creature); }

void World::addPlant(Object* plant) { m_plants.addObject(plant); }

void World::setBoundriesDirty() { m_boundries_dirty = true; }

} // walls
