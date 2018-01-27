#include "GameObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"

GameObj::GameObj()
{
  this->live = true;
  this->collider = NULL;
}

void GameObj::draw() const
{
}

bool GameObj::update()
{
  if (this->live == false)
    return (false);
  return (true);
}

void GameObj::move(sf::Vector2f)
{
}

void GameObj::event(sf::Event &e)
{
  
}

void GameObj::addCollider(const sf::IntRect &rect)
{
  this->collider = new Collider(rect, this);
}
