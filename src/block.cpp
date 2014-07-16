/**
 *  @author Barry Gackle
 */

// Internal Headers
#include "block.h"
#include "game_constants.h"

namespace walls{

Block::Block() :
m_type(GROUND),
m_is_outdoors(true),
m_is_edge(false) {}

Block::~Block() {}

BlockType Block::getType() const { return m_type; }

bool Block::getIsOutdoors() const { return m_is_outdoors; }

bool Block::getIsEdge() const { return m_is_edge; }

bool Block::getIsMovementBoundry() const {
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

bool Block::getIsIndoorBoundry() const {
    switch(m_type) {
        case WALL:
        case DOOR:
            return true;
            break;

        default:
            return false;
    }
}

bool Block::getIsEmpty() const { 
    if (m_plants.getCount() <= 0)
        return true;
    else
        return false;
}

void Block::setType(BlockType type) {
    m_type = type;
}

void Block::setIsOutdoors(bool outdoors) {
    m_is_outdoors = outdoors;
}

void Block::setIsEdge(bool edge) {
    m_is_edge = edge;
}

void Block::addCreature(Object* creature) {
    m_creatures.addObject(creature);
}

void Block::addPlant(Object* plant) { m_plants.addObject(plant); }

Object* Block::getPlant() {
    m_plants.getFirstObject();
}

void Block::removeCreature(Object* creature) { 
    m_creatures.removeObject(creature);
}

void Block::removePlant(Object* plant) { m_plants.removeObject(plant); }

} // walls
