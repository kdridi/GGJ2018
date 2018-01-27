#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class Scene;
class SpriteSheet;

class Engine
{
    
public:
    static Engine* current;
    
public:
    
    Engine();
    virtual ~Engine();
    
    sf::RenderWindow& getWindow()
    {
        return this->window;
    }
    
    SpriteSheet& getSpriteSheet(unsigned int id)
    {
        return (*sprites[id]);
    }
    
    
public:
    bool init();
    bool update();
    
private:
    std::vector<SpriteSheet *> sprites;
    Scene* scene;
    sf::RenderWindow window;
};

