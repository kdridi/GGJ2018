#pragma once

#include "SpriteObj.hpp"

class MainObj : public SpriteObj
{
public:
  MainObj(int idJ, SpriteSheet &, unsigned int id);
  
  virtual void draw() const;
  virtual bool update();
  virtual void move(sf::Vector2f pos);
  void event(sf::Event &e);

  
private:

  void checkT(int id);
  void moveWithD();
private:
  int	       idJ;
  sf::Vector2f v;
};
