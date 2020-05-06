#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED
#include "Map.hpp"
#include "dinstring.hpp"

enum ItemType
{
    VISION, CONSUMABLE, MOVEMENT, MANA,
    MANA_REGEN, AP, CDR, MAGIC_PEN, DMG, CRIT,
    AS, LS, ARMOR_PEN, HEALTH, HEALTH_REGEN, MR, ARMOR
};

class Item
{
private:
    Map gamemode;
    DinString name;
    ItemType type;
    bool active;
    int price;
public:
    Item() {}
    Item(Map m, DinString n, ItemType t, bool a, int p) : gamemode(m)
    {
        name = n;
        type = t;
        active = a;
        price = p;
    }
    Item(const Item &i) : gamemode(i.gamemode)
    {
        name = i.name;
        type = i.type;
        active = i.active;
        price = i.price;
    }
    ~Item() {}
    ///----------------- GET:
    DinString getName()const
    {
        return name;
    }
    int getType()const
    {
        return type;
    }
    bool getActive()const
    {
        return active;
    }
    int getPrice()const
    {
        return price;
    }
    ///----------------- SET:
    void setName(const DinString n)
    {
        name = n;
    }
    void setType(const ItemType a)
    {
        type = a;
    }
    void setActive(const bool a)
    {
        active = a;
    }
    void setPrice(const int a)
    {
        price = a;
    }
};


#endif // ITEM_HPP_INCLUDED
