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
public:
    Skin(){}
    Skin(DinString n, int p, int index, bool l)
    {
        name = n;
        price = p;
        skinRarity = SkinRarity[index];
        legacy = l;
    }
    Skin(const Skin &s)
    {
        name = s.name;
        price = s.price;
        skinRarity = s.skinRarity;
        legacy = s.legacy;
    }
    ~Skin(){}
};

#endif // SKIN_HPP_INCLUDED
