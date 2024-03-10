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

private:

    Window* m_Output;
    sf::Font m_font;

};


#endif // RESSURCE_MANAGER_H
