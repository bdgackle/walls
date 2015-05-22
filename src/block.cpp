/**
 *  @author Barry Gackle
 */

// Local Headers
#include "block.hpp"
#include "game_constants.hpp"

namespace walls {

Block::Block() :
    m_type(GROUND),
    m_is_outdoors(true),
    m_is_edge(false) {}

BlockType Block::getType() const
{
    return m_type;
}

bool Block::getIsOutdoors() const
{
    return m_is_outdoors;
}

bool Block::getIsEdge() const
{
    return m_is_edge;
}

bool Block::getIsMovementBoundry() const
{
    switch(m_type) {
    case WALL:
    case ROCK:
    case SAPLING:
        return true;
        break;

    default:
        return false;
    }
}

bool Block::getIsIndoorBoundry() const
{
    switch(m_type) {
        case WALL:
        case DOOR:
            return true;
            break;

        default:
            return false;
    }
}

bool Block::getHasPlant() const
{
    if (m_plants.getCount() > 0)
        return true;
    else
        return false;
}

bool Block::getHasCreature() const
{
    if (m_creatures.getCount() > 0)
        return true;
    else
        return false;
}

bool Block::getHasPrey() const
{
    if (m_prey.getCount() > 0)
        return true;
    else
        return false;
}

void Block::setType(BlockType type)
{
    m_type = type;
}

void Block::setIsOutdoors(bool outdoors)
{
    m_is_outdoors = outdoors;
}

void Block::setIsEdge(bool edge)
{
    m_is_edge = edge;
}

void Block::addCreature(Object* creature)
{
    m_creatures.addObject(creature);
}

void Block::addPlant(Object* plant)
{
    m_plants.addObject(plant);
}

void Block::addPrey(Object* prey)
{
    m_prey.addObject(prey);
}

const Object& Block::getCreature() const
{
    m_creatures.getFirstObject();
}

Object* Block::getCreature()
{
    m_creatures.getFirstObject();
}

const Object& Block::getPlant() const
{
    m_plants.getFirstObject();
}

Object* Block::getPlant()
{
    m_plants.getFirstObject();
}

const Object& Block::getPrey() const
{
    m_prey.getFirstObject();
}

Object* Block::getPrey()
{
    m_prey.getFirstObject();
}

void Block::removeCreature(Object* creature)
{
    m_creatures.removeObject(creature);
}

void Block::removePlant(Object* plant)
{
    m_plants.removeObject(plant);
}

void Block::removePrey(Object* prey)
{
    m_prey.removeObject(prey);
}

} // namespace walls
