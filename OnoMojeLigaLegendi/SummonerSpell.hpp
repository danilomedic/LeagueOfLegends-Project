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
    SummonerSpell(){}
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
    ~SummonerSpell(){}
    void swapBiding()
    {
        if(key == 'D')
            key = 'F';
        if(key == 'F')
            key = 'D';
    }
};


#endif // SUMMONERSPELL_HPP_INCLUDED
