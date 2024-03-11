/*
*********************************************************
*                                                       *
*                    verlies                            *
*                                                       *
*                 (?) by A.C.M.                         *
*                                                       *
*           Deadsoft Development Corp.                  *
*                                                       *
*                    GPL 3.0                            *
*                                                       *
*********************************************************
*/

#include <iostream>
#include <stdexcept>

#include <libintl.h>
#include <clocale>
#define _(string) gettext (string)

#include <SFML/Graphics.hpp>

#include "Logfile.h"
#include "window.h"
#include "resource_manager.h"



Resource_Manager* Resources;

CLog ErrorLog("verlies.log");

int main()
{
    Log("Start of Logfile.");

    std::setlocale(LC_ALL, "");
    bindtextdomain("verlies", "locale");
    textdomain("verlies");

    Window* Main_Win;
    Resources = new Resource_Manager();
    if(!Resources)
    {
        Log("Failed to load Resource-Manager.");
        return -1;

    }

    Main_Win = Resources->get_Windowhandle();

    Resources->set_font("/usr/share/fonts/TTF/DejaVuSerif-Italic.ttf");
    Main_Win->set_pen(10, 200);
    Main_Win->write(sf::Color::Blue, _("Test .."));
    Main_Win->poll();

    if(Main_Win)
    {
        Main_Win = nullptr;

    }
    delete Resources;

    Log("End of Logfile.\n");
    return EXIT_SUCCESS;

}
