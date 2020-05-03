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
    bool swapLane();
};

#endif // ROLE_HPP_INCLUDED
