#include "Engine.hpp"
#include "config.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;
    
    Engine e;
    
    if (e.init() == false)
        return (1);
    
    while (e.update() == true);
    
    return (0);
}

