#ifndef SUMMONERSPELL_HPP_INCLUDED
#define SUMMONERSPELL_HPP_INCLUDED
#include "dinstring.hpp"

class SummonerSpell
{
private:
    DinString name;
    char key; /// (D ili F)
    int cooldown;
};


#endif // SUMMONERSPELL_HPP_INCLUDED
