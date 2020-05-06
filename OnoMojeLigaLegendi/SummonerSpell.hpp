#ifndef SUMMONERSPELL_HPP_INCLUDED
#define SUMMONERSPELL_HPP_INCLUDED
#include "dinstring.hpp"

class SummonerSpell
{
private:
    DinString name;
    char key; /// (D ili F)
    int cooldown;
public:
    SummonerSpell() {}
    SummonerSpell(DinString n, char k, int cd)
    {
        if(k != 'F' && k != 'D')
            return;
        key = k;
        name = n;
        cooldown = cd;
    }
    SummonerSpell(const SummonerSpell &s)
    {
        key = s.key;
        name = s.name;
        cooldown = s.cooldown;
    }
    ~SummonerSpell() {}
    void swapBiding()
    {
        if(key == 'D')
            key = 'F';
        if(key == 'F')
            key = 'D';
    }
    ///----------------- GET:
    DinString getName()const
    {
        return name;
    }
    char getKey()const
    {
        return key;
    }
    int getCooldown()const
    {
        return cooldown;
    }
    ///----------------- SET:
    void setName(const DinString a)
    {
        name = a;
    }
    void setKey(const char a)
    {
        key = a;
    }
    void setCooldown(const int a)
    {
        cooldown = a;
    }
};


#endif // SUMMONERSPELL_HPP_INCLUDED
