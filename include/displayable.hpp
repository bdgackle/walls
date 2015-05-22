/*
 *  @author Barry Gackle
 */

#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP

// Local Headers
#include "appearance.hpp"

namespace walls {

class Displayable {
 public:
    virtual ~Displayable() {}

    virtual Appearance appearance() const = 0;
};

} // namespace walls

#endif // DISPLAYABLE_HPP
