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

#include <iostream>

void JsonScene::init(Engine& engine)
{
    auto& sheet = engine.getSpriteSheet(0);
    
    std::cout << std::setw(4) << room << std::endl;
    
    for (auto const& layer : room.at("layers"))
    {
        auto const& name { layer.value("name", "") };
        
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

