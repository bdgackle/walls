/*
 *  @author Barry Gackle
 */

// Module Header
#include "creature_appearances.hpp"

// Local Headers
#include "appearance.hpp"

// External Headers
#include <ncurses.h>

namespace walls {

const Appearance bunny_appearance('b', COLOR_PAIR(5));
const Appearance ferret_appearance('f', COLOR_PAIR(2));
const Appearance grass_appearance(',', COLOR_PAIR(3));
const Appearance grass_seed_appearance(';', COLOR_PAIR(4));

} // namespace walls
