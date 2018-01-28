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
    e.registerSceneFactory("room03", [&] () {
        return new JsonScene(e, "room03");
    });
    e.registerSceneFactory("room04", [&] () {
        return new JsonScene(e, "room04");
    });
    e.registerSceneFactory("room05", [&] () {
        return new JsonScene(e, "room05");
    });
    e.registerSceneFactory("room06", [&] () {
        return new JsonScene(e, "room06");
    });
    e.registerSceneFactory("room07", [&] () {
        return new JsonScene(e, "room07");
    });
    e.registerSceneFactory("room08", [&] () {
        return new JsonScene(e, "room08");
    });
    e.registerSceneFactory("FakeSceneA", [&] () {
        FakeSceneA* scene = new FakeSceneA(e);
        return scene;
    });
    
//    e.showScene("FakeSceneA");
    e.showScene("room01");
    
    if (e.init() == false)
        return (1);
    
    while (e.update() == true);
    
    return (0);
}

