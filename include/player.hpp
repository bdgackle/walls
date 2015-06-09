/**
 *  @author Barry Gackle
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

// Internal Headers
#include "maplocation.hpp"
#include "game_constants.hpp"

namespace walls {
    class Map;
    class World;
}

namespace walls {

class Player {
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

#endif // PLAYER_HPP
