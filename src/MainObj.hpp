#pragma once

#include "SpriteObj.hpp"

class MainObj : public SpriteObj
{
public:
  MainObj(SpriteSheet &, unsigned int id);
  
  virtual void draw() const;
  virtual bool update();
  virtual void move(sf::Vector2f pos);
};
