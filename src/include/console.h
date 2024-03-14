#ifndef CONSOLE_H
#define CONSOLE_H

/**
 * @todo write docs
 */

#include <queue>
#include <string>

#include "SFML/Graphics.hpp"
#include "resource_manager.h"
#include "window.h"

class Console
{
public:
    Console(Window* window_handle, Resource_Manager* resource_manager);
    ~Console();

    void scroll();
    void write_line(const std::string line);
    void write_input(const std::string line);
    void set_line_color(const sf::Color color);
    void draw_frame();

    void update();

private:
    void write_prompt(int line);

    int m_lines;
    int m_pos_x;
    int m_pos_y;
    int m_font_size;

    std::string m_prompt;
    sf::Text m_input_line;

    sf::Color m_prompt_color;

    int m_line_pos_x;
    int m_line_pos_y;
    sf::Color m_line_color;

    Window* m_window_handle;
    Resource_Manager* m_resource_manager;

    sf::Sprite m_frame;
    sf::Font m_font;

    std::deque<sf::Text> m_console;

};

#endif // CONSOLE_H
