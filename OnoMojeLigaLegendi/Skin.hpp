#ifndef SKIN_HPP_INCLUDED
#define SKIN_HPP_INCLUDED
#include "dinstring.hpp"

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

#endif // SKIN_HPP_INCLUDED
