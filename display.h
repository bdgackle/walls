/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

#ifndef DISPLAY_H
#define DISPLAY_H

// Internal Headers
#include "wall_map.h"

namespace walls{

class Display
{
 public:
    Display() {}
    virtual ~Display() {}

    static void printMap(const WallMap& map);

 private:
};

} // walls

#endif //DISPLAY_H
