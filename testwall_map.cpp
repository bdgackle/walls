/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Internal Headers
#include "wall_map.h"
#include "ut.h"

using walls::WallMap;

int main()
{
    WallMap* map = new WallMap(3,4);
    WallMap* test_map = new WallMap(1000,1000);
    WallMap* test_map2 = new WallMap(1001,1001);

    const char * map_string = "...."
                        ".X.X"
                        "..X.";

    map->setWall(map_string);

    nextTest("Constructor");
    result(test_map->getHeight() == 1000);
    result(test_map->getWidth() == 1000);
    result(test_map2->getHeight() == 1000);
    result(test_map2->getWidth() == 1000);

    nextTest("isWall()");
    result(map->isWall(0,0) == false);
    result(map->isWall(1,0) == false);
    result(map->isWall(2,0) == false);
    result(map->isWall(3,0) == false);
    result(map->isWall(0,1) == false);
    result(map->isWall(1,1) == true);
    result(map->isWall(2,1) == false);
    result(map->isWall(3,1) == true);
    result(map->isWall(0,2) == false);
    result(map->isWall(1,2) == false);
    result(map->isWall(2,2) == true);
    result(map->isWall(3,2) == false);

    nextTest("isWall() limits");
    result(map->isWall(10000,1) == false);
    result(map->isWall(1,10000) == false);
    result(map->isWall(5,1) == false);
    result(map->isWall(1,5) == false);

    nextTest("getWall()");
    result(map->getWall(0,0) == '.');
    result(map->getWall(1,0) == '.');
    result(map->getWall(2,0) == '.');
    result(map->getWall(3,0) == '.');
    result(map->getWall(0,1) == '.');
    result(map->getWall(1,1) == 'X');
    result(map->getWall(2,1) == '.');
    result(map->getWall(3,1) == 'X');
    result(map->getWall(0,2) == '.');
    result(map->getWall(1,2) == '.');
    result(map->getWall(2,2) == 'X');
    result(map->getWall(3,2) == '.');

    nextTest("getWall() limits");
    result(map->getWall(10000,1) == '\\');
    result(map->getWall(1,10000) == '\\');
    result(map->getWall(5,1) == '\\');
    result(map->getWall(1,5) == '\\');

    nextTest("constants");
    result(map->getWallChar() == 'X');
    result(map->getSizeMax() == 1000);
    result(map->getOutOfBoundsChar() == '\\');

    delete map;
    delete test_map;
    delete test_map2;
    return done();
}
