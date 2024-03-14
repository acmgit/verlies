#ifndef CONSOLE_CPP
#define CONSOLE_CPP

#include <deque>

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

    m_lines = 9;

}

Console::~Console()
{
    m_window_handle = nullptr;

}

void Console::scroll()
{
    if(m_console.size() >= m_lines)
    {
        m_console.pop_front();

    }
}

void Console::write_line(const std::string line)
{
    sf::Text to_insert;
    to_insert.setString(line);
    to_insert.setFillColor(m_line_color);
    to_insert.setFont(m_font);
    to_insert.setFillColor(m_line_color);
    to_insert.setCharacterSize(m_font_size);
    m_console.push_back(to_insert);

}

void Console::write_input(const std::string line)
{
    sf::Text to_insert;
    to_insert.setString(line);
    to_insert.setFillColor(m_line_color);
    to_insert.setFont(m_font);
    to_insert.setFillColor(m_line_color);
    to_insert.setCharacterSize(m_font_size);
    to_insert.setPosition(m_line_pos_x + m_font_size, m_line_pos_y + m_lines * m_font_size);
    m_input_line = to_insert;

    write_prompt(m_lines);
    m_window_handle->write(to_insert);
}

void Console::update()
{
    int current_line = m_lines - 1;

    for( sf::Text line : m_console)
    {
        write_prompt(current_line);

        line.setPosition(m_line_pos_x + m_font_size, m_line_pos_y + current_line * m_font_size);
        m_window_handle->write(line);
        current_line--;
    }

    write_prompt(m_lines);
    m_window_handle->write(m_input_line);

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

void Console::write_prompt(int line)
{
    sf::Text prompt;

    prompt.setFont(m_font);
    prompt.setString(m_prompt);
    prompt.setFillColor(m_prompt_color);
    prompt.setCharacterSize(m_font_size);
    prompt.setPosition(m_line_pos_x, m_line_pos_y + (line * m_font_size));
    m_window_handle->write(prompt);

}


#endif
