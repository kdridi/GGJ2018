#include <iostream>

#include "Scene.hpp"
#include "Engine.hpp"
#include "GameObj.hpp"
#include "MainObj.hpp"
#include "ColliderMap.hpp"

Scene	*Scene::current = NULL;

Scene::Scene(Engine& engine)
: engine(engine)
, layerList()
, players()
{
  Scene::current = this;
}
 
Scene::~Scene()
{
  for (auto &layer : this->layerList)
    {
      auto it = layer.begin();
      while (it != layer.end())
	{
	  auto obj = *it;

	  if (obj != MainObj::PA && obj != MainObj::PB)
	    it = layer.erase(it);
	  else
	    ++it;
	  delete obj;
	}
    }
}

void Scene::init()
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
	      auto obj = *it;
	      it = layer.erase(it);
	      delete obj;
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

void Scene::pushWallObj(std::size_t x, std::size_t y)
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto obj = new SpriteObj(sheet, SPRITE_WALL - 1);
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(1, obj);
    ColliderMap::current->addCollider(x, y, SPRITE_WALL);
}

void Scene::pushStaticObj(std::size_t x, std::size_t y)
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto obj = new SpriteObj(sheet, SPRITE_STATIC - 1);
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(1, obj);
    ColliderMap::current->addCollider(x, y, SPRITE_STATIC);
}

void Scene::pushDoorObj(std::size_t x, std::size_t y)
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto obj = new SpriteObj(sheet, SPRITE_DOOR0 - 1);
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(1, obj);
}

void Scene::pushDoorSmallObj(std::size_t x, std::size_t y)
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto obj = new SpriteObj(sheet, SPRITE_DOOR_SMALL - 1);
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(1, obj);
}

void Scene::pushExitObj(std::string name, std::size_t x, std::size_t y, std::size_t w, std::size_t h)
{
    // TODO Scene::pushExitObj implementation is missing
    // Créer une zone "transparente" à la position (x,y) de taille WxH
    // Lorsqu'un player touche cette zone, on reload la scene dont le nom est donné par la variable "name"
    
    std::cout << "ExitObj[" << name << "] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "w = " << w << " ";
    std::cout << "h = " << h << " ";
}


