/**
 *  @author Barry Gackle
 */

#ifndef WORLD_H
#define WORLD_H

// C++ Standard Headers
#include <list>

// Internal Headers
#include "boundry_scanner.h"
#include "player.h"
#include "map.h"

using std::list;

namespace walls{

class Creature;

class World
{
 public:
    World(int width, int height, int depth);
    virtual ~World();

    void update(int time);

    const Map& getMap() const;
    const Player& getPlayer() const;
    const list<Creature*>& getCreatures() const;
    const list<Creature*>& getPlants() const;

    int getTime() const;
    int getCreatureCount() const;
    int getPlantCount() const;

    Map* getMap();
    Player* getPlayer();
    list<Creature*>* getCreatures();
    list<Creature*>* getPlants();

    void addCreature(Creature* creature);
    void addPlant(Creature* plant);
    void setBoundriesDirty();

 private:
    Map m_map;
    Player m_player;
    list<Creature*> m_creatures;
    list<Creature*> m_plants;

    BoundryScanner m_scanner;
    bool m_boundries_dirty;

    int m_time;
    int m_creature_count;
    int m_plant_count;
};

} // walls

#endif // WORLD_H
