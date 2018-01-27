#pragma once

#include <SFML/Graphics.hpp>

class SpriteSheet;

class GameObj
{
public:
  GameObj(SpriteSheet &);
  ~GameObj() = default;

  void		draw() const;
  
private:
  
  sf::Sprite	sprite;
  SpriteSheet	&spriteSheet;
};
