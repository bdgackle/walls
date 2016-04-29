/**
 *  @file display.hpp
 *  
 *  @author Barry Gackle
 *  @copyright 9 March 2016
 *  @copyright All rights reserved
 *
 *  @brief Contains class Display
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

// Local Headers
#include "unit_types.hpp"

namespace walls {
class Glyph;

class Display {
    /** Get height of display in character cells */
    virtual DisplayCoordinate height() const = 0;

    /** Get width of display in character cells */
    virtual DisplayCoordinate width() const = 0;

    /** Set a glyph in the next frame */
    virtual void set_cell(DisplayCoordinate x,
                          DisplayCoordinate y,
                          const Glyph& glyph) = 0; 

    /** Show next frame */
    virtual void refresh() = 0;
}; // class Display

} // namespace walls

#endif // DISPLAY_HPP
