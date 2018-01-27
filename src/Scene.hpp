#pragma once

#include <list>
#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class GameObj;
class Actor;

class Scene
{
public:
    Scene();
    virtual ~Scene();

    void event(sf::Event &event);
    bool init();
    bool draw();
    bool update();
    
private:
    void push_back(int layerId, GameObj *obj);
    
    std::array<std::list<GameObj *>, 10>  layerList;
};

