#ifndef window_cpp
#define window_cpp

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "include/Logfile.h"
#include "include/window.h"

Window::Window(const std::string title, const sf::Vector2u dimension)
{
    m_height = dimension.y;
    m_width = dimension.x;
    m_pen_x = 0;
    m_pen_y = 0;
    m_title = title;
    m_font_size = 16;
    Log("Open Window: " << m_width << "x" << m_height << " Title: " << m_title.c_str());

    m_handle.create({m_width, m_height, 32}, m_title, sf::Style::Close);
    m_is_open = true;
}

Window::~Window()
{
    if(m_is_open)
    {
        close();

    }

}

bool Window::is_open()
{
    return m_is_open;

}

void Window::clear(sf::Color color)
{
    m_handle.clear(color);

}

void Window::poll()
{
    while(m_is_open)
    {
        sf::Event event;
        while(m_handle.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                close();
                m_is_open = false;

            }
        }
        m_handle.display();
        sf::Time wait = sf::milliseconds(50);
        sf::sleep(wait);
    }

}

void Window::close()
{
    m_handle.close();

}

void Window::set_font(sf::Font font)
{
    m_font = font;

}

void Window::set_pen(int x, int y)
{
    m_pen_x = x;
    m_pen_y = y;

}

void Window::set_font_size(int character_size)
{
    m_font_size = character_size;

}

int Window::get_font_size()
{
    return m_font_size;

}

void Window::set_color(sf::Color color)
{
    m_color = color;

}


void Window::write(const std::string text)
{
    sf::Text line;

    line.setFont(m_font);
    line.setString(text);
    line.setFillColor(m_color);
    line.setCharacterSize(m_font_size);
    line.move(m_pen_x, m_pen_y);

    m_handle.draw(line);

}

void Window::write(const sf::Text& text)
{
    std::string logtext = text.getString();
    m_handle.draw(text);

}


void Window::draw_image(const sf::Sprite gfx_object)
{
    m_handle.draw(gfx_object);

}

void Window::update()
{
    m_handle.display();
}
#endif // window_cpp
