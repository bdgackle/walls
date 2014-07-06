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
    void getEdges(deque<MapLocation>* edges, int depth);

    BlockType getType(const MapLocation& location) const;
    bool getIsOutdoors(const MapLocation& location) const;
    bool getIsMovementBoundry(const MapLocation& location) const;
    bool getIsIndoorBoundry(const MapLocation& location) const;
    bool getIsUpdated(const MapLocation& location) const;

    void setType(const MapLocation& location, BlockType type);
    void setIsOutdoors(const MapLocation& location, bool isOutdoors);
    void setIsUpdated(const MapLocation& location, bool isUpdated);
    void clearIsUpdated();
    void clearIsOutdoors();

 protected:
    void addLocationToList(const MapLocation& location,
                           deque<MapLocation>* list);

    Block* getBlock(const MapLocation& location) const;

 private:
    Block* m_blocks;
    const int m_width;
    const int m_height;
    const int m_depth;
};

} // walls

#endif // MAP_H
