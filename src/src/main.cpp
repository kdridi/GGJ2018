#include "Engine.hpp"
#include "FakeSceneA.hpp"
#include "JsonScene.hpp"

int main()
{
    Engine e;
    
    e.registerSceneFactory("room01", [&] () {
        return new JsonScene(e, "room01");
    });
    e.registerSceneFactory("room02", [&] () {
        return new JsonScene(e, "room02");
    });
    e.registerSceneFactory("FakeSceneA", [&] () {
        FakeSceneA* scene = new FakeSceneA(e);
        return scene;
    });
    
//    e.showScene("FakeSceneA");
    e.showScene("room02");
    
    if (e.init() == false)
        return (1);
    
    while (e.update() == true);
    
    return (0);
}

