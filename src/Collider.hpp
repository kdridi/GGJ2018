#pragma once

#include <SFML/Graphics.hpp>

class GameObj;

struct Collider
{
  Collider(const sf::IntRect &rect, GameObj *obj)
  {this->rect = rect; this->obj = obj;}

  sf::IntRect rect;
  GameObj      *obj;
};
