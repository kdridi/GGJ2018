//
//  Spells.hpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#ifndef Spells_hpp
#define Spells_hpp

#include <vector>

class Spells
{
public:
    Spells();
    
    enum Type
    {
        SPELL_NONE,

        SPELL_FIREBALL,
        SPELL_ELECTRIC,
        SPELL_HEAL,
        SPELL_SNARE,
        
        SPELL_SWORD,
        SPELL_BOW,
    };
    
    Type left();
    Type right();
    
    void move_left();
    void move_right();

    void push_spell(Type type);
    void remove_spell(Type type);
    
private:
    std::vector<Type> _types;
    unsigned int _position;
};

#endif /* Spells_hpp */
