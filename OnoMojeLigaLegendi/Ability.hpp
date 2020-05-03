#ifndef ABILITY_HPP_INCLUDED
#define ABILITY_HPP_INCLUDED
#include "dinstring.hpp"

enum AbilityType   {PASSIVE, DAMAGE, HEAL, CC, MODE_SWAP, SHIELD, DASH};

class Ability
{
private:
    DinString name;
    int cooldown, manaCost;
    char key; ///(Q, W, E, R ili P za passive)
    AbilityType type;
};

#endif // ABILITY_HPP_INCLUDED
