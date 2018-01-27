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
  virtual void addCollider(const sf::IntRect &);

  virtual int getY() const;
  virtual sf::Vector2f getPos() const
  {return this->sprite.getPosition();}
  
protected:
  sf::Sprite sprite;
  SpriteSheet& spriteSheet;
};
