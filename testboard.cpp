/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Standard Headers
#include <stddef.h>

// External Headers
#include <gperftools/profiler.h>

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
    WallMap* wall_map2 = new WallMap(20,20);

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

    const char * map2 = "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "...................."
                       "....................";

    wall_map->setWall(map);
    wall_map2->setWall(map2);
    test2->setWalls(*wall_map);

    nextTest("Construction");
    Display::printBoard(*test1);

    nextTest("setWalls()");
    Display::printBoard(*test2);

//    ProfilerStart("./board.prof");
//    for (int i = 0; i < 100000; i++)
//    {
        test2->setWalls(*wall_map);
        while(test2->scan()) {
            nextTest("Scan");
            Display::printBoard(*test2);
        }
//        test2->setWalls(*wall_map2);
//        while(test2->scan()) {
//            nextTest("Scan");
//        }
//    }
 //   ProfilerStop();
                    
    delete test1;
    delete test2;
    delete wall_map;
    return done();
}
