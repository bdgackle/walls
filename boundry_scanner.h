/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef BOUNDRY_SCANNER_H
#define BOUNDRY_SCANNER_H

// C++ Standard Headers
#include <deque>

namespace walls
{

class Map;
class MapLocation;

using std::deque;

class BoundryScanner
{
 public:
    BoundryScanner(Map *map);
    virtual ~BoundryScanner();

    void updateBoundry();

 protected:
    void popLocation();
    void pushLocation(MapLocation location);

 private:
    deque<MapLocation> m_stack;
    Map *m_map;
    int m_perf_count; //DEBUG: Used only for profiling 
};

} // namespace walls

#endif // BOUNDRY_SCANNER_H
