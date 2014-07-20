/**
 *  @author Barry Gackle
 */

// External Headers
#include <stdio.h>
#include <time.h>

// Internal Headers
#include "world.h"
#include "maplocation.h"
#include "game_constants.h"
#include "grass.h"
#include "block.h"

namespace walls {

World::World(int width, int height, int depth) :
    m_map(width, height, depth),
    m_scanner(&m_map),
    m_boundries_dirty(true),
    m_player(this),
    m_time(0),
    m_update_time(0) {}

World::~World() {}

void World::update(int time)
{
    clock_t start = clock();
    if (m_boundries_dirty) {
        m_scanner.updateBoundry();
        m_boundries_dirty = false;
    }

    m_creatures.update(time);
    m_plants.update(time);
    m_prey.update(time);

    m_time += time;
    clock_t stop = clock();
    m_update_time = stop - start;
}

const Map& World::getMap() const
{
    return m_map;
}

const Player& World::getPlayer() const
{
    return m_player;
}

const ObjectList& World::getCreatures() const
{
    return m_creatures;
}

const ObjectList& World::getPlants() const
{
    return m_plants;
}

const ObjectList& World::getPrey() const
{
    return m_prey;
}

int World::getTime() const
{
    return m_time;
}

int World::getCreatureCount() const
{
    return m_creatures.getCount();
}

int World::getPlantCount() const
{
    return m_plants.getCount();
}

int World::getPreyCount() const
{
    return m_prey.getCount();
}

int World::getUpdateTime() const
{
    return m_update_time;
}

Map* World::getMap()
{
    return &m_map;
}

Player* World::getPlayer()
{
    return &m_player;
}

ObjectList* World::getCreatures()
{
    return &m_creatures;
}

ObjectList* World::getPlants()
{
    return &m_plants;
}

ObjectList* World::getPrey()
{
    return &m_prey;
}

void World::addCreature(Object* creature)
{
    m_creatures.addObject(creature);
}

void World::addPlant(Object* plant)
{
    m_plants.addObject(plant);
}

void World::addPrey(Object* prey)
{
    m_prey.addObject(prey);
}

void World::setBoundriesDirty()
{
    m_boundries_dirty = true;
}

} // walls
