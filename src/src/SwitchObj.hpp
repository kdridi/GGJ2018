#pragma once

#include "SpriteObj.hpp"
#include "Scene.hpp"

class SwitchObj : public SpriteObj
{
public:
  SwitchObj(PressureType type, bool kid, bool adult, const std::string target);

  virtual bool update();
public:
  PressureType type;
  bool kid;
  bool adult;
  std::string target;
};
