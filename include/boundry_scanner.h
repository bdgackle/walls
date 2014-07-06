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

using std::deque;

class BoundryScanner
{
 public:
    BoundryScanner(Map *map);
    virtual ~BoundryScanner();

    void updateBoundry();

 protected:
    void popLocation();
    void pushLocation(int index);

 private:
    deque<int> m_stack;
    Map *m_map;
};

} // namespace walls

#endif // BOUNDRY_SCANNER_H
