#pragma once

#include "SpriteObj.hpp"

class MainObj : public SpriteObj
{
public:
  MainObj(int idJ, int state);
  
  virtual void draw() const;
  virtual bool update();
  virtual void move(sf::Vector2f pos);
  virtual void moveAt(sf::Vector2f pos);
  void event(sf::Event &e);

  void setActive(bool active)
  {this->active = active;}
private:

  void checkT(int id);
  void moveWithD();

  void suicide();
  void growUp();
private:

  int idK;
  int	       idJ;
  bool active;
  sf::IntRect rect;
  sf::Vector2f v;
  float f;
  int state;
    
public:
    static void updatePlayer(std::size_t id, std::size_t x, std::size_t y, bool* big);
};
