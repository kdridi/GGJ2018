//
//  FakeSceneA.cpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#include "FakeSceneA.hpp"
#include "Engine.hpp"

#include "SpriteObj.hpp"
#include "MainObj.hpp"
#include "ColliderMap.hpp"
#include "MoveObj.hpp"
#include "CrackObj.hpp"

FakeSceneA::~FakeSceneA()
{
}

static int ids0[] = {
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};

static int ids1[] = {
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0,12,12,12,12,12,12,12,12, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 1, 0,11, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 0, 0,12, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 2, 0,12, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 0, 0,11, 0, 0, 0,12,
    12, 0, 0, 0,12,12,12,12,12,12,12,12, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
};

// static int ids1[] = {
//     12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0,12, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0,12, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,
//     12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
// };

void FakeSceneA::init(Engine& engine)
{
    auto& sheet = engine.getSpriteSheet(0);
    auto& brune = engine.getSpriteSheet(1);
    auto& enfant = engine.getSpriteSheet(2);
    
    new ColliderMap(ids1, sf::Vector2i(16, 12), sf::Vector2i(64, 64), {12});
    for (int x = 0; x < 16; ++x)
    {
        for (int y = 0; y < 12; ++y)
        {
            auto id = ids0[y * 16 + x];
            if (id > 0)
            {
                auto obj = new SpriteObj(sheet, id - 1);
                obj->move(sf::Vector2f(x * 64, y * 64));
                
                push_back(0, obj);
            }
        }
    }
    
    for (int x = 0; x < 16; ++x)
    {
        for (int y = 0; y < 12; ++y)
        {
            auto id = ids1[y * 16 + x];
            if (id > 0)
            {
                if (id == 1)
                {
                    auto *obj = new MainObj(1, brune, 0, sf::IntRect(0, 0, 50, 122));
                    obj->moveAt(sf::Vector2f(x * 64, y * 64));
                    setPlayer(0, obj);
                }
                else if (id == 2)
                {
                    auto *obj = new MainObj(2, enfant, 0, sf::IntRect(0, 0, 31, 80));
                    obj->moveAt(sf::Vector2f(x * 64, y * 64));
                    setPlayer(1, obj);
                }
                else if (id == 11)
                {
                    
                    auto *obj = new CrackObj(sheet, 0, sf::IntRect(0, 0, 64, 30));
                    obj->move(sf::Vector2f(x * 64, y * 64));
                    push_back(2, obj);
                }
                else
                {
                    auto obj = new SpriteObj(sheet, id - 1);
                    obj->move(sf::Vector2f(x * 64, y * 64));
                    
                    push_back(1, obj);
                }
            }
        }
    }
}