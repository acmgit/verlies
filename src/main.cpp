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

#include <SFML/Graphics.hpp>

#include "include/Logfile.h"
#include "window.h"

CLog ErrorLog("verlies.log");

int main()
{
    Log("Start of Logfile.");
    Window* Main_Win;

    try
    {
        Main_Win = new Window("Main_Window", {800, 600});

    }
    catch(std::exception& ex)
    {
        Log("Failed to open Window: " << ex.what());
        return EXIT_FAILURE;

    }

    Main_Win->clear(sf::Color::Black);

    Main_Win->set_pen(10, 10);
    Main_Win->set_font("gfx/PixelOperator8.ttf");
    Main_Win->write(sf::Color::Red, "Test ..");

    Main_Win->poll();

    Log("End of Logfile.");
    return EXIT_SUCCESS;

}
