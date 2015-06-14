/**
 *  @author: Barry Gackle
 *  @author: 21 June 2014
 */

// C Standard Headers
#include <stdlib.h>

// Local Headers
#include "world.hpp"
#include "ui.hpp"
#include "maplocation.hpp"
#include "map.hpp"
#include "game_constants.hpp"
#include "ferret.hpp"
#include "bunny.hpp"
#include "grass.hpp"

using walls::World;
using walls::UserInterface;
using walls::MapLocation;
using walls::Map;
using walls::Ferret;
using walls::Bunny;
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
            else if (random_number < 1000)
                world.addPlant(new Grass(&world, MapLocation(x, y, 0)));
        }
    }

    // Seed the world with some random ferrets
    for (int i = 0; i < 50; i++) {
         world.addCreature(new Ferret(&world, MapLocation(i,i,0)));
    }
    world.addCreature(new Ferret(&world, MapLocation(100,105,0)));

    for (int i = 0; i < 100; i++) {
        world.addPrey(new Bunny(&world, MapLocation(15,i,0)));
        world.addPrey(new Bunny(&world, MapLocation(115,i,0)));
        world.addPrey(new Bunny(&world, MapLocation(185,i,0)));
    }

    // Make and start the ui
    UserInterface ui(&world);
    ui.init();
    ui.start();

    return 0;
}
