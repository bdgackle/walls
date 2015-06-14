/**
 *  @author Barry Gackle
 *  @author 4 July 2014
 */

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

// Local Headers
#include "game_constants.hpp"

namespace walls {

class InputHandler {
 public:
    InputHandler();
    ~InputHandler();

    void init(int width, int height, int curs_x, int curs_y);

    Command getInput();

    int getCursorX() const;
    int getCursorY() const;
    bool getCursorVisible() const;

 protected:
    Command processInputNormal(int input);
    Command processInputEdit(int input);
    Command processInputCommon(int input);

    void moveCursor(int delta_x, int delta_y);

 private:
    enum Mode {
        NORMAL,
        EDIT
    };

    Mode m_mode;
    int m_cursor_x;
    int m_cursor_y;

    int m_screen_width;
    int m_screen_height;
};

} // namespace walls

#endif // INPUT_HANDLER_HPP
