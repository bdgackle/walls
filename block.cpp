/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// Internal Headers
#include "block.h"
#include "game_constants.h"

namespace walls{

Block::Block() :
m_type(GROUND),
m_is_outdoors(true),
m_is_updated(false) {}

Block::~Block() {}

BlockType Block::getType() const
{
    return m_type;
}

bool Block::getIsOutdoors() const
{
    return m_is_outdoors;
}

bool Block::getIsMovementBoundry() const
{
    switch(m_type)
    {
        case WALL:
            return true;
            break;

        default:
            return false;
    }
}

bool Block::getIsIndoorBoundry() const
{
    switch(m_type)
    {
        case WALL:
        case DOOR:
            return true;
            break;

        default:
            return false;
    }
}

bool Block::getIsUpdated() const
{
    return m_is_updated;
}

void Block::setType(BlockType type)
{
    m_type = type;
}

void Block::setIsOutdoors(bool outdoors)
{
    m_is_outdoors = outdoors;
}

void Block::setIsUpdated(bool updated)
{
    m_is_updated = updated;
}

} // walls
