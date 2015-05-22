/*
 *  @author Barry Gackle
 */

#ifndef APPEARANCE_HPP
#define APPEARANCE_HPP

namespace walls {

typedef char Glyph;
typedef int Color;

class Appearance {
 public:
    Appearance(Glyph glyph, Color color);

    Glyph glyph() const;
    Color color() const;

 private:
    const Glyph m_glyph;
    const Color m_color;
};

} // namespace walls

#endif // APPEARANCE_HPP
