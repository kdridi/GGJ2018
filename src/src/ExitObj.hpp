#pragma once

#include <iostream>
#include "SpriteObj.hpp"

class Engine;

class ExitObj : public SpriteObj
{
public:
    ExitObj(Engine& engine, const std::string &name, sf::Vector2f size, std::size_t enemyLock, std::size_t pressureLock);
    
    virtual void draw() const;
    virtual bool update();
    
    void lauch();

public:
    bool open();
    
protected:
    std::string name;
    Engine& engine;
    std::size_t enemyLock;
    std::size_t pressureLock;
};

