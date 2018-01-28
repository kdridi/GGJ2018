//
//  JsonScene.cpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#include "JsonScene.hpp"
#include "SpriteObj.hpp"
#include "Engine.hpp"
#include "ColliderMap.hpp"
#include "MainObj.hpp"

#include <iostream>

void JsonScene::init()
{
    std::cout << std::setw(4) << room << std::endl;
    
    for (auto const& layer : room.at("layers"))
    {
        auto const& name { layer.value("name", "") };
        
        if (name.compare("objects") == 0)
        {
            auto const& objects{ layer["objects"] };
            
            for (auto const& object : objects)
            {
                auto const& type { object.value("type", "") };
                
                if (type.compare("spawn") == 0)
                {
                    auto const& name { object.value("name", "") };
                    if (name.compare("player") == 0)
                    {
                        auto const& size = object["properties"].value("size", "unmodified");
                        uint64_t id = object["properties"]["id"];
                        uint64_t w = object["width"];
                        uint64_t h = object["height"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        uint64_t px = x + w / 2;
                        uint64_t py = y + h / 2;
                        bool big = size.compare("big") == 0;
                        bool* big_ptr = size.compare("unmodified") == 0 ? nullptr : &big;
                        
                        MainObj::updatePlayer(id, px, py, big_ptr);
                        push_back(2, id == 0 ? MainObj::PA : MainObj::PB);
                    } else if (name.compare("enemyClose") == 0)
                    {
                        double damage = object["properties"]["damage"];
                        double hp = object["properties"]["hp"];
                        uint64_t w = object["width"];
                        uint64_t h = object["height"];
                        uint64_t x = object["x"];
                        uint64_t y = object["y"];
                        
                        pushEnemyCloseObj(x, y, w, h, damage, hp);
                    }
                } else if (type.compare("exit") == 0)
                {
                    auto const& name { object.value("name", "") };
                    uint64_t w = object["width"];
                    uint64_t h = object["height"];
                    uint64_t x = object["x"];
                    uint64_t y = object["y"];
                    pushExitObj(name, x, y, w, h);
                }
            }
        }
        
        if (name.compare("env") == 0)
        {
            uint64_t const& width{layer["width"]};
            uint64_t const& height{layer["height"]};
            
            auto const& data{ layer["data"] };
            
            for (uint64_t y = 0; y < height; ++y)
            {
                for (uint64_t x = 0; x < width; ++x)
                {
                    uint64_t id = data.at(y * width + x);
                    
                    switch (id) {
                        case SPRITE_WALL:
                            pushWallObj(x, y);
                            break;
                        case SPRITE_STATIC:
                            pushStaticObj(x, y);
                            break;
                        case SPRITE_DOOR0:
                        case SPRITE_DOOR1:
                            pushDoorObj(x, y);
                            break;
                        case SPRITE_DOOR_SMALL:
                            pushDoorSmallObj(x, y);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}

