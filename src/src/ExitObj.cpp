#include <iostream>

#include "ExitObj.hpp"
#include "SpriteSheet.hpp"
#include "Engine.hpp"

ExitObj::ExitObj(Engine& engine, const std::string &name, sf::Vector2f size, bool open)
: SpriteObj(Engine::current->getSpriteSheet(SSHEET_PLAYER_BIG), 0)
, engine(engine)
, open(open)
{
    this->name = name;
    this->addCollider(sf::IntRect(0, 0, size.x, size.y));
}

void ExitObj::draw() const
{
    
}

bool ExitObj::update()
{
    return (true);
}

void ExitObj::lauch()
{
    std::cout << this->name << std::endl;
    engine.showScene(name);
}

