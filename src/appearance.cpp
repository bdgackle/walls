/**
 *  @author Barry Gackle
 */

// Module Header
#include "appearance.hpp"

namespace walls {

Appearance::Appearance(Glyph glyph, Color color) :
    m_glyph(glyph),
    m_color(color) {}

Glyph Appearance::glyph() const
{
    return m_glyph;
}

Color Appearance::color() const
{
    return m_color;
}

} // namespace walls
