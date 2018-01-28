//
//  Spells.cpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#include "Spells.hpp"

Spells::Spells()
: _types()
, _position(0)
{
}

Spells::Type Spells::left()
{
    unsigned int position = _position + 0;
    
    if (position >= _types.size())
        return SPELL_NONE;
    
    return _types[position];
}

Spells::Type Spells::right()
{
    unsigned int position = _position + 1;
    
    if (position >= _types.size())
        return SPELL_NONE;
    
    return _types[position];
}

void Spells::move_left()
{
    if (_position >= 1)
        _position -= 1;
}

void Spells::move_right()
{
    if (_position + 1 < _types.size() - 1)
        _position += 1;
}

void Spells::push_spell(Spells::Type type)
{
    for (auto t : _types)
        if (t == type)
            return;
    
    _types.push_back(type);
}

void Spells::remove_spell(Spells::Type type)
{
    unsigned int index = 0;
    int position = -1;
    
    for (auto t : _types)
    {
        if (t == type)
            position = index;
        
        index += 1;
    }
    
    if (position >= 0)
    {
        _types.erase (_types.begin() + position);
        
        if (_position >= _types.size() - 1)
            move_left();
        
        if (_types.empty())
            _position = 0;
    }
}





