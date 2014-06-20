/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// C Standard Headers
#include <stddef.h>
#include <stdio.h>

// Internal Headers
#include "display.h"
#include "board.h"
#include "wall_map.h"

namespace walls{

void Display::printBoard(const Board& board)
{
    for (size_t y = 0; y < board.getHeight(); y++)
    {
        for (size_t x = 0; x < board.getWidth(); x++)
        {
            if (board.isWall(x,y))
                printf("X ");
            else if (board.isOutside(x,y))
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

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
