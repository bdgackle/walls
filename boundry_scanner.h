/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef BOUNDRY_SCANNER_H
#define BOUNDRY_SCANNER_H

// C++ Standard Headers
#include <vector>

namespace walls
{

class Map;
class MapLocation;

using std::vector;

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
    vector<MapLocation> m_stack;
    Map *m_map;
};

} // namespace walls

#endif // BOUNDRY_SCANNER_H
