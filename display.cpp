/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// C Standard Headers
#include <stddef.h>
#include <stdio.h>

// Internal Headers
#include "display.h"
#include "wall_map.h"

namespace walls{

void Display::printMap(const WallMap& map)
{
    for (size_t y = 0; y < map.getHeight(); y++)
    {
        for (size_t x = 0; x < map.getWidth(); x++)
        {
            printf("%c",map.getWall(x,y));
        }
        printf("\n");
    }
}

} // walls
