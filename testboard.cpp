/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Standard Headers
#include <stddef.h>

// Internal Headers
#include "board.h"
#include "wall_map.h"
#include "display.h"
#include "ut.h"

using walls::Board;
using walls::Display;
using walls::WallMap;

int main()
{
    Board* test1 = new Board(20,20);
    Board* test2 = new Board(20,20);
    WallMap* wall_map = new WallMap(20,20);

    const char * map = "...................."
                       "..............XXXXXX"
                       "..............X....."
                       "..............X....."
                       "..............XXXXXX"
                       "...................."
                       ".....XXXXXXXX......."
                       ".....X......X......."
                       ".....X......X......."
                       ".....X......XXXXXXXX"
                       ".....X......X.X....."
                       "XXXXXX......XXXXXXXX"
                       ".....XXXXXXXX......."
                       ".....X.............."
                       "....XXXXXXXXXXXXX.XX"
                       "....X......XX.....X."
                       "....XX......X...XXXX"
                       ".....XXXX..XX...X..X"
                       "........XXXX....XXXX"
                       "....................";

    wall_map->setWall(map);
    test2->setWalls(*wall_map);

    //nextTest("Construction");
    //Display::printBoard(*test1);

    //nextTest("setWalls()");
    //Display::printBoard(*test2);

    for (int i = 0; i < 10000; i++)
    {
        delete test2;
        test2 = new Board(20,20);
        test2->setWalls(*wall_map);
        while(test2->scan())
        {
            //nextTest("scan()");
            //Display::printBoard(*test2);
        }
    }
                    
    delete test1;
    delete test2;
    delete wall_map;
    return done();
}
