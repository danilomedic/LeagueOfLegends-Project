#ifndef CHAMPIONSTATS_HPP_INCLUDED
#define CHAMPIONSTATS_HPP_INCLUDED

class ChampionStats
{
protected:
    int movementSpeed;
    int armor, magicResist;
    int AP, AD;
    int health, mana;
    int cooldownReduction, critChance;
    float attackSpeed;
public:
    ChampionStats(){}
    ChampionStats(int ms, int arm, int mr, int ap, int ad, int hp, int m, int cdr, int cch, float as)
    {
        movementSpeed = ms;
        armor = arm;
        magicResist = mr;
        AP = ap;
        AD = ad;
        health = hp;
        mana = m;
        cooldownReduction = cdr;
        critChance = cch;
        attackSpeed = as;
    }
    ChampionStats(ChampionStats &cs)
    {
        movementSpeed = cs.movementSpeed;
        armor = cs.armor;
        magicResist = cs.magicResist;
        AP = cs.AP;
        AD = cs.AD;
        health = cs.health;
        mana = cs.mana;
        cooldownReduction = cs.cooldownReduction;
        critChance = cs.critChance;
        attackSpeed = cs.attackSpeed;
    }
    ~ChampionStats(){}
};

#endif // CHAMPIONSTATS_HPP_INCLUDED
