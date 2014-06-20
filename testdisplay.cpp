/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Standard Headers
#include <stddef.h>

// Internal Headers
#include "wall_map.h"
#include "display.h"
#include "ut.h"

using walls::Display;
using walls::WallMap;

int main()
{
    WallMap* test1 = new WallMap(3,5);
    WallMap* test2 = new WallMap(3,5);

    const char * map = "..X.."
                       ".X.X."
                       "X.X.X";

    test2->setWall(map);
                    
    // Check initial values
    nextTest("Print blank map");
    Display::printMap(*test1);

    nextTest("Print populated map");
    Display::printMap(*test2);

    delete test1;
    delete test2;
    return done();
}
