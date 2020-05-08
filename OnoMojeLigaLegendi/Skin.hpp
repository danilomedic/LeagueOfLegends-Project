#ifndef SKIN_HPP_INCLUDED
#define SKIN_HPP_INCLUDED
#include "dinstring.hpp"

DinString SkinRarity[6]
    {
        "COMMON", "RARE", "EPIC", "LEGENDARY", "ULTIMATE", "MYTHIC"
    };

class Skin
{
private:
    DinString name;
    int price;
    DinString skinRarity;
    bool legacy;
public:
    Skin() {}
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
    ~Skin() {}
    ///----------------- GET:
    DinString getName()const
    {
        return name;
    }
    int getPrice()const
    {
        return price;
    }
    DinString getSkinRarity()const
    {
        return skinRarity;
    }
    bool getLegacy()const
    {
        return legacy;
    }
    ///----------------- SET:
    void setName(const DinString a)
    {
        name = a;
    }
    void setPrice(const int a)
    {
        price = a;
    }
    void setSkinRarity(const DinString a)
    {
        skinRarity = a;
    }
    void setLegacy(const bool a)
    {
        legacy = a;
    }

    friend ostream& operator << (ostream &out, Skin &s)
    {
        out << "******************************************************" << endl;
        out << "SKIN" << endl;
        out << "Name: " << s.getName() << " (" << s.getPrice() << ")" << endl;
        if(s.getLegacy())
            out << "It is a legacy " << s.getSkinRarity() << " skin." << endl;
        else
            out << "It isn't a legacy " << s.getSkinRarity() << " skin." << endl;
        return out;
    }
};

#endif // SKIN_HPP_INCLUDED
