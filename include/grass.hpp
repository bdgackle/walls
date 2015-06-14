/**
 *  @author Barry Gackle
 */

#ifndef GRASS_HPP
#define GRASS_HPP

// Local Headers
#include "plant.hpp"
#include "maplocation.hpp"

namespace walls {
class World;
class MapLocation;

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

} // namespace walls

#endif // GRASS_HPP
