#include "Engine.hpp"

#include <iostream>
#include <sstream>

#include "Utils.hpp"
#include "FakeSceneA.hpp"

int main()
{
    Engine e;
    
    e.registerSceneFactory("FakeSceneA", [] () {
        FakeSceneA* scene = new FakeSceneA();
        return scene;
    });
    
    e.showScene("FakeSceneA");
    
    if (e.init() == false)
        return (1);
    
    while (e.update() == true);
    
    return (0);
}

