#ifndef ABILITY_HPP_INCLUDED
#define ABILITY_HPP_INCLUDED
#include "dinstring.hpp"

enum AbilityType{PASSIVE, DAMAGE, HEAL, CC, MODE_SWAP, SHIELD, DASH};

class Ability
{
private:
    DinString name;
    int cooldown, manaCost;
    char key; ///(Q, W, E, R ili P za passive)
    AbilityType type;
public:
    Ability(){}
    Ability(DinString n, int cd, int mc, char k, AbilityType t)
    {
        if(k != 'Q' && k != 'W'  && k != 'E'  && k != 'R' &&  k != 'P')
            return;
        name = n;
        cooldown = cd;
        manaCost = mc;
        key = k;
        type = t;
    }
    Ability(Ability &a)
    {
        name = a.name;
        cooldown = a.cooldown;
        manaCost = a.manaCost;
        key = a.key;
        type = a.type;
    }
    ~Ability(){}
};

#endif // ABILITY_HPP_INCLUDED
