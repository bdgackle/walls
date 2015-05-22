/*
 *  @author Barry Gackle
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

// Local Headers
#include "game_constants.hpp"

// C++ Standard Headers
#include <string>
#include <vector>

namespace walls {
class World;
class Map;
class MapLocation;
class Object;

class Display {
 public:
    Display();
    virtual ~Display();

    void draw(const World& world,
              const MapLocation& upper_left,
              int curs_x,
              int curs_y,
              bool curs_visible);

    void drawDebug(const World& world,
                   const MapLocation& upper_left,
                   int curs_x,
                   int curs_y);

    void drawDebugBlank();

    int getHeight() const;
    int getWidth() const;
    int getCenterX() const;
    int getCenterY() const;

    void setDimensions(int width, int height);

 protected:
    void drawMap(const Map& map, const MapLocation& upper_left);
    void drawStatus(PlayerStatus status, const World& world);
    void drawPlayer(const MapLocation& location, const MapLocation& upper_left);
    void drawObjects(const std::vector<Object*>& objects,
                     const MapLocation& upper_left);
    void drawCursor(int curs_x, int curs_y, bool visible);
    void updateScreen();

    void drawTile(int x, int y, char tile, int color = 8);
    void outputFrame();

    int getIndex(int x, int y) const;
    bool isOnScreen(const MapLocation& location,
                    const MapLocation& upper_left,
                    int* screen_x,
                    int* screen_y);

    static char getDisplayChar(BlockType type);
    static int getDisplayColor(BlockType type);
    static std::string getStatusString(PlayerStatus status);

    void createBuffers();
    void deleteBuffers();

 private:
    int m_width;
    int m_height;

    char* m_display_frame;
    int* m_display_colors;
    char* m_buffer_frame;
    int* m_buffer_colors;
};

} // namespace walls

#endif // DISPLAY_HPP
