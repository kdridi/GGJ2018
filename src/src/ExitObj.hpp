#pragma once

#include <iostream>
#include "SpriteObj.hpp"

class ExitObj : public SpriteObj
{
public:
  ExitObj(const std::string &name, sf::Vector2f size);

  virtual void draw() const;
  virtual bool update();

  void lauch();
protected:
  std::string name;
};
