/**
 *  @author: Barry Gackle
 *  @author: 21 June 2014
 */

// C Standard Headers
#include <stdio.h>

// Internal Headers
#include "world.h"
#include "ui.h"

int main()
{
    walls::UserInterface ui;
    ui.init();

    walls::World world(ui.getWidth(), ui.getHeight());

    ui.setWorld(&world);
    ui.start();

    return 0;
}
