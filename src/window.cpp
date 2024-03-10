#ifndef window_cpp
#define window_cpp

#include <string>
#include <SFML/Graphics.hpp>

#include "Logfile.h"
#include "window.h"

Window::Window(const std::string title, const sf::Vector2u dimension)
{
    m_height = dimension.y;
    m_width = dimension.x;
    m_title = title;
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

void Window::write(const sf::Color Color, const std::string text)
{
    sf::Text line;

    line.setFont(m_font);
    line.setString(text);
    line.setFillColor(Color);
    line.move(m_pen_x, m_pen_y);

    m_handle.draw(line);

}
#endif // window_cpp
