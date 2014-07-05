/*
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

#ifndef DISPLAY_H
#define DISPLAY_H

// Internal Headers
#include "game_constants.h"
#include "maplocation.h"

namespace walls{

class World;

class Display
{
 public:
    Display();
    virtual ~Display();

    void init(const World* world, const MapLocation& upper_left);
    void drawWorld();
    void drawStatus();
    void drawPlayer();
    void drawCursor(int curs_x, int curs_y, bool visible);

    void scrollRelative(int south, int east, int down);
    void scrollTo(const MapLocation& upper_left);

    void setDimensions(int height, int width);

 protected:
    int getHeight() const;
    int getWidth() const;


    void setTile(int x, int y);
    void drawTile(int x, int y, char tile);
    char getDisplayChar(BlockType type) const;
    string getStatusString(PlayerStatus status) const;

    void shutdown();

    void createFrame();
    void deleteFrame();

    int getIndex(int x, int y);

 private:
    int m_width;
    int m_height;

    char* m_frame;

    MapLocation m_upper_left;
    const World* m_world;
};

} // walls

#endif // DISPLAY_H
