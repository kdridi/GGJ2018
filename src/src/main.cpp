#include "Engine.hpp"
#include "FakeSceneA.hpp"
#include "JsonScene.hpp"

int main()
{
    Engine e;
    
    e.registerSceneFactory("room1", [&] () {
        return new JsonScene(e, "room1");
    });
    e.registerSceneFactory("FakeSceneA", [&] () {
        FakeSceneA* scene = new FakeSceneA(e);
        return scene;
    });
    
   // e.showScene("FakeSceneA");
    e.showScene("room1");
    
    if (e.init() == false)
        return (1);
    
    while (e.update() == true);
    
    return (0);
}

