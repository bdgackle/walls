/**
 *  @author Barry Gackle
 */

#ifndef WATER_H
#define WATER_H

// Internal Headers
#include "thing.h"

namespace walls{

class World;

class Water : public Thing
{
 public:
    Water();
    virtual ~Water();

    virtual void init(const MapLocation& location, World* world);

    virtual void update(int time);

    virtual char getDisplayChar();

 protected:
    int depth;
    int pressure;
    bool contained;
    bool active;
};

} // walls

#endif // WATER_H
