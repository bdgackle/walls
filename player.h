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

class Player
{
 public:
    Player();
    virtual ~Player();

    MapLocation getLocation() const;
    PlayerStatus getStatus() const;
    void setLocation(const MapLocation& location, const Map *map);

 protected:
    void setStatus(PlayerStatus status);

 private:
    MapLocation m_location;
    PlayerStatus m_status;
};

} // namespace walls

#endif // PLAYER_H
