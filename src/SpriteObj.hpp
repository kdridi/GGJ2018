#pragma once

#include "GameObj.hpp"

class SpriteSheet;

class SpriteObj : public GameObj
{
public:
  SpriteObj(SpriteSheet &);
  SpriteObj(SpriteSheet &, unsigned int id);
  virtual ~SpriteObj() = default;

  virtual void draw() const;
  virtual bool update();
  virtual void move(sf::Vector2f pos);
protected:
  sf::Sprite sprite;
  SpriteSheet& spriteSheet;
};
