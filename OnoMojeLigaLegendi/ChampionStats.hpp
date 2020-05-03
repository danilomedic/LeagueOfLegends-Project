#ifndef CHAMPIONSTATS_HPP_INCLUDED
#define CHAMPIONSTATS_HPP_INCLUDED

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

#endif // CHAMPIONSTATS_HPP_INCLUDED
