/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

#ifndef WORLD_H
#define WORLD_H

// C++ Standard Headers
#include <vector>

// Internal Headers
#include "game_constants.h"
#include "boundry_scanner.h"
#include "player.h"
#include "map.h"
#include "creature.h"

using std::vector;

namespace walls{

class MapLocation;

class World
{
 public:

    World(int width, int height, int depth);
    virtual ~World();

    void init(unsigned int seed);

    void doCommand(Command command, const MapLocation& location);

    MapLocation getPlayerLocation() const;
    PlayerStatus getPlayerStatus() const;
    BlockType getBlockType(const MapLocation& location) const;

    vector<Creature*> getCreatures() const;
    void addCreature(Creature* creature);

    const char* getCpuTime() const;

 protected:
    void movePlayer(int delta_x, int delta_y, int delta_z);
    void addWall(const MapLocation& location);
    void addDoor(const MapLocation& location);
    void addGround(const MapLocation& location);


    void setBoundriesDirty(bool dirty);
    bool getBoundriesDirty() const;

    void update();

 private:
    Map m_map;
    BoundryScanner m_scanner;
    Player m_player;
    vector<Creature*> m_creatures;

    bool m_boundries_dirty;
    char m_update_time[15];
};

} // walls

#endif // WORLD_H
