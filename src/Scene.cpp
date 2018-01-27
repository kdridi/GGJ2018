#include <iostream>

#include "Scene.hpp"
#include "Engine.hpp"
#include "SpriteObj.hpp"
#include "MainObj.hpp"
#include "ColliderMap.hpp"

Scene::Scene()
{
}
 
Scene::~Scene()
{
}

static int ids0[] = {
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};

static int ids1[] = {
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0,12, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0,12, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
};

bool Scene::init()
{
    auto& sheet = Engine::current->getSpriteSheet(0);
    auto& brune = Engine::current->getSpriteSheet(1);
    
    new ColliderMap(ids1, sf::Vector2i(16, 12), sf::Vector2i(64, 64), {12});
    for (int x = 0; x < 16; ++x)
    {
        for (int y = 0; y < 12; ++y)
        {
            auto id = ids0[y * 16 + x];
            if (id > 0)
            {
                auto obj = new SpriteObj(sheet, id - 1);
                obj->move(sf::Vector2f(x * 64, y * 64));
                
                push_back(0, obj);
            }
        }
    }
    
    for (int x = 0; x < 16; ++x)
    {
        for (int y = 0; y < 12; ++y)
        {
            auto id = ids1[y * 16 + x];
            if (id > 0)
            {
                auto obj = new SpriteObj(sheet, id - 1);
                obj->move(sf::Vector2f(x * 64, y * 64));
                
                push_back(1, obj);
            }
        }
    }

    GameObj *obj = new MainObj(1, brune, 0);
    obj->move(sf::Vector2f(10 * 64, 9 * 64));
    push_back(2, obj);
    obj = new MainObj(2, brune, 1);
    obj->move(sf::Vector2f(4 * 64, 4 * 64));
    push_back(2, obj);
    return (true);
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

bool Scene::draw()
{
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

//
//#include <boost/property_tree/json_parser.hpp>
//
//namespace boost {
//    namespace property_tree {
//        namespace json_parser {
//            template<typename Ptree>
//            void read_json(std::basic_istream< typename Ptree::key_type::value_type > &,
//                           Ptree &);
//            template<typename Ptree>
//            void read_json(const std::string &, Ptree &,
//                           const std::locale & = std::locale());
//            template<typename Ptree>
//            void write_json(std::basic_ostream< typename Ptree::key_type::value_type > &,
//                            const Ptree &, bool = true);
//            template<typename Ptree>
//            void write_json(const std::string &, const Ptree &,
//                            const std::locale & = std::locale(), bool = true);
//        }
//    }
//}


