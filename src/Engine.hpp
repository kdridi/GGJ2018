#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class Scene;

class Engine
{
    
public:
    static Engine    *current;
    
public:
    
    Engine();
    virtual ~Engine();
    
    sf::RenderWindow    &getWindow()
    {
        return this->window;
    }
    
public:
    bool            init();
    bool            update();
    
private:
    
    Scene            *scene;
    sf::RenderWindow      window;
};

