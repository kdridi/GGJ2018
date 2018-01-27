#include <iostream>

#include "Scene.hpp"
#include "Engine.hpp"
#include "GameObj.hpp"
#include "MainObj.hpp"

Scene::Scene()
: layerList()
, players()
{
}
 
Scene::~Scene()
{
}

void Scene::init(Engine& engine)
{
    throw "please override this method!";
}

bool Scene::update()
{
  for (auto &layer : this->layerList)
    {
      auto it = layer.begin();
      while (it != layer.end())
	{
	  if ((*it)->update() == false)
	    {
	      it = layer.erase(it);
	    }
	  else
	    ++it;
	}
    }
  return (true);
}

void Scene::event(sf::Event &event)
{
    for (auto layer : this->layerList)
    {
        for (auto obj : layer)
            obj->event(event);
    }
  
}

bool sortY(GameObj *A, GameObj *B)
{
  if (A->getY() < B->getY())
    return (true);
  return (false);
} 

bool Scene::draw()
{
    this->layerList[2].sort(sortY);
    for (auto layer : this->layerList)
    {
        for (auto obj : layer)
            obj->draw();
    }
    
    return (true);
}

void Scene::push_back(int layerId, GameObj *obj)
{
    this->layerList[layerId].push_back(obj);
}

void Scene::updateFrom(Scene& previous)
{
    for (std::size_t index = 0; index < players.size(); ++index)
    {
        setPlayer(index, previous.players[index]);
    }
}

void Scene::setPlayer(std::size_t id, MainObj* obj)
{
    push_back(2, obj);
    players[id] = obj;
}


