/**
 *  @author Barry Gackle
 */

#ifndef MAP_H
#define MAP_H

// C++ Standard Headers
#include <vector>

using std::vector;

namespace walls {

class Block;
class MapLocation;

class Map
{
 public:
    Map(int width, int height, int depth);
    virtual ~Map();

    void init();

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

    void getEdges(vector<int>* edges, int depth) const;

    void clearIsOutdoors();

 protected:
    void pushIndex(int index, vector<int>* list, vector<bool>* done) const;

 private:
    Block* m_blocks;
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

#endif // MAP_H
