#include <iostream>

#include "SwitchObj.hpp"
#include "Engine.hpp"

SwitchObj::SwitchObj(PressureType type, bool kid, bool adult, const std::string target)
: SpriteObj(Engine::current->getSpriteSheet(SSHEET_ITEMS), SPRITE_PRESSURE - 1)
, triggered(false)
{
    this->type = type;
    this->kid = kid;
    this->adult = adult;
    this->target = target;
    
    this->addCollider(sf::IntRect(0, 0, 64, 64));
}

bool SwitchObj::update()
{
    if (this->collider->test(sf::Vector2f(0, 0)) == true)
    {
        if (type == PRESSURE_OPEN_DOOR && triggered == false)
        {
            std::cout << "OPEN !!!!!!!" << std::endl;
            Scene::current->pushPressure();
            triggered = true;
        }
    }
    return (true);
}

