#include "Engine.hpp"

#include <libgen.h>
#include <iostream>
#include <sstream>

int main()
{
    std::stringstream ss;
    ss << dirname(const_cast<char*>(__FILE__));
    ss << "/../assets";
    
    std::cout << "[" << ss.str() << "]" << std::endl;
    
    Engine e{ss.str()};
    
    if (e.init() == false)
        return (1);
    while (e.update() == true);
    return (0);
}

