#pragma once

#include "SpriteObj.hpp"

class MonsterObj : public SpriteObj
{
public:
    MonsterObj(SpriteSheet &sp, unsigned int id);
    
    virtual bool update();
    
    void move(sf::Vector2f pos);
    void moveAt(sf::Vector2f pos);
    
private:
    sf::IntRect rect;
    sf::Vector2f v;
};

