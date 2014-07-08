/**
 *  @author Barry Gackle
 */

#ifndef WORLD_H
#define WORLD_H

// C++ Standard Headers
#include <vector>

// Internal Headers
#include "boundry_scanner.h"
#include "player.h"
#include "map.h"

// Forward Declarations
namespace walls {
    class MapLocation;
    class Creature;
}

// Using
using std::vector;

namespace walls{

class World
{
 public:
    World(int width, int height, int depth);
    virtual ~World();

    void init(unsigned int seed);
    void update(int time);

    const Map& getMap() const;
    const Player& getPlayer() const;
    const vector<Creature*>& getCreatures() const;

    Map* getMap();
    Player* getPlayer();
    vector<Creature*>* getCreatures();

    void addCreature(Creature* creature);
    void setBoundriesDirty();

 private:
    Map m_map;
    Player m_player;
    vector<Creature*> m_creatures;

    BoundryScanner m_scanner;
    bool m_boundries_dirty;
};

} // walls

#endif // WORLD_H
