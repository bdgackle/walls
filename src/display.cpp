/**
 *  @author Barry Gackle
 */

// Local Headers
#include "display.hpp"
#include "game_constants.hpp"
#include "maplocation.hpp"
#include "map.hpp"
#include "player.hpp"
#include "object.hpp"
#include "world.hpp"
#include "creature.hpp"
#include "ferret.hpp"

// External Headers
#include <curses.h>

// C++ Standard Headers
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace walls {

Display::Display() :
    m_width(0),
    m_height(0),
    m_display_frame(NULL),
    m_display_colors(NULL),
    m_buffer_frame(NULL),
    m_buffer_colors(NULL) {}

Display::~Display()
{
    deleteBuffers();
}

// PERF: Everything BEFORE updateScreen() is taking around 10ms... or about
//       half the current frametime just to push data around
void Display::draw(const World& world,
                   const MapLocation& upper_left,
                   int curs_x,
                   int curs_y,
                   bool curs_visible)
{
    const Map& map = world.getMap();
    PlayerStatus player_status = world.getPlayer().getStatus();
    MapLocation player_location = world.getPlayer().getLocation();
    const vector<Object*>& creatures = world.getCreatures().getObjects();
    const vector<Object*>& prey = world.getPrey().getObjects();
    const vector<Object*>& plants = world.getPlants().getObjects();
    drawMap(map, upper_left);
    drawObjects(plants, upper_left);
    drawObjects(creatures, upper_left);
    drawObjects(prey, upper_left);
    drawPlayer(player_location, upper_left);
    updateScreen();

    drawDebugBlank();
    drawDebug(world, upper_left, curs_x, curs_y);

    drawStatus(player_status, world);
    drawCursor(curs_x, curs_y, curs_visible);
}

void Display::drawDebug(const World& world,
                        const MapLocation& upper_left,
                        int curs_x,
                        int curs_y)
{
    char line_one[40];
    char line_two[40];
    char line_three[40];
    char line_four[40];
    char name[40];

    int food = 0;

    MapLocation curs_loc = upper_left.getRelative(curs_x, curs_y, 0);
    const Map& map = world.getMap();

    sprintf(name, "Nothing");
    if (map.hasCreature(curs_loc)) {
        const Creature& cre = (const Creature&)(map.creature(curs_loc));
        MapLocation cre_loc = cre.getTarget();
        sprintf(name, "FEWWET!!");
        food = cre.getFood();

        int cre_x;
        int cre_y;
        if (isOnScreen(cre_loc, upper_left, &cre_x, &cre_y)) {
            drawTile(cre_x, cre_y, '!', COLOR_PAIR(7));
        }
        updateScreen();
    }

    if (map.hasPrey(curs_loc)) {
        sprintf(name,"BUNNY!!!!!");
    }

    sprintf(line_one, "Critter: %s", name);
    mvaddstr(0, 85, line_one);

    sprintf(line_two, "FOOD: %d", food);
    mvaddstr(1, 85, line_two);

    sprintf(line_three, "AGE: NOT IMPLEMENTED");
    mvaddstr(2, 85, line_three);

    sprintf(line_four, "Update: %d", world.getUpdateTime());
    mvaddstr(3, 85, line_four);
}

void Display::drawDebugBlank()
{
    mvaddstr(0, 81, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(1, 81, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(2, 81, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(3, 81, PLAYER_STATUS_NONE_STRING.c_str());
}

int Display::getHeight() const
{
    return m_height;
}

int Display::getWidth() const
{
    return m_width;
}

int Display::getCenterX() const
{
    return m_width / 2;
}

int Display::getCenterY() const
{
    return m_height / 2;
}

void Display::setDimensions(int width, int height)
{
    m_width = width;
    m_height = height;
    createBuffers();
}

void Display::drawMap(const Map& map, const MapLocation& upper_left)
{
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            MapLocation next = upper_left.getRelative(x, y, 0);
            BlockType type = map.blockType(next);
            drawTile(x, y, getDisplayChar(type), getDisplayColor(type));
        }
    }
}

void Display::drawStatus(PlayerStatus status, const World& world)
{
    char line_two[40];
    char line_three[40];
    char line_four[40];

    string stat_string = getStatusString(status);
    mvaddstr(0, 0, stat_string.c_str());
/*
    sprintf(line_two, "Time: %d", world.getTime());
    mvaddstr(1, 0, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(1, 0, line_two);
*/
    sprintf(line_two, "Ferrets: %d", world.getCreatureCount());
    mvaddstr(1, 0, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(1, 0, line_two);

    sprintf(line_three, "Bunnies: %d", world.getPreyCount());
    mvaddstr(2, 0, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(2, 0, line_three);

    sprintf(line_four, "Plants: %d", world.getPlantCount());
    mvaddstr(3, 0, PLAYER_STATUS_NONE_STRING.c_str());
    mvaddstr(3, 0, line_four);
}

void Display::drawPlayer(const MapLocation& location,
                         const MapLocation& upper_left)
{
    int x;
    int y;
    if (isOnScreen(location, upper_left, &x, &y))
        drawTile(x, y, PLAYER_CHAR);
}

void Display::drawObjects(const vector<Object*>& objects,
                          const MapLocation& upper_left)
{
    vector<Object*>::const_iterator iter;
    for (iter = objects.begin(); iter != objects.end(); ++iter) {
        int x;
        int y;
        Appearance appearance = (*iter)->appearance();

        MapLocation loc = (*iter)->getLocation();
        if (isOnScreen(loc, upper_left, &x, &y)) {
            drawTile(x, y, appearance.glyph(), appearance.color());
        }
    }
}

void Display::drawCursor(int curs_x, int curs_y, bool visible)
{
    if (visible) {
        curs_set(1); // Cursor visible
        move(curs_y, curs_x); // Move ncurses cursor to track logical cursor
    } else {
        curs_set(0); // Cursor not visible
    }
}

void Display::drawTile(int x, int y, char tile, int color)
{
    int index = getIndex(x,y);
    m_buffer_frame[index] = tile;
    m_buffer_colors[index] = color;
}

void Display::updateScreen()
{
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            int index = getIndex(x,y);

            char new_tile = m_buffer_frame[index];
            int new_color = m_buffer_colors[index];
            char old_tile = m_display_frame[index];
            int old_color = m_display_colors[index];

            if ((new_tile != old_tile) || (new_color != old_color)) {
                attron(new_color);
                mvaddch(y, x, new_tile);
                attroff(new_color);
                m_display_frame[index] = new_tile;
                m_display_colors[index] = new_color;
            }
        }
    }
}

int Display::getIndex(int x, int y) const
{
    return x + y * m_width;
}

bool Display::isOnScreen(const MapLocation& loc,
                         const MapLocation& ul,
                         int* screen_x,
                         int* screen_y)
{
    *screen_x = ul.getDistanceX(loc);
    *screen_y = ul.getDistanceY(loc);
    int screen_z = ul.getDistanceZ(loc);

    if ((*screen_x >= 0) && (*screen_x < m_width) &&
        (*screen_y >= 0) && (*screen_y < m_height) &&
        (screen_z == 0))
        return true;
    else
        return false;
}

char Display::getDisplayChar(BlockType type)
{
    switch(type) {
    case NOT_ON_MAP:
        return NOT_ON_MAP_CHAR;
        break;

    case GROUND:
        return GROUND_CHAR;
        break;

    case ROCK:
        return ROCK_CHAR;
        break;

    case SAPLING:
        return SAPLING_CHAR;
        break;

    case WALL:
        return WALL_CHAR;
        break;

    case DOOR:
        return DOOR_CHAR;
        break;

    case FLOOR:
        return FLOOR_CHAR;
        break;

    default:
        return INVALID_CHAR;
    }
}

int Display::getDisplayColor(BlockType type)
{
    switch(type) {
    case NOT_ON_MAP:
        return NOT_ON_MAP_COLOR;
        break;

    case GROUND:
        return GROUND_COLOR;
        break;

    case ROCK:
        return ROCK_COLOR;
        break;

    case SAPLING:
        return SAPLING_COLOR;
        break;

    case WALL:
        return WALL_COLOR;
        break;

    case DOOR:
        return DOOR_COLOR;
        break;

    case FLOOR:
        return FLOOR_COLOR;
        break;

    default:
        return INVALID_COLOR;
    }
}

string Display::getStatusString(PlayerStatus status)
{
    switch(status) {
    case HAPPY:
        return PLAYER_STATUS_HAPPY_STRING;
        break;

    case VENGEFUL:
        return PLAYER_STATUS_VENGEFUL_STRING;
        break;

    case SMELLS_FERRET:
        return PLAYER_STATUS_SMELLS_FERRET_STRING;
        break;

    case INVADE_FERRET:
        return PLAYER_STATUS_INVADE_FERRET_STRING;
        break;

    default:
        return PLAYER_STATUS_NONE_STRING;
    }
}

void Display::createBuffers()
{
    deleteBuffers();
    m_display_frame = new char[m_width * m_height];
    m_display_colors = new int[m_width * m_height];
    m_buffer_frame = new char[m_width * m_height];
    m_buffer_colors = new int[m_width * m_height];
}

void Display::deleteBuffers()
{
    if (m_display_frame != NULL)
        delete [] m_display_frame;

    if (m_display_colors != NULL)
        delete [] m_display_colors;

    if (m_buffer_frame != NULL)
        delete [] m_buffer_frame;

    if (m_buffer_colors != NULL)
        delete [] m_buffer_colors;
}

} // namespace walls
