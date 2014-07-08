/**
 *  @author Barry Gackle
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

    virtual void init(const MapLocation& location, World* world);

    virtual void update(int time);

    char getDisplayChar() const;

    void move(int d_x, int d_y, int d_z);
};

} // walls

#endif // CREATURE_H
