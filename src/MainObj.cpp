#include <iostream>

#include "MainObj.hpp"
#include "ColliderMap.hpp"

MainObj::MainObj(SpriteSheet &s, unsigned int id) : SpriteObj(s, id)
{
  this->v = sf::Vector2f(0, 0);
}

void MainObj::draw() const
{
  SpriteObj::draw();
}

void MainObj::event(sf::Event &e)
{
  if (e.type == sf::Event::KeyPressed)
    {
      if (e.key.code == sf::Keyboard::Up)
	this->v = sf::Vector2f(0, -1);
      if (e.key.code == sf::Keyboard::Down)
	this->v = sf::Vector2f(0, 1);
      if (e.key.code == sf::Keyboard::Left)
	this->v = sf::Vector2f(-1, 0);
      if (e.key.code == sf::Keyboard::Right)
	this->v = sf::Vector2f(1, 0);
    }
}

bool MainObj::update()
{
  sf::Vector2f pos = this->sprite.getPosition();

  if (ColliderMap::current->isCollide({pos.x + v.x, pos.y + v.y}) == false)
    if (ColliderMap::current->isCollide({pos.x + 64 + v.x, pos.y + v.y}) == false)
      if (ColliderMap::current->isCollide({pos.x + v.x, pos.y + 64 + v.y}) == false)
	if (ColliderMap::current->isCollide({pos.x + 64 + v.x, pos.y + 64 + v.y}) == false)
	  this->sprite.move(v);
  SpriteObj::update();
}

void MainObj::move(sf::Vector2f pos)
{
  SpriteObj::move(pos);
}
