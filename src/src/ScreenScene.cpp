//
//  ScreenScene.cpp
//  myproject
//
//  Created by Karim DRIDI on 28/01/2018.
//

#include "ScreenScene.hpp"

#include "Engine.hpp"
#include "SpriteObj.hpp"

ScreenScene::ScreenScene(Engine& engine, int id)
: Scene(engine)
, id(id)
{
}

void ScreenScene::init()
{
    if (id == 0) {
        auto& sheet = engine.getSpriteSheet(SSHEET_MSG1);
        auto obj = new SpriteObj(sheet);
        obj->move(sf::Vector2f(0, 0));
        push_back(0, obj);
    } else if (id == 1) {
        auto& sheet = engine.getSpriteSheet(SSHEET_MSG2);
        auto obj = new SpriteObj(sheet);
        obj->move(sf::Vector2f(0, 0));
        push_back(0, obj);
    }
}

void ScreenScene::showNext()
{
    if (id == 0) {
        engine.showScene("msg02");
    } else if (id == 1) {
        engine.showScene("room01");
    }
}
