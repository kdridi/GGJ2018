#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Collider.hpp"

class ColliderMap
{
public:
  static ColliderMap *current;
  static Collider    *test;
  
  ColliderMap(int *tile, const sf::Vector2i &size,
	      const sf::Vector2i &mul, const std::vector<int> &colliderId);
  virtual ~ColliderMap() = default;


  Collider *getTest(const sf::Vector2f &pos);
  bool	isCollide(const sf::Vector2f &pos);

  void	addCollider(Collider *collider)
  {this->colliderList.push_back(collider);}
  
private:

  bool	isACollider(int id);
  bool	isACollider(int x, int y);
  
private:
  int	*tile;
  int	width;
  int	height;
  sf::Vector2i	mul;
  std::vector<int> colliderId;
  std::vector<Collider *> colliderList;
};
