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

using std::vector;

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
    vector<int> m_stack;
    Map* m_map;
    bool* m_updated;
};

} // namespace walls

#endif // BOUNDRY_SCANNER_H
