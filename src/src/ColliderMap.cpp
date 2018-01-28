#include <iostream>
#include <cstring>
#include "ColliderMap.hpp"

ColliderMap *ColliderMap::current = NULL;
Collider *ColliderMap::test = NULL;

ColliderMap::ColliderMap()
{
    ColliderMap::current = this;
    std::memset(tile, 0, sizeof(*tile) * WIDTH * HEIGHT);
    std::cout << "ColliderMap: " << this << std::endl;
}

Collider* ColliderMap::getTest(const sf::Vector2f &pos)
{
    for (auto collide : this->colliderList)
    {
        if (collide == test)
            continue;
        
        if (collide->rect.contains(pos.x, pos.y) == true)
            return (collide);
    }
    return (NULL);
}

bool  ColliderMap::isCollide(const sf::Vector2f &pos)
{
    sf::Vector2f v = pos;
    Collider *collider = this->getTest(v);
    
    if (collider != NULL)
        return (true);
    
    v.x /= SIZE;
    v.y /= SIZE;
    
    return (this->isACollider(v.x, v.y));
}

bool  ColliderMap::isACollider(int x, int y)
{
    return this->tile[y * WIDTH + x] != 0;
}

void ColliderMap::addCollider(int x, int y, int id)
{
    this->tile[y * WIDTH + x] = id;
}
