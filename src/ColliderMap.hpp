#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ColliderMap
{
public:
  static ColliderMap *current;
  
  ColliderMap(int *tile, const sf::Vector2i &size,
	      const sf::Vector2i &mul, const std::vector<int> &colliderId);
  virtual ~ColliderMap() = default;


  bool	isCollide(const sf::Vector2f &pos);
private:

  bool	isACollider(int id);
  bool	isACollider(int x, int y);
  
private:
  int	*tile;
  int	width;
  int	height;
  sf::Vector2i	mul;
  std::vector<int> colliderId;
};
