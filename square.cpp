/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */


// C Standard Headers
#include <stddef.h>

// Internal Headers
#include "square.h"

namespace walls{

Square::Square() :
m_north(NULL),
m_south(NULL),
m_east(NULL),
m_west(NULL),
m_x(0),
m_y(0),
m_is_wall(false),
m_is_outside(false)
{
}

bool Square::checkNeighbors()
{
    // Squares touching the edge are outside, and we need to be careful
    // not to dereference null pointers
    if ((getNorth() == NULL) ||
        (getSouth() == NULL) ||
        (getEast() == NULL) ||
        (getWest() == NULL))
    {
        return true;
    }

    if ((getNorth()->isOutside()) ||
        (getSouth()->isOutside()) ||
        (getWest()->isOutside()) ||
        (getWest()->isOutside()))
    {
        return true;
    }

    return false;
}

} // walls
