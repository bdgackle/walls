/**
 *  @author Barry Gackle
 */

#ifndef BLOCK_H
#define BLOCK_H

// Internal Headers
#include "game_constants.h"

namespace walls {
    class Creature;
}

namespace walls {

class Block
{
 public:
    Block();
    virtual ~Block();

    BlockType getType() const;
    bool getIsOutdoors() const;
    bool getIsMovementBoundry() const;
    bool getIsIndoorBoundry() const;
    bool getIsWaterBoundry() const;
    bool getIsEdge() const;
    bool getIsEmpty() const;

    void setType(BlockType type);
    void setIsOutdoors(bool outdoors);
    void setIsEdge(bool edge);

    void addCreature(const Creature* creature);
    void removeCreature();

 private:
    BlockType m_type;
    bool m_is_outdoors;
    bool m_is_edge;
    const Creature* m_creature;
};

} // walls

#endif // BLOCK_H
