#include <iostream>

#include "MainObj.hpp"

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
  std::cout << "coucou" << std::endl;
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
  this->sprite.move(v);
  SpriteObj::update();
}

void MainObj::move(sf::Vector2f pos)
{
  SpriteObj::move(pos);
}
