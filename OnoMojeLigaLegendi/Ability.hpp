#ifndef ABILITY_HPP_INCLUDED
#define ABILITY_HPP_INCLUDED
#include "dinstring.hpp"

enum AbilityType {PASSIVE, DAMAGE, HEAL, CC, MODE_SWAP, SHIELD, DASH, ITEM_ABILITY};

class Ability
{
private:
    DinString name;
    float cooldown;
    int manaCost;
    char key; ///(Q, W, E, R ili P za passive)
    AbilityType type;
public:
    Ability() {}
    Ability(DinString n, float cd, int mc, char k, AbilityType t)
    {
        if(k != 'Q' && k != 'W'  && k != 'E'  && k != 'R' &&  k != 'P')
            return;
        name = n;
        cooldown = cd;
        manaCost = mc;
        key = k;
        type = t;
    }
    Ability(const Ability &a)
    {
        name = a.name;
        cooldown = a.cooldown;
        manaCost = a.manaCost;
        key = a.key;
        type = a.type;
    }
    ~Ability() {}
    ///----------------- GET:
    DinString getName() const
    {
        return name;
    }
    float getCooldown() const
    {
        return cooldown;
    }
    int getManaCost() const
    {
        return manaCost;
    }
    char getKey() const
    {
        return key;
    }
    int getType() const
    {
        return type;
    }
    ///----------------- SET:
    void setName(const DinString n)
    {
        name = n;
    }
    void setCooldown(const float a)
    {
        cooldown = a;
    }
    void setManaCost(const int a)
    {
        manaCost = a;
    }
    void setKey(const char k)
    {
        key = k;
    }
    void setType(const AbilityType a)
    {
        type = a;
    }
    friend ostream& operator << (ostream &out, Ability &a)
    {
        out << "******************************************************" << endl;
        out << "ABILITY" << endl;
        out << "Name: " << a.getName() << " (" << a.getKey() << ")" << endl;
        out << "Cooldown: " << a.getCooldown() << " ManaCost: " << a.getManaCost() << endl;
        switch(a.getType())
        {
            case 0: cout << "Tip: PASSIVE" << endl; break;
            case 1: cout << "Tip: DAMAGE" << endl; break;
            case 2: cout << "Tip: HEAL" << endl; break;
            case 3: cout << "Tip: CC" << endl; break;
            case 4: cout << "Tip: MODE_SWAP" << endl; break;
            case 5: cout << "Tip: SHIELD" << endl; break;
            case 6: cout << "Tip: DASH" << endl; break;
        }
        return out;
    }
};

#endif // ABILITY_HPP_INCLUDED
