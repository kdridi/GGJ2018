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
#include "MonsterObj.hpp"
#include "ShareObj.hpp"

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
    12, 0, 0, 0,12,12,12,12,12,12,12,12, 0, 5, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 1, 0,11, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 0, 0,12, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 2, 0,12, 0, 0, 0,12,
    12, 0, 0, 0,12, 0, 0, 0, 0, 0, 0,11, 0, 0, 0,12,
    12, 0, 0, 0,12,12,12,12,12,12,12,12, 0, 0, 0,12,
    12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0,12,
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

void FakeSceneA::init()
{
    auto& sheet = engine.getSpriteSheet(SSHEET_ITEMS);
    
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
                if (id == 1) // first player
                {
                    auto *obj = new MainObj(1, 1);
                    obj->moveAt(sf::Vector2f(x * 64, y * 64));
                    setPlayer(0, obj);
                }
                else if (id == 2) // second player
                {
                    auto *obj = new MainObj(2, 1);
                    obj->moveAt(sf::Vector2f(x * 64, y * 64));
                    setPlayer(1, obj);
                }
                else if (id == 11) // wall hole
                {
                    auto *obj = new CrackObj(sheet, 0, sf::IntRect(0, 0, 64, 15));
                    obj->move(sf::Vector2f(x * 64, y * 64));
                    push_back(2, obj);
                }
                else if (id == 4) // monster
                {
                    auto *obj = new MonsterObj(engine.getSpriteSheet(SSHEET_MONSTER), 0);
                    obj->moveAt(sf::Vector2f(x * 64, y * 64));
                    push_back(2, obj);
                }
                else if (id == 5) // Share
                {
                    auto *obj = new ShareObj(engine.getSpriteSheet(0), 0);
                    obj->move(sf::Vector2f(x * 64, y * 64));
                    push_back(2, obj);
                }
                else
                {
                    auto obj = new SpriteObj(sheet, id - 1);
                    obj->move(sf::Vector2f(x * 64, y * 64));
                    push_back(1, obj);
                    ColliderMap::current->addCollider(x, y, id);
                }
            }
        }
    }
}
