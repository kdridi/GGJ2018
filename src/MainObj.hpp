#pragma once

#include "SpriteObj.hpp"

class MainObj : public SpriteObj
{
public:
  MainObj(int idJ, SpriteSheet &, unsigned int id);
  MainObj(int idJ, SpriteSheet &, unsigned int id, const sf::IntRect &rect);
  
  virtual void draw() const;
  virtual bool update();
  virtual void move(sf::Vector2f pos);
  void event(sf::Event &e);

  void setActive(bool active)
  {this->active = active;}
private:

  void checkT(int id);
  void moveWithD();
private:

  int idK;
  int	       idJ;
  bool active;
  sf::IntRect rect;
  sf::Vector2f v;
  float f;
};
