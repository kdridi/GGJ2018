#include "Engine.hpp"
#include "Scene.hpp"
#include "SpriteSheet.hpp"
#include "Utils.hpp"
#include "ColliderMap.hpp"
#include "SpriteObj.hpp"
#include "MainObj.hpp"

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
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("rooms/map.png")));
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("BruneSpriteSheet.png")));
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("BruneSpriteSheetEnfant.png")));
    this->sprites.push_back(new SpriteSheet(utils::getFullPath("salles.png")));

    new MainObj(1, 2);
    new MainObj(2, 2);
    
    sound.play_music(Sound::MUSIC_PUZZLE);
    
    return (true);
}

bool Engine::update()
{
    if (nextScene)
    {
        if (scene)
        {
            delete scene;
        }
        
        scene = nextScene;
        {
            auto& sheet = getSpriteSheet(SSHEET_FLOOR);
            auto obj = new SpriteObj(sheet);
            obj->move(sf::Vector2f(0, 0));
            scene->push_back(0, obj);
        }
        scene->init();
        
        nextScene = nullptr;
    }
    
    sf::Event event;
    
    while (window.pollEvent(event))
    {
        this->scene->event(event);
      
        if (event.type == sf::Event::Closed)
        {
            return (false);
        }
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
    {
        new ColliderMap();
        return (*it).second();
    }

    std::stringstream ss;
    ss << "can't create scene with name \"";
    ss << name;
    ss << "\"";
    
    throw ss.str();
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
