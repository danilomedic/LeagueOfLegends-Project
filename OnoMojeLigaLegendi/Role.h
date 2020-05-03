#ifndef ROLE_DEF
#define ROLE_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

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

#endif
