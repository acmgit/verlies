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

    std::setlocale(LC_ALL, "");
    textdomain("verlies");
    bindtextdomain("verlies", "locale");

    Log("Loading Resources.");

    try
    {
        m_Output = new Window(_("Mainwindow"), sf::Vector2u(800, 600));

    }
    catch(std::exception& ex)
    {
        Log("Error: " << ex.what());
        m_Output = 0;
        return;
    }

    m_Output->write(sf::Color::White, "Loading ...");

    Log("Ressource-Manager opened.");
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

    Log("Ressource-Manager closed.")

}

Window* Resource_Manager::get_Windowhandle()
{
    return m_Output;

}
#endif // RESOURCE_MANAGER_CPP
