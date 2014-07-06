/**
 *  @author Barry Gackle
 *  @author 23 June 2014
 */

#ifndef MAP_H
#define MAP_H

// C++ Standard Headers
#include <deque>

// Internal Headers
#include "game_constants.h"

namespace walls{

class Block;
class MapLocation;

using std::deque;

class Map
{
 public:
    Map(int width, int height, int depth);
    virtual ~Map();

    int getHeight() const;
    int getWidth() const;
    int getDepth() const;

    bool exists(const MapLocation& location) const;
    bool exists(int index) const;
    void getEdges(deque<int>* edges, int depth);

    BlockType getType(const MapLocation& location) const;
    BlockType getType(int index) const;
    bool getIsOutdoors(const MapLocation& location) const;
    bool getIsOutdoors(int index) const;
    bool getIsMovementBoundry(const MapLocation& location) const;
    bool getIsMovementBoundry(int index) const;
    bool getIsIndoorBoundry(const MapLocation& location) const;
    bool getIsIndoorBoundry(int index) const;
    bool getIsUpdated(const MapLocation& location) const;
    bool getIsUpdated(int index) const;
    bool getIsEdge(const MapLocation& location) const;
    bool getIsEdge(int index) const;

    void setType(const MapLocation& location, BlockType type);
    void setType(int index, BlockType type);
    void setIsOutdoors(const MapLocation& location, bool isOutdoors);
    void setIsOutdoors(int index, bool isOutdoors);
    void setIsUpdated(const MapLocation& location, bool isUpdated);
    void setIsUpdated(int index, bool isUpdated);
    void setIsEdge(const MapLocation& location, bool isEdge);
    void setIsEdge(int index, bool isEdge);
    void clearIsUpdated();
    void clearIsOutdoors();

 protected:
    void addLocationToList(int index,
                           deque<int>* list);

    Block* getBlock(const MapLocation& location) const;
    Block* getBlock(int index) const;

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

    const int m_max_index;
};

} // walls

#endif // MAP_H
