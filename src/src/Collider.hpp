#pragma once

#include <SFML/Graphics.hpp>

class GameObj;

struct Collider
{
  Collider(const sf::IntRect &rect, GameObj *obj)
  {this->rect = rect; this->obj = obj;}

  bool	test(const sf::Vector2f &);
  Collider *getTest(const sf::Vector2f &);
  
  sf::IntRect rect;
  GameObj      *obj;
};
