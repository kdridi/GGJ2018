#include "MainObj.hpp"

MainObj::MainObj(SpriteSheet &s, unsigned int id) : SpriteObj(s, id)
{
}

void MainObj::draw() const
{
  SpriteObj::draw();
}

bool MainObj::update()
{
  SpriteObj::update();
}

void MainObj::move(sf::Vector2f pos)
{
  SpriteObj::move(pos);
}
