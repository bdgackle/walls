/**
 *  @author Barry Gackle
 */

#ifndef BUNNY_HPP
#define BUNNY_HPP

// Internal Headers
#include "creature.hpp"

namespace walls{

class World;
class MapLocation;

class Bunny : public Creature {
 public:
    Bunny(World* world, const MapLocation& location);
    virtual ~Bunny();

    virtual void update(int time);
    virtual void breed();

    char getDisplayChar() const;
    int getDisplayColor() const;
};

} // walls

#endif // BUNNY_HPP
