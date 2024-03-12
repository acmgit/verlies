#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "SFML/Graphics.hpp"
#include "window.h"

class Resource_Manager
{
public:
    Resource_Manager();
    ~Resource_Manager();

    Window* get_Windowhandle();
    void set_font(const std::string new_font);
    sf::Sprite& get_console_frame();

private:

    Window* m_Output;
    sf::Font m_font;

    sf::Texture m_console_frame_texture;
    sf::Sprite m_console_frame;
};


#endif // RESSURCE_MANAGER_H
