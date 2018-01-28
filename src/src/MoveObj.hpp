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
  virtual void lauch(MainObj *, sf::Vector2f v);

  virtual bool canLauch(sf::Vector2f v) const;
protected:
  int	       step;
  sf::Vector2f v;
  MainObj *obj;
  int state;
};
