#ifndef CHAMPIONSTATS_DEF
#define CHAMPIONSTATS_DEF
#include <iostream>
using namespace std;

class ChampionStats
{
protected:
    int movementSpeed;
    int armror, magicResist;
    int AP, AD;
    int health, mana;
    int cooldownReduction = 0, critChance = 0;
    float attackSpeed;
};

#endif
