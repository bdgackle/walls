/**
 *  @author Barry Gackle
 *  @author 29 June 2014
 */

#ifndef PLAYER_H
#define PLAYER_H

// Internal Headers
#include "maplocation.h"
#include "game_constants.h"

namespace walls
{

class Map;
class World;

class Player
{
 public:
    Player(World* world);
    virtual ~Player();

    PlayerStatus getStatus() const;
    MapLocation getLocation() const;

    void move(int d_x, int d_y, int d_z);

    void setLocation(const MapLocation& location);

 protected:
    void setStatus(PlayerStatus status);

 private:
    MapLocation m_location;
    PlayerStatus m_status;
    World* m_world;
};

} // namespace walls

#endif // PLAYER_H
