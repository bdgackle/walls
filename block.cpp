/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// C Standard Headers
#include "stddef.h"

// Internal Headers
#include "block.h"

namespace walls{

Block::Block() :
m_north(NULL),
m_south(NULL),
m_east(NULL),
m_west(NULL),
m_x(0),
m_y(0),
m_type(GROUND),
m_has_player(false),
m_has_cursor(false)
{
}

char Block::getTop()
{
    if (m_type == WALL)
        return m_type;
    else if (m_has_player)
        return PLAYER;
    else if (m_has_cursor)
        return CURSOR;
    else
        return m_type;
}

} // walls
