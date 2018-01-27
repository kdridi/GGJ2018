#include <iostream>

#include "MainObj.hpp"
#include "ColliderMap.hpp"
#include "SpriteSheet.hpp"
#include "MoveObj.hpp"
#include "Engine.hpp"


MainObj::MainObj(int idJ, int state) :
  SpriteObj(Engine::current->getSpriteSheet(1), 0)
{
  sf::IntRect rect = sf::IntRect(0, 0, 50, 122);
  
    this->idJ = idJ;
    this->v = sf::Vector2f(0, 0);
    this->rect = rect;
    this->addCollider(sf::IntRect(0, 0, rect.width, rect.width));
    this->sprite.setTextureRect(this->spriteSheet.getId(0, rect));
    this->active = true;
    this->state = 2;
}

void MainObj::draw() const
{
    SpriteObj::draw();
}

void MainObj::event(sf::Event &e)
{
  this->f = 5.5;
  
  if (this->active == false)
    return ;
    if (this->idJ == 1)
    {
        if (e.type == sf::Event::KeyPressed)
        {
	    if (e.key.code == sf::Keyboard::A)
	    {
	      this->suicide();
	    }

	    if (e.key.code == sf::Keyboard::E)
	    {
	      this->growUp();
	    }

            if (e.key.code == sf::Keyboard::Up)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(1, this->rect));
                this->v = sf::Vector2f(0, -f);
                this->idK = 0;
            }
            if (e.key.code == sf::Keyboard::Down)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(0, this->rect));
                this->v = sf::Vector2f(0, f);
                this->idK = 1;
            }
            if (e.key.code == sf::Keyboard::Left)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(2, this->rect));
                this->v = sf::Vector2f(-f, 0);
                this->idK = 2;
            }
            if (e.key.code == sf::Keyboard::Right)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(3, this->rect));
                this->v = sf::Vector2f(f, 0);
                this->idK = 3;
            }
        }
        else if (e.type == sf::Event::KeyReleased)
        {
            if (e.key.code == sf::Keyboard::Up && this->idK == 0)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Down && this->idK == 1)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Left && this->idK == 2)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Right && this->idK == 3)
                this->v = sf::Vector2f(0, 0);
        }
    }
    else if (this->idJ == 2)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Z)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(1, this->rect));
                this->v = sf::Vector2f(0, -f);
                this->idK = 0;
            }
            if (e.key.code == sf::Keyboard::S)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(0, this->rect));
                this->v = sf::Vector2f(0, f);
                this->idK = 1;
            }
            if (e.key.code == sf::Keyboard::Q)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(2, this->rect));
                this->v = sf::Vector2f(-f, 0);
                this->idK = 2;
            }
            if (e.key.code == sf::Keyboard::D)
            {
	        this->sprite.setTextureRect(this->spriteSheet.getId(3, this->rect));
                this->v = sf::Vector2f(f, 0);
                this->idK = 3;
            }
        }
        else if (e.type == sf::Event::KeyReleased)
        {
            if (e.key.code == sf::Keyboard::Z && this->idK == 0)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::S && this->idK == 1)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::Q && this->idK == 2)
                this->v = sf::Vector2f(0, 0);
            if (e.key.code == sf::Keyboard::D && this->idK == 3)
                this->v = sf::Vector2f(0, 0);
        }
    }
}

bool MainObj::update()
{
  if (this->active == false)
    return (true);
  if (this->collider != NULL && this->collider->test(this->v) == false)
    this->move(v);
  else
    {
      Collider *c = this->collider->getTest(this->v);
      MoveObj *m;
      
      if (c != NULL && (m = dynamic_cast<MoveObj *>(c->obj)) != NULL)
	{
	  m->lauch(this, sf::Vector2f(this->v.x / f, this->v.y / f));
	  this->v = sf::Vector2f(0, 0);
	}

    }
    
  return (SpriteObj::update());
}

void MainObj::move(sf::Vector2f pos)
{
  sf::Vector2f v = this->sprite.getPosition();
  sf::Vector2f size = sf::Vector2f(this->sprite.getTextureRect().width,
				   this->sprite.getTextureRect().height);
  
  if (this->collider != NULL)
    {
      this->collider->rect.top = v.y + pos.y + (size.y - size.x);
      this->collider->rect.left = v.x + pos.x;
    }
  this->sprite.setPosition(v.x + pos.x, v.y + pos.y);
}

void MainObj::moveAt(sf::Vector2f pos)
{
  sf::Vector2f size = sf::Vector2f(this->sprite.getTextureRect().width,
				   this->sprite.getTextureRect().height);

  if (this->collider != NULL)
    {
      this->collider->rect.top = pos.y + (size.y - size.x);
      this->collider->rect.left = pos.x;
    }
  this->sprite.setPosition(pos.x, pos.y);
}

void MainObj::suicide()
{
  if (this->state != 2)
    return ;
  
  this->state = 1;
  sf::IntRect rect = sf::IntRect(0, 0, 30, 80);

  this->rect = rect;
  this->addCollider(sf::IntRect(0, 0, rect.width, rect.width));
  this->sprite.setTexture(Engine::current->getSpriteSheet(2).getTexture());
  this->sprite.setTextureRect(this->spriteSheet.getId(0, rect));

  sf::Vector2f size = sf::Vector2f(this->sprite.getTextureRect().width,
  				   this->sprite.getTextureRect().height);
  sf::Vector2f pos = this->sprite.getPosition();

  this->collider->rect.top = pos.y + (size.y - size.x);
  this->collider->rect.left = pos.x;
  this->sprite.move(20, 42);

}

void MainObj::growUp()
{
  if (this->state != 1)
    return ;

  this->state = 2;
  sf::IntRect rect = sf::IntRect(0, 0, 50, 122);

  this->rect = rect;
  this->addCollider(sf::IntRect(0, 0, rect.width, rect.width));
  this->sprite.setTexture(Engine::current->getSpriteSheet(1).getTexture());
  this->sprite.setTextureRect(this->spriteSheet.getId(0, rect));

  sf::Vector2f size = sf::Vector2f(this->sprite.getTextureRect().width,
				   this->sprite.getTextureRect().height);
  sf::Vector2f pos = this->sprite.getPosition();

  this->collider->rect.top = pos.y + (size.y - size.x);
  this->collider->rect.left = pos.x;
  this->sprite.move(-20, -42);

}
