/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef BOUNDRY_SCANNER_HPP
#define BOUNDRY_SCANNER_HPP

// Local Headers
#include "update_map.hpp"

// C++ Standard Headers
#include <list>

namespace walls {
class Map;

class BoundryScanner
{
 public:
    BoundryScanner(Map* map);
    virtual ~BoundryScanner();

    void init(int map_size);

    void updateBoundry();

 protected:
    void popLocation();
    void pushLocation(int index);

 private:
    std::list<int> m_stack;
    Map* m_map;
    UpdateMap m_updated;
};

} // namespace walls

#endif // BOUNDRY_SCANNER_HPP
