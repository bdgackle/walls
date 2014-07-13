/**
 *  @author Barry Gackle
 */

#ifndef FERRET_H
#define FERRET_H

// Internal Headers
#include "creature.h"

namespace walls{

class World;
class MapLocation;

class Ferret : public Creature
{
 public:
    Ferret(World* world, const MapLocation & location);
    virtual ~Ferret();

    virtual void update(int time);

    char getDisplayChar() const;
};

} // walls

#endif // CREATURE_H
