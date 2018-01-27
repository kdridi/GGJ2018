#include "Engine.hpp"
#include "Scene.hpp"
#include "SpriteSheet.hpp"

#include <sstream>

Engine* Engine::current = NULL;

Engine::Engine(std::string assetsDir)
: assetsDir(assetsDir)
{
    Engine::current = this;
    this->scene = new Scene();
}

Engine::~Engine()
{
}

bool Engine::init()
{
    this->window.create(sf::VideoMode(1024, 768), "SFML window");
    this->sprites.push_back(new SpriteSheet(getFullPath("spritesheet.png")));
    
    if (this->scene->init() == false)
        return (false);
    
    return (true);
}

bool Engine::update()
{
    sf::Event event;
    
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            return (false);
        }
    }
    
    this->window.clear();
    this->scene->draw();
    this->window.display();
    return (true);
}

std::string Engine::getFullPath(std::string path)
{
    std::stringstream ss;
    ss << assetsDir;
    ss << "/";
    ss << path;
    
    return ss.str();
}

