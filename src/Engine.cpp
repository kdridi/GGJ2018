#include "Engine.hpp"
#include "Scene.hpp"

Engine        *Engine::current = NULL;

Engine::Engine()
{
    Engine::current = this;
    this->scene = new Scene();
}

Engine::~Engine()
{
    delete this->scene;
}

bool    Engine::init()
{
    this->window.create(sf::VideoMode(1024, 768), "SFML window");
    
    if (this->scene->init() == false)
        return (false);
    
    return (true);
}

bool    Engine::update()
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

