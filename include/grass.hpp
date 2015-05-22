/**
 *  @author Barry Gackle
 */

#ifndef GRASS_HPP
#define GRASS_HPP

// Local Headers
#include "appearance.hpp"
#include "object_imp.hpp"
#include "maplocation.hpp"

namespace walls {
class World;
class MapLocation;

class Grass : public ObjectImp {
 public:
    Grass(World* world, const MapLocation& location);

    virtual void update(int time);

    virtual Appearance appearance() const;

    virtual void die();

 protected:
    void reproduce();
    void seed(const MapLocation& location);

 private:
    bool m_flower;
    int m_flower_time;
    int m_seed_time;
    int m_age;
    static const int k_flower_min;
    static const int k_flower_max;
    static const int k_seed_max;
};

} // namespace walls

#endif // GRASS_HPP
