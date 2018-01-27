#include "Engine.hpp"

#include <iostream>
#include <sstream>

#include "Utils.hpp"

int main()
{
    Engine e;
    
    if (e.init() == false)
        return (1);
    
    while (e.update() == true);
    
    return (0);
}

