#pragma once

#include <SFML/Graphics.hpp>


class Actor;
class SpriteSheet;

class GameObj
{
public:
    GameObj(SpriteSheet &);
    GameObj(SpriteSheet &, unsigned int id);
    virtual ~GameObj() = default;
    
    virtual void draw() const;
    virtual bool update();
    void move(sf::Vector2f pos);
  
private:
    sf::Sprite sprite;
    SpriteSheet& spriteSheet;
};

