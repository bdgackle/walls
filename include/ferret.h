/**
 *  @author Barry Gackle
 *  @author 6 July 2014
 */

#ifndef FERRET_H
#define FERRET_H

#include "creature.h"
#include "maplocation.h"
#include "map.h"

namespace walls{

class Ferret : public Creature
{
 public:
    Ferret();
    virtual ~Ferret();

    virtual void init(MapLocation location, Map* map);

    virtual void update();

    char getDisplayChar() const;
    void move(int d_x, int d_y, int d_z);
};

} // walls

#endif // CREATURE_H
