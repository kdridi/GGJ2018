#include "Collider.hpp"
#include "ColliderMap.hpp"

bool Collider::test(const sf::Vector2f &v)
{
    sf::Vector2f pos = sf::Vector2f(rect.left, rect.top);
    sf::Vector2f s = sf::Vector2f(rect.width - 1, rect.height - 1);
    ColliderMap::test = this;
    
    if (ColliderMap::current->isCollide({pos.x + v.x      , pos.y       + v.y}) == false &&
        ColliderMap::current->isCollide({pos.x + s.x + v.x, pos.y       + v.y}) == false &&
        ColliderMap::current->isCollide({pos.x + v.x      , pos.y + s.y + v.y}) == false &&
        ColliderMap::current->isCollide({pos.x + s.x + v.x, pos.y + s.y + v.y}) == false)
    {
        if (ColliderMap::current->isCollide({pos.x + v.x + s.x/2, pos.y + v.y          }) == false &&
            ColliderMap::current->isCollide({pos.x + s.x + v.x  , pos.y + v.y   + s.y/2}) == false &&
            ColliderMap::current->isCollide({pos.x + v.x + s.x/2, pos.y + s.y   + v.y  }) == false &&
            ColliderMap::current->isCollide({pos.x + v.x        , pos.y + s.y/2 + v.y  }) == false)
            return (false);
    }
    return (true);
}

Collider* Collider::getTest(const sf::Vector2f &v)
{
    sf::Vector2f pos = sf::Vector2f(rect.left, rect.top);
    sf::Vector2f s = sf::Vector2f(rect.width - 1, rect.height - 1);
    ColliderMap::test = this;
    Collider *c = NULL;
    
    if ((c = ColliderMap::current->getTest({pos.x       + v.x, pos.y       + v.y})) == NULL &&
        (c = ColliderMap::current->getTest({pos.x + s.x + v.x, pos.y       + v.y})) == NULL &&
        (c = ColliderMap::current->getTest({pos.x       + v.x, pos.y + s.y + v.y})) == NULL &&
        (c = ColliderMap::current->getTest({pos.x + s.x + v.x, pos.y + s.y + v.y})) == NULL)
    {
        if ((c = ColliderMap::current->getTest({pos.x       + v.x + s.x/2, pos.y + v.y        })) == NULL &&
            (c = ColliderMap::current->getTest({pos.x + s.x + v.x        , pos.y + v.y + s.y/2})) == NULL &&
            (c = ColliderMap::current->getTest({pos.x + v.x + s.x/2      , pos.y + v.y + s.y  })) == NULL &&
            (c = ColliderMap::current->getTest({pos.x       + v.x        , pos.y + v.y + s.y/2})) == NULL)
            return (c);
    }
    return (c);
}

