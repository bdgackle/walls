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
    int m_flower_time;
    int m_seed_time;
    static const int k_flower_min;
    static const int k_flower_max;
    static const int k_seed_max;
};

} // walls

#endif // GRASS_H
