/**
 *  @author: Barry Gackle
 *  @author: 21 June 2014
 */

// Internal Headers
#include "world.h"
#include "maplocation.h"
#include "ui.h"

int main()
{
    walls::World world(200, 200, 4);
    world.init(42);

    walls::UserInterface ui;
    ui.init(&world);

    ui.start();

    return 0;
}
