/**
 *  @author Barry Gackle
 */

#ifndef BLOCK_HPP
#define BLOCK_HPP

// Local Headers
#include "game_constants.hpp"
#include "object_list.hpp"

namespace walls {
class Object;

class Block {
 public:
    Block();

    BlockType getType() const;
    bool getIsOutdoors() const;
    bool getIsEdge() const;
    bool getIsMovementBoundry() const;
    bool getIsIndoorBoundry() const;
    bool getHasPlant() const;
    bool getHasCreature() const;
    bool getHasPrey() const;

    void setType(BlockType type);
    void setIsOutdoors(bool outdoors);
    void setIsEdge(bool edge);

    void addCreature(Object* creature);
    void addPlant(Object* plant);
    void addPrey(Object* prey);
    Object* getCreature();
    Object* getPlant();
    Object* getPrey();
    void removeCreature(Object* creature);
    void removePlant(Object* plant);
    void removePrey(Object* prey);

 private:
    BlockType m_type;
    bool m_is_outdoors;
    bool m_is_edge;
    ObjectList m_creatures;
    ObjectList m_prey;
    ObjectList m_plants;
};

} // namespace walls

#endif // BLOCK_HPP
