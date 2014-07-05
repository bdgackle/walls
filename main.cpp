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
    walls::World world(1000, 1000, 1);
    walls::UserInterface ui;

    ui.start(&world, walls::MapLocation(0,0,0));

    return 0;
}
