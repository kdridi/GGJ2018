#include <iostream>
#include "ColliderMap.hpp"


ColliderMap *ColliderMap::current = NULL;
Collider *ColliderMap::test = NULL;

ColliderMap::ColliderMap(int *tile, const sf::Vector2i &size,
			 const sf::Vector2i &mul, const std::vector<int> &colliderId)
{
  this->tile = tile;
  this->width = size.x;
  this->height = size.y;
  this->mul = mul;
  this->colliderId = colliderId;
  ColliderMap::current = this;
}

Collider  *ColliderMap::getTest(const sf::Vector2f &pos)
{
  for (auto collide : this->colliderList)
    {
      if (collide == test)
	continue;
      if (collide->rect.contains(pos.x, pos.y) == true)
	return (collide);
    }
  return (NULL);
}

bool  ColliderMap::isCollide(const sf::Vector2f &pos)
{
  sf::Vector2f v = pos;
  Collider *collider = this->getTest(v);

  if (collider != NULL)
    return (true);
  v.x /= this->mul.x;
  v.y /= this->mul.y;

  return (this->isACollider(v.x, v.y));
}

bool  ColliderMap::isACollider(int x, int y)
{
  return (this->isACollider(this->tile[y * this->width + x]));
}

bool  ColliderMap::isACollider(int id)
{
  for (auto it : this->colliderId)
    if (it == id)
      return (true);
  return (false);
}
