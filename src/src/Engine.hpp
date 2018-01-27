#pragma once

#include <list>
#include <map>
#include <functional>
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
    
    void showScene(std::string name);

    sf::RenderWindow& getWindow()
    {
        return this->window;
    }
    
    SpriteSheet& getSpriteSheet(unsigned int id)
    {
        return (*sprites[id]);
    }
    
    Engine& registerSceneFactory(std::string name, std::function<Scene*()> factory);
    
public:
    bool init();
    bool update();
    
private:
    Scene* createScene(std::string name);
    
    std::map< std::string, std::function<Scene*()> > factoryMap;
    std::vector<SpriteSheet *> sprites;
    Scene* scene;
    Scene* nextScene;
    sf::RenderWindow window;
};
