/**
 *  @author Barry Gackle
 */

#ifndef MAP_HPP
#define MAP_HPP

// Local Headers
#include "block.hpp"

// C++ Standard Headers
#include <list>

namespace walls {
class MapLocation;
class UpdateMap;

class Map {
 public:
    Map(int width, int height, int depth);
    virtual ~Map();

    int getHeight() const;
    int getWidth() const;
    int getDepth() const;
    int getBlockCount() const;
    int getMaxIndex() const;

    const Block& getBlock(const MapLocation& location) const;
    Block* getBlock(const MapLocation& location);

    const Block& getBlock(int index) const;
    Block* getBlock(int index);

    bool exists(const MapLocation& location) const;
    bool exists(int index) const;

    void getEdges(std::list<int>* edges, int depth) const;
    void getAdjacent(const MapLocation& location,
                     std::list<MapLocation>* adjacent,
                     int distance) const;

    void clearIsOutdoors();

 protected:
    void pushIndex(int index, std::list<int>* list, UpdateMap* done) const;

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

#endif // MAP_HPP