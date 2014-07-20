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
#include "object_list.h"

namespace walls {
    class Object;
}

using std::list;

namespace walls {

class World {
 public:
    World(int width, int height, int depth);
    virtual ~World();

    void update(int time);

    const Map& getMap() const;
    const Player& getPlayer() const;
    const ObjectList& getCreatures() const;
    const ObjectList& getPlants() const;
    const ObjectList& getPrey() const;

    int getTime() const;
    int getCreatureCount() const;
    int getPlantCount() const;
    int getPreyCount() const;
    int getUpdateTime() const;

    Map* getMap();
    Player* getPlayer();
    ObjectList* getCreatures();
    ObjectList* getPlants();
    ObjectList* getPrey();

    void addCreature(Object* creature);
    void addPlant(Object* plant);
    void addPrey(Object* prey);

    void startClock() const;
    void stopClock() const;

    void setBoundriesDirty();

 private:
    Map m_map;
    Player m_player;
    ObjectList m_creatures;
    ObjectList m_plants;
    ObjectList m_prey;

    BoundryScanner m_scanner;
    bool m_boundries_dirty;

    int m_time;

    mutable clock_t m_start;
    mutable clock_t m_stop;
    mutable int m_update_time;
};

} // walls

#endif // WORLD_H
