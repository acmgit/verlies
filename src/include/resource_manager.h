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

private:

    Window* m_Output;


};


#endif // RESSURCE_MANAGER_H
