#pragma once

#include <list>
#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class Engine;
class GameObj;
class MainObj;
class Actor;

enum SpriteType
{
    SPRITE_WALL = 1,
    SPRITE_STATIC = 2,
    SPRITE_MOBILE = 3,
    SPRITE_LINKED = 4,
    SPRITE_FLOOR = 5,
    SPRITE_PRESSURE = 6,
    SPRITE_DOOR0 = 7,
    SPRITE_DOOR1 = 8,
    SPRITE_BOSS0 = 9,
    SPRITE_BOSS1 = 10,
    SPRITE_ENEMY_AWAY = 11,
    SPRITE_DOOR_SMALL = 12,
    SPRITE_BOSS2 = 13,
    SPRITE_BOSS3 = 14,
    SPRITE_ENEMY_CLOSE = 15,
    SPRITE_PRESSURE_SMALL = 16,
};

class Scene
{
public:
  static Scene *current;
  
public:
    Scene(Engine& engine);
    virtual ~Scene();

    void event(sf::Event &event);
    bool draw();
    bool update();
    
    virtual void init();
    void push_back(int layerId, GameObj *obj);

protected:
    void pushExitObj(std::string name, std::size_t x, std::size_t y, std::size_t w, std::size_t h);
    void pushWallObj(std::size_t x, std::size_t y);
    void pushStaticObj(std::size_t x, std::size_t y);
    void pushDoorObj(std::size_t x, std::size_t y);
    void pushDoorSmallObj(std::size_t x, std::size_t y);
    void pushEnemyCloseObj(std::size_t x, std::size_t y, std::size_t w, std::size_t h, double damage, double hp);
    Engine& engine;

private:
    std::array<std::list<GameObj *>, 10> layerList;
};

