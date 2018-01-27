#pragma once

#include "SpriteObj.hpp"

class MainObj;

class MoveObj : public SpriteObj
{
public:
  MoveObj(SpriteSheet &);
  MoveObj(SpriteSheet &, unsigned int id);

  Collider	*getCollider()
  {return (this->collider);}

  virtual bool update();
  void lauch(MainObj *, sf::Vector2f v);
private:
  int	       step;
  sf::Vector2f v;
  MainObj *obj;
  int state;
};
