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
    
    bool init();
    bool draw();
    
private:
    void push_back(int layerId, GameObj *obj);
    
    std::array<std::list<GameObj *>, 10>  layerList;
};

