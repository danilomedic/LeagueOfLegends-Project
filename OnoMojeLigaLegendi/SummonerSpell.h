#ifndef SUMMONERSPELL_DEF
#define SUMMONERSPELL_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

class SummonerSpell
{
private:
    DinString name;
    char key; /// (D ili F)
    int cooldown;
};


#endif // SUMMONERSPELL_DEF
