#pragma once

#include <list>
#include "MoveObj.hpp"

class ShareObj : public MoveObj
{
private:
  static std::list<ShareObj *> objList;
  static void lauchAll(MainObj *obj, sf::Vector2f v);
  
public:
  ShareObj(SpriteSheet &, unsigned int id);
  ~ShareObj();
  
  virtual bool update();
  virtual void lauch(MainObj *obj, sf::Vector2f v);
};
