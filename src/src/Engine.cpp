#include "Engine.hpp"
#include "Scene.hpp"
#include "SpriteSheet.hpp"
#include "Utils.hpp"

#include <sstream>

Engine* Engine::current = NULL;

Engine::Engine()
: sprites()
, scene(nullptr)
, nextScene(nullptr)
, window()
{
    Engine::current = this;
}

Engine::~Engine()
{
}

bool Engine::init()
{
    this->window.create(sf::VideoMode(1024, 768), "SFML window");
    this->window.setFramerateLimit(60);
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("spritesheet.png")));
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("BruneSpriteSheet.png")));
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("BruneSpriteSheetEnfant.png")));
    
    return (true);
}

bool Engine::update()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        this->scene->event(event);
      
        if (event.type == sf::Event::Closed)
        {
            return (false);
        }
    }
    
    if (nextScene)
    {
        if (scene)
        {
            nextScene->updateFrom(*scene);
            delete scene;
        }
        
        scene = nextScene;
        scene->init(*this);
        
        nextScene = nullptr;
    }
    
    this->window.clear();
    this->scene->update();
    this->scene->draw();
    this->window.display();
    return (true);
}

Scene* Engine::createScene(std::string name)
{
    auto it = factoryMap.find(name);
    
    if (it != factoryMap.end())
        return (*it).second();
    
    throw "can't create this scene";
}

void Engine::showScene(std::string name)
{
    nextScene = createScene(name);
}

Engine& Engine::registerSceneFactory(std::string name, std::function<Scene*()> factory)
{
    factoryMap[name] = factory;
    return *this;
}
