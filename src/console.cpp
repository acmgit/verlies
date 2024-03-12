#ifndef CONSOLE_CPP
#define CONSOLE_CPP

#include "SFML/Graphics.hpp"
#include "console.h"
#include "window.h"

Console::Console(Window* window_handle, sf::Sprite& console_frame)
{
    m_window_handle = window_handle;
    m_frame = console_frame;
    m_pos_x = 0;
    m_pos_y = 400;
}

Console::~Console()
{
    m_window_handle = nullptr;

}
void Console::scroll()
{


}

void Console::writeline()
{


}

void Console::draw_frame()
{
    m_frame.setPosition(m_pos_x, m_pos_y);
    m_window_handle->draw_image(m_frame);

}

#endif
