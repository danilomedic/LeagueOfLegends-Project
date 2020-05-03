#ifndef SKIN_DEF
#define SKIN_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

class Skin
{
private:
    DinString name;
    int price;
    DinString SkinRarity[6]
    {
        "COMMON", "RARE", "EPIC", "LEGENDARY", "ULTIMATE", "MYTHIC"
    };
    DinString skinRarity;
    bool legacy;
};

#endif
