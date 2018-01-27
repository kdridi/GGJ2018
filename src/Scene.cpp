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
    return (true);
}

bool Scene::draw()
{
    for (auto obj : this->objList)
        obj->draw();
    
    // Engine::current->getWindow().draw(obj);
    
    return (true);
}

