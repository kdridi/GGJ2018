#include <iostream>

#include "Scene.hpp"
#include "Engine.hpp"
#include "GameObj.hpp"
#include "MainObj.hpp"
#include "ColliderMap.hpp"
#include "ExitObj.hpp"
#include "CrackObj.hpp"
#include "MonsterObj.hpp"
#include "ShareObj.hpp"
#include "MoveObj.hpp"
#include "SwitchObj.hpp"

Scene    *Scene::current = NULL;

Scene::Scene(Engine& engine)
: engine(engine)
, layerList()
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
            {
                it = layer.erase(it);
                delete obj;
            }
            else
                ++it;
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
    auto *obj = new CrackObj(sheet, SPRITE_DOOR_SMALL - 1, sf::IntRect(0, 0, 64, 15));
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(1, obj);
}

void Scene::pushExitObj(std::string name, std::size_t x, std::size_t y, std::size_t w, std::size_t h, std::size_t enemyLock, std::size_t pressureLock)
{
    // TODO Scene::pushExitObj implementation is missing
    // Créer une zone "transparente" à la position (x,y) de taille WxH
    // Lorsqu'un player touche cette zone, on reload la scene dont le nom est donné par la variable "name"
    
    std::cout << "Before new ExitObj" << std::endl;
    auto obj = new ExitObj(engine, name, sf::Vector2f(w, h), enemyLock, pressureLock);
    std::cout << "After new ExitObj" << std::endl;
    obj->move(sf::Vector2f(x, y));
    push_back(1, obj);
    exitList.push_back(obj);
    
    std::cout << "ExitObj[" << name << "] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "w = " << w << " ";
    std::cout << "h = " << h << " ";
    std::cout << "enemyLock = " << enemyLock << " ";
    std::cout << "pressureLock = " << pressureLock << " ";
    std::cout << std::endl;
}

void Scene::pushEnemyCloseObj(std::size_t x, std::size_t y, std::size_t w, std::size_t h, double damage, double hp)
{
    std::cout << "EnemyCloseObj[] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "w = " << w << " ";
    std::cout << "h = " << h << " ";
    std::cout << "damage = " << damage << " ";
    std::cout << "hp = " << hp << " ";
    std::cout << std::endl;
    
    auto *obj = new MonsterObj(engine.getSpriteSheet(SSHEET_MONSTER), 0);
    obj->moveAt(sf::Vector2f(x, y));
    push_back(2, obj);
}

void Scene::pushEnemyAwayObj(std::size_t x, std::size_t y, std::size_t w, std::size_t h, double damage, double hp)
{
    std::cout << "EnemyAwayObj[] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "w = " << w << " ";
    std::cout << "h = " << h << " ";
    std::cout << "damage = " << damage << " ";
    std::cout << "hp = " << hp << " ";
    std::cout << std::endl;
    
    auto *obj = new MonsterObj(engine.getSpriteSheet(SSHEET_MONSTER), 0);
    obj->moveAt(sf::Vector2f(x, y));
    push_back(2, obj);
}

void Scene::pushEnemyBossObj(std::size_t x, std::size_t y, std::size_t w, std::size_t h, double damage, double hp)
{
    std::cout << "EnemyBossObj[] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "w = " << w << " ";
    std::cout << "h = " << h << " ";
    std::cout << "damage = " << damage << " ";
    std::cout << "hp = " << hp << " ";
    std::cout << std::endl;
    
    auto *obj = new MonsterObj(engine.getSpriteSheet(SSHEET_MONSTER), 0);
    obj->moveAt(sf::Vector2f(x, y));
    push_back(2, obj);
}

void Scene::pushMobileObj(std::size_t x, std::size_t y)
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto *obj = new MoveObj(sheet, SPRITE_MOBILE - 1);
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(1, obj);
}

void Scene::pushLinkedObj(std::size_t x, std::size_t y)
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto *obj = new ShareObj(sheet, SPRITE_LINKED - 1);
    obj->move(sf::Vector2f(x * 64, y * 64));
    push_back(2, obj);
}

void Scene::pushItemObj(std::size_t x, std::size_t y, std::size_t w, std::size_t h, Spells::Type type)
{
    std::cout << "ItemObj[" << type << "] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "w = " << w << " ";
    std::cout << "h = " << h << " ";
    std::cout << std::endl;
}

void Scene::pushToogleObj(std::string name, std::size_t x, std::size_t y, SpriteType type)
{
    std::cout << "ToogleObj[" << name << "] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "type = " << type << " ";
    std::cout << std::endl;
}

void Scene::pushPressureObj(PressureType type, std::size_t x, std::size_t y, bool kid, bool adult, std::string target)
{
    // TODO Implements Pressure Obj
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    auto *obj = new SwitchObj(type, kid, adult, target);
    // auto *obj = new MoveObj(Engine::current->getSpriteSheet(SSHEET_ITEMS), 1);
    obj->move(sf::Vector2f(x, y));
    push_back(2, obj);
    
    std::cout << "PressureObj[" << type << "] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "kid = " << (kid ? "true" : "false") << " ";
    std::cout << "adult = " << (adult ? "true" : "false") << " ";
    std::cout << "target = " << target << " ";
    std::cout << std::endl;
}

void Scene::killEnemmy()
{
    for (auto *exit : exitList)
        exit->killEnemmy();
}

void Scene::pushPressure()
{
    for (auto *exit : exitList)
        exit->pushPressure();
}
