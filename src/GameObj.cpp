#include "GameObj.hpp"
#include "Engine.hpp"
#include "SpriteSheet.hpp"

GameObj::GameObj(SpriteSheet &sp) : spriteSheet(sp)
{
  this->sprite.setTexture(this->spriteSheet.getTexture());
}

void	GameObj::draw() const
{
  Engine::current->getWindow().draw(this->sprite);
}
