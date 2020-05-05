#ifndef ROLE_HPP_INCLUDED
#define ROLE_HPP_INCLUDED
#include "dinstring.hpp"

class Role
{
private:
    DinString Playstyle[6]
    {
        "ASSASIN", "MAGE", "TANK", "FIGHTER", "SUPPORT", "MARKSMAN"
    };
    DinString playstyle;
    DinString Lane[5]
    {
        "TOP", "JUNGLE", "MID", "ADC", "SUPP"
    };
    DinString lane;
public:
    Role(){}
    Role(int indexP, int indexL)
    {
        playstyle = Playstyle[indexP];
        lane = Lane[indexL];
    }
    Role(const Role &r)
    {
        playstyle = r.playstyle;
        lane = r.lane;
    }
    ~Role(){}
    bool swapLane();
};

#endif // ROLE_HPP_INCLUDED
