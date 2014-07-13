/**
 *  @author Barry Gackle
 */

#ifndef BLOCK_H
#define BLOCK_H

// Internal Headers
#include "game_constants.h"
#include "thing.h"

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
    bool getIsWaterBoundry() const;
    bool getIsEdge() const;
    const vector<Thing*>* getContents() const;

    void setType(BlockType type);
    void setIsOutdoors(bool outdoors);
    void setIsEdge(bool edge);
    void addToContents(Thing* new_thing);
    void removeFromContents(Thing* old_thing);

 private:
    BlockType m_type;
    bool m_is_outdoors;
    bool m_is_edge;
    vector<Thing*> m_contents;
};

} // walls

#endif // BLOCK_H
