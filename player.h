/**
 *  @author Barry Gackle
 *  @author 29 June 2014
 */

#ifndef PLAYER_H
#define PLAYER_H

// Internal Headers
#include "maplocation.h"

namespace walls
{

class Player
{
 public:
    const static int STATUS_HAPPY = 0;
    const static int STATUS_VENGEFUL = 1;

    Player();
    virtual ~Player();

    MapLocation getLocation() const;
    int getStatus() const;
    void setLocation(const MapLocation& location, const Map *map);

 protected:
    void setStatus(int status);

 private:
    MapLocation m_location;
    int m_status;
};

} // namespace walls

#endif // PLAYER_H
