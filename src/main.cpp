/**
 *  @author: Barry Gackle
 *  @author: 21 June 2014
 */

// C Standard Headers
#include <stdlib.h>

// Internal Headers
#include "world.h"
#include "ui.h"
#include "maplocation.h"
#include "map.h"
#include "game_constants.h"
#include "ferret.h"
#include "grass.h"

using walls::World;
using walls::UserInterface;
using walls::MapLocation;
using walls::Map;
using walls::Ferret;
using walls::Grass;

int main()
{
    World world(200, 200, 4);

    // Random number for seeding
    srand(42);

    // Seed the world with some random rocks/trees/pebbles
    Map* map = world.getMap();
    for (int x = 0; x < map->getWidth(); x++) {
        for (int y = 0; y < map->getHeight(); y++) {
            int random_number = rand() % 1000;

            if (random_number < 5)
                map->getBlock(MapLocation(x, y, 0))->setType(walls::ROCK);
            else if (random_number < 10)
                map->getBlock(MapLocation(x, y, 0))->setType(walls::SAPLING);
            else if (random_number < 20)
                world.addCreature(new Grass(&world, MapLocation(x, y, 0)));
        }
    }

    // Seed the world with some random ferrets
    for (int i = 0; i < 10; i++) {
        Ferret* ferret = new Ferret(&world, MapLocation(5,i,0));
        world.addCreature(ferret);
    }

    // Make and start the ui
    UserInterface ui(&world);
    ui.init();
    ui.start();

    return 0;
}
