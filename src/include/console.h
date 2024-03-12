#ifndef CONSOLE_H
#define CONSOLE_H

/**
 * @todo write docs
 */

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"
#include "window.h"

class Console
{
public:
    Console(Window* window_handle, sf::Sprite& console_frame);
    ~Console();

    void scroll();
    void writeline();
    void draw_frame();

private:

    int m_lines;
    int m_pos_x;
    int m_pos_y;

    Window* m_window_handle;
    sf::Sprite m_frame;
};

#endif // CONSOLE_H
