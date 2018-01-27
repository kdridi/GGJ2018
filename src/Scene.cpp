#include "Scene.hpp"
#include "Engine.hpp"
#include "GameObj.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

bool Scene::init()
{
    objList.push_back(new GameObj(Engine::current->getSpriteSheet(0), 0));
    return (true);
}

bool Scene::draw()
{
    for (auto obj : this->objList)
        obj->draw();
    
    return (true);
}

