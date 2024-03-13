#ifndef CONSOLE_CPP
#define CONSOLE_CPP

#include "Logfile.h"
#include "SFML/Graphics.hpp"
#include "console.h"
#include "resource_manager.h"
#include "window.h"

Console::Console(Window* window_handle, Resource_Manager* resource_manager)
{
    m_window_handle = window_handle;
    m_resource_manager = resource_manager;

    m_font = resource_manager->get_console_font();
    m_frame = m_resource_manager->get_console_frame();
    m_pos_x = 0;
    m_pos_y = 400;
    m_font_size = m_window_handle->get_font_size();
    Log("Fontsize: " << m_font_size);

    m_prompt_color = sf::Color::White;
    m_prompt = ">";

    m_line_pos_x = m_pos_x + m_font_size;
    m_line_pos_y = m_pos_y + m_font_size;
    m_line_color = sf::Color::Green;

    m_lines = 10;

}

Console::~Console()
{
    m_window_handle = nullptr;

}
void Console::scroll()
{


}

void Console::write_line(const int line_number, const std::string line)
{
    if(line_number > m_lines || line_number < 0)
    {
        Log("Console: Illegal Linenumber - " << line_number);
        return;
    }

    sf::Text console_line;

    console_line.setFont(m_font);
    console_line.setString(m_prompt);
    console_line.setFillColor(m_prompt_color);
    console_line.setCharacterSize(m_font_size);
    console_line.setPosition(m_line_pos_x, m_line_pos_y + (line_number * m_font_size));
    m_window_handle->write(console_line);

    console_line.setString(line);
    console_line.setFillColor(m_line_color);
    console_line.setPosition(m_line_pos_x + m_font_size, m_line_pos_y + (line_number * m_font_size));
    m_window_handle->write(console_line);

}

void Console::set_line_color(const sf::Color color)
{
    m_line_color = color;

}

void Console::draw_frame()
{
    m_frame.setPosition(m_pos_x, m_pos_y);
    m_window_handle->draw_image(m_frame);

}

#endif
