#include <iostream>

#include "MainObj.hpp"
#include "ColliderMap.hpp"
#include "SpriteSheet.hpp"
#include "MoveObj.hpp"
#include "Engine.hpp"
#include "Scene.hpp"
#include "ExitObj.hpp"
#include "AttackObj.hpp"
#include "SwitchObj.hpp"

MainObj    *MainObj::PA = NULL;
MainObj    *MainObj::PB = NULL;

MainObj::MainObj(int idJ, int state) :
SpriteObj(Engine::current->getSpriteSheet(SSHEET_PLAYER_BIG), 0)
{
    sf::IntRect rect = sf::IntRect(0, 0, 50, 122);
    
    this->idJ = idJ;
    if (this->idJ == 1)
        MainObj::PA = this;
    if (this->idJ == 2)
        MainObj::PB = this;
    this->v = sf::Vector2f(0, 0);
    this->rect = rect;
    this->addCollider(sf::IntRect(0, 0, rect.width, rect.width));
    this->sprite.setTextureRect(this->spriteSheet.getId(0, rect));
    this->active = true;
    this->state = 2;
    this->inv = 0;
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
	  if (e.key.code == sf::Keyboard::R)
            {
	      this->suicide();
            }
	  if (e.key.code == sf::Keyboard::LShift)
            {
	      sf::Vector2f size(this->collider->rect.width, this->collider->rect.height);
	      AttackObj *obj = new AttackObj(30, true, this);
                
	      obj->move(sf::Vector2f(this->collider->rect.left, this->collider->rect.top)
			+ sf::Vector2f(size.x, 0));
	      Scene::current->push_back(1, obj);
	      this->active = false;
            }
            
	  if (e.key.code == sf::Keyboard::W)
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
	  if (e.key.code == sf::Keyboard::A)
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
	  if (e.key.code == sf::Keyboard::W && this->idK == 0)
	    this->v = sf::Vector2f(0, 0);
	  if (e.key.code == sf::Keyboard::S && this->idK == 1)
	    this->v = sf::Vector2f(0, 0);
	  if (e.key.code == sf::Keyboard::A && this->idK == 2)
	    this->v = sf::Vector2f(0, 0);
	  if (e.key.code == sf::Keyboard::D && this->idK == 3)
	    this->v = sf::Vector2f(0, 0);
        }
    }
  else if (this->idJ == 2)
    {
      if (e.type == sf::Event::KeyPressed)
        {
	  if (e.key.code == sf::Keyboard::U)
            {
	      this->suicide();
            }
	  if (e.key.code == sf::Keyboard::M)
            {
	      sf::Vector2f size(this->collider->rect.width, this->collider->rect.height);
	      AttackObj *obj = new AttackObj(30, true, this);
                
	      obj->move(sf::Vector2f(this->collider->rect.left, this->collider->rect.top)
			+ sf::Vector2f(size.x, 0));
	      Scene::current->push_back(1, obj);
	      this->active = false;
            }

	    
	  if (e.key.code == sf::Keyboard::O)
            {
	      this->sprite.setTextureRect(this->spriteSheet.getId(1, this->rect));
	      this->v = sf::Vector2f(0, -f);
	      this->idK = 0;
            }
	  if (e.key.code == sf::Keyboard::L)
            {
	      this->sprite.setTextureRect(this->spriteSheet.getId(0, this->rect));
	      this->v = sf::Vector2f(0, f);
	      this->idK = 1;
            }
	  if (e.key.code == sf::Keyboard::K)
            {
	      this->sprite.setTextureRect(this->spriteSheet.getId(2, this->rect));
	      this->v = sf::Vector2f(-f, 0);
	      this->idK = 2;
            }
	  if (e.key.code == sf::Keyboard::SemiColon)
            {
	      this->sprite.setTextureRect(this->spriteSheet.getId(3, this->rect));
	      this->v = sf::Vector2f(f, 0);
	      this->idK = 3;
            }
        }
      else if (e.type == sf::Event::KeyReleased)
        {
	  if (e.key.code == sf::Keyboard::O && this->idK == 0)
	    this->v = sf::Vector2f(0, 0);
	  if (e.key.code == sf::Keyboard::L && this->idK == 1)
	    this->v = sf::Vector2f(0, 0);
	  if (e.key.code == sf::Keyboard::K && this->idK == 2)
	    this->v = sf::Vector2f(0, 0);
	  if (e.key.code == sf::Keyboard::SemiColon && this->idK == 3)
	    this->v = sf::Vector2f(0, 0);
        }
    }
}

bool MainObj::update()
{
    if (this->active == false)
        return (true);
    
    if (this->collider != nullptr)
    {
        if (this->collider->test(this->v))
        {
            Collider *c = this->collider->getTest(this->v);
            if (c != nullptr)
            {
                MoveObj *m = dynamic_cast<MoveObj *>(c->obj);
                ExitObj *e = dynamic_cast<ExitObj *>(c->obj);
		SwitchObj *s = dynamic_cast<SwitchObj *>(c->obj);
		
                if (m != NULL)
                {
                    m->lauch(this, sf::Vector2f(this->v.x / f, this->v.y / f));
                    this->v = sf::Vector2f(0, 0);
                }
                else if (e != NULL)
                {
                    if (e->open())
                    {
                        e->lauch();
                        move(v);
                    }
                }
                else if (s != NULL)
                {
		  move(v);
                }
            }
        }
        else
        {
            move(v);
        }
    }

    if (this->inv > 0)
      this->inv -= 1;
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
    
    pos.y -= size.y;
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
    this->sprite.setTexture(Engine::current->getSpriteSheet(SSHEET_PLAYER_SMALL).getTexture());
    this->sprite.setTextureRect(this->spriteSheet.getId(0, rect));
    
    this->move(sf::Vector2f(20, 42));
    std::cout << this->collider->rect.top << " " << this->collider->rect.left << std::endl;
    
    Engine::current->sound.play_sound(Sound::GO_SMALL);
}

void MainObj::growUp()
{
    if (this->state != 1)
        return ;
    
    this->state = 2;
    sf::IntRect rect = sf::IntRect(0, 0, 50, 122);
    
    this->rect = rect;
    this->addCollider(sf::IntRect(0, 0, rect.width, rect.width));
    this->sprite.setTexture(Engine::current->getSpriteSheet(SSHEET_PLAYER_BIG).getTexture());
    this->sprite.setTextureRect(this->spriteSheet.getId(0, rect));
    
    this->move(sf::Vector2f(-20, -42));
    
}

sf::Vector2f MainObj::getPos() const
{
    sf::Vector2f pos(this->collider->rect.left, this->collider->rect.top);
    
    return (pos);
}

void MainObj::updatePlayer(std::size_t id, std::size_t x, std::size_t y, bool* big)
{
    MainObj *p = id == 0 ? MainObj::PA : MainObj::PB;
    std::cout << "Player[" << id << "] ";
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << " ";
    std::cout << "size = " << ((big == nullptr) ? "unmodified" : (*big ? "big" : "small")) << std::endl;
    p->moveAt(sf::Vector2f(x, y));
    if (big != nullptr)
    {
        if (*big)
            p->growUp();
        else
            p->suicide();
    }
}


void MainObj::takeDmg()
{
  if (this->inv <= 0)
    {
      if (this->state == 2)
	this->suicide();
      else
	std::cout << "DEATH" << std::endl;
      this->inv = 120;
    }
}
