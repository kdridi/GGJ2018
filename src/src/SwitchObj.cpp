#include <iostream>

#include "SwitchObj.hpp"
#include "Engine.hpp"

SwitchObj::SwitchObj(PressureType type, bool kid, bool adult, const std::string target) :
  SpriteObj(Engine::current->getSpriteSheet(SSHEET_ITEMS), 1)
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
      std::cout << "OPEN !!!!!!!" << std::endl;
      Scene::current->pushPressure();
    }
  return (true);
}
