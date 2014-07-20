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

class Ferret : public Creature {
 public:
    Ferret(World* world, const MapLocation & location);
    virtual ~Ferret();

    virtual void update(int time);
    virtual void breed();

    char getDisplayChar() const;
    int getDisplayColor() const;

 private:
    int m_visual_range;

    static const int INITIAL_FOOD_VALUE = 100;
    static const int BREED_FOOD_VALUE = 500;
    static const int POST_BREED_FOOD_VALUE = 400;
    static const int BUNNY_NUTRITION = 50;
    static const int MOVE_NUTRITION = 1;
    static const int VISUAL_RANGE = 4;
};

} // walls

#endif // CREATURE_H
