/**
 *  @author Barry Gackle
 */

#ifndef MAP_IMP_HPP
#define MAP_IMP_HPP

// Local Headers
#include "block.hpp"
#include "map.hpp"

// C++ Standard Headers
#include <vector>

namespace walls {
class MapLocation;
class UpdateMap;

class MapImp : public Map {
 public:
    MapImp(int width, int height, int depth);
    virtual ~MapImp();

    // Map Properties
    virtual int height() const;
    virtual int width() const;
    virtual int depth() const;
    virtual int blockCount() const;

    virtual bool exists(const MapLocation& loc) const;
    virtual bool exists(int index) const;

    virtual void edges(std::vector<int>* edges, int depth) const;
    void adjacent(const MapLocation& loc,
                  std::vector<MapLocation>* adjacent,
                  int distance) const;

    // Specific block property accessors
    virtual BlockType blockType(const MapLocation& loc) const;

    virtual bool isOutdoors(const MapLocation& loc) const;
    virtual bool isEdge(int index) const;
    virtual bool isEdge(const MapLocation& loc) const;
    virtual bool isMovementBoundry(const MapLocation& loc) const;
    virtual bool isIndoorBoundry(int index) const;
    virtual bool isIndoorBoundry(const MapLocation& loc) const;
    virtual bool hasCreature(const MapLocation& loc) const;
    virtual bool hasPlant(const MapLocation& loc) const;
    virtual bool hasPrey(const MapLocation& loc) const;

    // Specific block property mutators
    virtual void blockType(const MapLocation& loc, BlockType type);
    virtual void isOutdoors(int index, bool outdoors);
    virtual void isOutdoors(const MapLocation& loc, bool outdoors);
    virtual void isEdge(const MapLocation& loc, bool edge);

    virtual void addCreature(const MapLocation& loc, Object* creature);
    virtual void addPlant(const MapLocation& loc, Object* creature);
    virtual void addPrey(const MapLocation& loc, Object* creature);
    virtual void removeCreature(const MapLocation& loc, Object* creature);
    virtual void removePlant(const MapLocation&, Object* creature);
    virtual void removePrey(const MapLocation&, Object* creature);
    virtual const Object& creature(const MapLocation& loc) const;
    virtual Object* creature(const MapLocation& loc);
    virtual const Object& plant(const MapLocation& loc) const;
    virtual Object* plant(const MapLocation& loc);
    virtual const Object& prey(const MapLocation& loc) const;
    virtual Object* prey(const MapLocation& loc);

    const Block& block(const MapLocation& loc) const;
    Block* block(const MapLocation& location);
    const Block& block(int index) const;
    Block* block(int index);

    void clearIsOutdoors();

    void pushIndex(int index, std::vector<int>* list, UpdateMap* done) const;

 private:
    Block* m_blocks;
    Block m_invalid_block;

    const int m_width;
    const int m_height;
    const int m_depth;

    const int m_n_bound;
    const int m_s_bound;
    const int m_e_bound;
    const int m_w_bound;
    const int m_u_bound;
    const int m_d_bound;

    const int m_block_count;
};

} // walls

#endif // MAP_IMP_HPP
