/**
 *  @author Barry Gackle
 *  @author 21 June 2014
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "game_constants.h"

namespace walls{

class Block
{
 public:
    Block();
    virtual ~Block();

    BlockType getType() const;
    bool getIsOutdoors() const;
    bool getIsMovementBoundry() const;
    bool getIsIndoorBoundry() const;
    bool getIsUpdated() const;
    bool getIsEdge() const;

    void setType(BlockType type);
    void setIsOutdoors(bool outdoors);
    void setIsUpdated(bool updated);
    void setIsEdge(bool edge);

 private:
    BlockType m_type;
    bool m_is_outdoors;
    bool m_is_updated;
    bool m_is_edge;
};

} // walls

#endif // BLOCK_H
