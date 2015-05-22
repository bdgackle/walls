/**
 *  @author Barry Gackle
 */

#ifndef MAP_HPP
#define MAP_HPP

// Local Headers
#include "game_constants.hpp"

// C++ Standard Headers
#include <vector>

namespace walls {
class MapLocation;
class Object;

class Map {
 public:
    virtual ~Map() {}

    // Map Properties
    virtual int height() const = 0;
    virtual int width() const = 0;
    virtual int depth() const = 0;
    virtual int blockCount() const = 0;

    virtual bool exists(const MapLocation& loc) const = 0;
    virtual bool exists(int index) const = 0;

    virtual void edges(std::vector<int>* edges, int depth) const = 0;
    virtual void adjacent(const MapLocation& loc,
                          std::vector<MapLocation>* adjacent,
                          int distance) const = 0;

    // Specific block property accessors
    virtual BlockType blockType(const MapLocation& loc) const = 0;

    virtual bool isOutdoors(const MapLocation& loc) const = 0;
    virtual bool isEdge(int index) const = 0;
    virtual bool isEdge(const MapLocation& loc) const = 0;
    virtual bool isMovementBoundry(const MapLocation& loc) const = 0;
    virtual bool isIndoorBoundry(int index) const = 0;
    virtual bool isIndoorBoundry(const MapLocation& loc) const = 0;
    virtual bool hasCreature(const MapLocation& loc) const = 0;
    virtual bool hasPlant(const MapLocation& loc) const = 0;
    virtual bool hasPrey(const MapLocation& loc) const = 0;

    // Specific block property mutators
    virtual void blockType(const MapLocation& loc, BlockType type) = 0;
    virtual void isOutdoors(int index, bool outdoors) = 0;
    virtual void isOutdoors(const MapLocation& loc, bool outdoors) = 0;
    virtual void isEdge(const MapLocation& loc, bool edge) = 0;

    virtual void addCreature(const MapLocation& loc,
                             Object* creature) = 0;
    virtual void addPlant(const MapLocation&  loc,
                          Object* plant) = 0;
    virtual void addPrey(const MapLocation& loc,
                         Object* prey) = 0;
    virtual void removeCreature(const MapLocation& loc,
                                Object* creature) = 0;
    virtual void removePlant(const MapLocation&  loc,
                             Object* plant) = 0;
    virtual void removePrey(const MapLocation& loc,
                            Object* prey) = 0;
    virtual const Object& creature(const MapLocation& loc) const = 0;
    virtual Object* creature(const MapLocation& loc) = 0;
    virtual const Object& plant(const MapLocation& loc) const = 0;
    virtual Object* plant(const MapLocation& loc) = 0;
    virtual const Object& prey(const MapLocation& loc) const = 0;
    virtual Object* prey(const MapLocation& loc) = 0;

    virtual void clearIsOutdoors() = 0;

};

} // walls

#endif // MAP_HPP
