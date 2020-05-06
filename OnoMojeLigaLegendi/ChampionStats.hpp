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
    ChampionStats() {}
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
    ChampionStats(const ChampionStats &cs)
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
    ~ChampionStats() {}
    ///----------------- GET:
    int getMS()const
    {
        return movementSpeed;
    }
    int getARM()const
    {
        return armor;
    }
    int getMR()const
    {
        return magicResist;
    }
    int getAP()const
    {
        return AP;
    }
    int getAD()const
    {
        return AD;
    }
    int getHP()const
    {
        return health;
    }
    int getMANA()const
    {
        return mana;
    }
    int getCDR()const
    {
        return cooldownReduction;
    }
    int getCC()const
    {
        return critChance;
    }
    float getAS()const
    {
        return attackSpeed;
    }
    ///----------------- SET:
    void setMS(const int a)
    {
        movementSpeed = a;
    }
    void setARM(const int a)
    {
        armor = a;
    }
    void setMR(const int a)
    {
        magicResist = a;
    }
    void setAP(const int a)
    {
        AP = a;
    }
    void setAD(const int a)
    {
        AD = a;
    }
    void setHP(const int a)
    {
        health = a;
    }
    void setMANA(const int a)
    {
        mana = a;
    }
    void setCDR(const int a)
    {
        cooldownReduction = a;
    }
    void setCC(const int a)
    {
        critChance = a;
    }
    void setAS(const float a)
    {
        attackSpeed = a;
    }
};

#endif // CHAMPIONSTATS_HPP_INCLUDED
