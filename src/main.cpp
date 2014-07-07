/**
 *  @author: Barry Gackle
 *  @author: 21 June 2014
 */

// C Standard Headers
#include <stdio.h>

// Internal Headers
#include "world.h"
#include "maplocation.h"
#include "ui.h"

int main()
{
    walls::World world(200, 200, 1);
    world.init(42);

    walls::UserInterface ui;
    walls::MapLocation player_location(world.getPlayerLocation());

    ui.start(&world, player_location);

    return 0;
}
