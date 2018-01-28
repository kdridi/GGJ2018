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

void JsonScene::init(Engine& engine)
{
    auto& sheet = engine.getSpriteSheet(0);
    
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
                    
                    if (id > 0)
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
}
