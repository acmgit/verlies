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

#include "resource_manager.h"
#include "window.h"
#include "console.h"


Resource_Manager* Resources = nullptr;

CLog ErrorLog("verlies.log");

int main()
{
    Log("Start of Logfile.");

    std::setlocale(LC_ALL, "");
    bindtextdomain("verlies", "locale");
    textdomain("verlies");

    Window* Main_Win = nullptr;
    Resources = new Resource_Manager();
    if(!Resources)
    {
        Log("Failed to load Resource-Manager.");
        return -1;

    }

    Main_Win = Resources->get_Windowhandle();
    if(!Main_Win)
    {
        Log("Failed to open Window");
        delete Resources;
        return -1;

    }

    Console* Game_Console = nullptr;
    Game_Console = new Console(Main_Win, Resources);
    if(!Game_Console)
    {
        Log("Failed to load the Console.")
        delete Resources;
        Main_Win = nullptr;
        return -1;

    }

    Resources->set_font("/usr/share/fonts/TTF/DejaVuSerif-Italic.ttf");
    Main_Win->clear(sf::Color::Black);
    Log("Clear Window");

    for(int i = 0; i < 10; i++)
    {
        std::string text = _("Testlauf ");
        Game_Console->write_line(text);
        Game_Console->scroll();
        Game_Console->update();
        Main_Win->update();

    }

    Game_Console->write_input("ich geb");
    Game_Console->draw_frame();

    Main_Win->poll();



    if(Game_Console)
    {
        delete Game_Console;
        Game_Console = nullptr;

    }

    if(Resources)
    {
        delete Resources;
        Resources = nullptr;

    }
    if(Main_Win)
    {
        Main_Win = nullptr;

    }
    delete Resources;

    Log("End of Logfile.\n");
    return EXIT_SUCCESS;

}
