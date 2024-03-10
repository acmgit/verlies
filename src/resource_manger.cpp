#ifndef RESOURCE_MANAGER_CPP
#define RESOURCE_MANAGER_CPP

#include <libintl.h>
#include <clocale>
#define _(string) gettext (string)

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "resource_manager.h"
#include "window.h"
#include "Logfile.h"

Resource_Manager::Resource_Manager()
{
    Log("Loading Resources.");

    try
    {
        m_Output = new Window(_("Mainwindow"), sf::Vector2u(800, 600));
        m_font.loadFromFile("/usr/share/fonts/TTF/DejaVuSerif-Italic.ttf");
        m_Output->set_font(m_font);
        m_Output->set_font_size(16);

    }
    catch(std::exception& ex)
    {
        Log("Error: " << ex.what());
        m_Output = 0;
        return;
    }

    m_Output->write(sf::Color::White, "Loading ...");

    Log("Resource-Manager opened.");
}

Resource_Manager::~Resource_Manager()
{
    if(m_Output)
    {
        m_Output->close();
        Log("Window closed.");
        delete m_Output;
        m_Output = nullptr;

    }

    Log("Resource-Manager closed.")

}

Window* Resource_Manager::get_Windowhandle()
{
    return m_Output;

}

void Resource_Manager::set_font(const std::string new_font)
{
    if(!m_font.loadFromFile(new_font))
    {
        Log("Couldn't load font: " << new_font.c_str());
        return;
    }

    m_Output->set_font(m_font);
    Log("Font " << new_font.c_str() << " loaded.");

}

#endif // RESOURCE_MANAGER_CPP
