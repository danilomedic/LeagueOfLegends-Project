#ifndef ABILIY_DEF
#define ABILITY_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

enum AbilityType   {PASSIVE, DAMAGE, HEAL, CC, MODE_SWAP, SHIELD, DASH};

class Ability
{
private:
    DinString name;
    int cooldown, manaCost;
    char key; ///(Q, W, E, R ili P za passive)
    AbilityType type;
};

#endif // ABILIY_DEF
