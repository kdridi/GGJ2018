#include <iostream>

#include "MainObj.hpp"
#include "ColliderMap.hpp"

MainObj::MainObj(int idJ, SpriteSheet &s, unsigned int id) : SpriteObj(s, id)
{
  this->idJ = idJ;
  this->v = sf::Vector2f(0, 0);
  this->addCollider(sf::IntRect(0, 0, 64, 64));
}

void MainObj::draw() const
{
  SpriteObj::draw();
}

void MainObj::event(sf::Event &e)
{
  if (this->idJ == 1)
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
  else if (this->idJ == 2)
    {
      if (e.type == sf::Event::KeyPressed)
	{
	  if (e.key.code == sf::Keyboard::Z)
	    this->v = sf::Vector2f(0, -1);
	  if (e.key.code == sf::Keyboard::S)
	    this->v = sf::Vector2f(0, 1);
	  if (e.key.code == sf::Keyboard::Q)
	    this->v = sf::Vector2f(-1, 0);
	  if (e.key.code == sf::Keyboard::D)
	    this->v = sf::Vector2f(1, 0);
	}
    }
}

bool MainObj::update()
{
  sf::Vector2f pos = this->sprite.getPosition();
  
  ColliderMap::test = this->collider;
  if (ColliderMap::current->isCollide({pos.x + v.x, pos.y + v.y}) == false)
    if (ColliderMap::current->isCollide({pos.x + 64 + v.x, pos.y + v.y}) == false)
      if (ColliderMap::current->isCollide({pos.x + v.x, pos.y + 64 + v.y}) == false)
	if (ColliderMap::current->isCollide({pos.x + 64 + v.x, pos.y + 64 + v.y}) == false)
	  this->move(v);

  return (SpriteObj::update());
}

void MainObj::move(sf::Vector2f pos)
{
  SpriteObj::move(pos);
}
