#pragma once

#include "SpriteObj.hpp"

class Colider;

class CrackObj : public SpriteObj
{
  
public:
  
  CrackObj(SpriteSheet &, unsigned int id, const sf::IntRect &);
  ~CrackObj();
  
};
