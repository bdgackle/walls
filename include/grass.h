/**
 *  @author Barry Gackle
 */

#ifndef GRASS_H
#define GRASS_H

// Internal Headers
#include "plant.h"
#include "maplocation.h"

namespace walls {
    class World;
    class MapLocation;
}

namespace walls {

class Grass : public Plant {
 public:
    Grass(World* world, const MapLocation& location);
    virtual ~Grass();

    virtual void update(int time);

    char getDisplayChar() const;
    int getDisplayColor() const;

 protected:
    void reproduce();
    void seed(const MapLocation& location);

 private:
    bool m_flower;
};

} // walls

#endif // GRASS_H
