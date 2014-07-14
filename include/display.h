/*
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

#ifndef DISPLAY_H
#define DISPLAY_H

// C++ Standard Headers
#include <string>
#include <list>

// Internal Headers
#include "game_constants.h"

using std::string;
using std::list;

namespace walls{

class World;
class Map;
class MapLocation;
class Creature;

class Display
{
 public:
    Display();
    virtual ~Display();

    void draw(const World& world,
              const MapLocation& upper_left,
              int curs_x,
              int curs_y,
              bool curs_visible);

    int getHeight() const;
    int getWidth() const;
    int getCenterX() const;
    int getCenterY() const;

    void setDimensions(int width, int height);

 protected:
    void drawMap(const Map& map, const MapLocation& upper_left);
    void drawStatus(PlayerStatus status, const World& world);
    void drawPlayer(const MapLocation& location, const MapLocation& upper_left);
    void drawCreatures(const list<Creature*>& creatures,
                       const MapLocation& upper_left);
    void drawCursor(int curs_x, int curs_y, bool visible);

    void drawTile(int x, int y, char tile, int color = 8);

    int getIndex(int x, int y) const;

    static char getDisplayChar(BlockType type);
    static int getDisplayColor(BlockType type);
    static string getStatusString(PlayerStatus status);

    void createFrame();
    void deleteFrame();

 private:
    int m_width;
    int m_height;

    char* m_frame;
};

} // walls

#endif // DISPLAY_H
