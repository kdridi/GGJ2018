#include "CrackObj.hpp"

#include "Engine.hpp"
#include "SpriteSheet.hpp"

CrackObj::CrackObj(SpriteSheet &sp, unsigned int id, const sf::IntRect &rect) : SpriteObj(sp, id)
{
  this->addCollider(rect); 
}

CrackObj::~CrackObj()
{

}

