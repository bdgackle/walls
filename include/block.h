/**
 *  @author Barry Gackle
 */

#ifndef BLOCK_H
#define BLOCK_H

// C++ Standard Headers
#include <list>

// Internal Headers
#include "game_constants.h"

namespace walls {
    class Object;
}

using std::list;

namespace walls {

class Block
{
 public:
    Block();
    virtual ~Block();

    BlockType getType() const;
    bool getIsOutdoors() const;
    bool getIsEdge() const;
    bool getIsMovementBoundry() const;
    bool getIsIndoorBoundry() const;
    bool getIsEmpty() const;

    void setType(BlockType type);
    void setIsOutdoors(bool outdoors);
    void setIsEdge(bool edge);

    void addCreature(const Object* creature);
    void addPlant(const Object* plant);
    void removeCreature(const Object* creature);
    void removePlant(const Object* plant);

 private:
    BlockType m_type;
    bool m_is_outdoors;
    bool m_is_edge;
    list<const Object*> m_creatures;
    list<const Object*> m_plants;
};

} // walls

#endif // BLOCK_H
