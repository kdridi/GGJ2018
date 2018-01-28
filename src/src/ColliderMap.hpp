#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>

#include "Collider.hpp"

#define WIDTH 16
#define HEIGHT 16
#define SIZE 64

class ColliderMap
{
public:
    static ColliderMap *current;
    static Collider    *test;
    
    ColliderMap();
    virtual ~ColliderMap() = default;
    
    Collider *getTest(const sf::Vector2f &pos);
    bool    isCollide(const sf::Vector2f &pos);
    
    void addCollider(Collider *collider)
    {
        std::cout << "ColliderMap::addCollider " << this << " with collider : " << collider << std::endl;
        this->colliderList.push_back(collider);
    }
    
    void delleteCollider(Collider *collider)
    {
        this->colliderList.remove(collider);
    }
    
    void addCollider(int x, int y, int id);
private:
    bool    isACollider(int x, int y);
    
private:
    int tile[WIDTH * HEIGHT];
    std::list<Collider *> colliderList;
};

