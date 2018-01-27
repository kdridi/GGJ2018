#pragma once

#include <list>
#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class Engine;
class GameObj;
class MainObj;
class Actor;

class Scene
{
public:
    Scene();
    virtual ~Scene();

    void event(sf::Event &event);
    bool draw();
    bool update();
    
    void updateFrom(Scene& previous);
    virtual void init(Engine& engine);
    void setPlayer(std::size_t id, MainObj* obj);

protected:
    void push_back(int layerId, GameObj *obj);
    void pushExitObj(std::string name, std::size_t x, std::size_t y, std::size_t w, std::size_t h);
    
private:
    std::array<std::list<GameObj *>, 10> layerList;
    std::array<MainObj *, 2> players;
};

