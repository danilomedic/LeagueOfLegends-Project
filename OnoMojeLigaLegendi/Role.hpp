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
        "SUPP", "ADC", "MID", "JUNGLE", "TOP"
    };
    DinString lane;
public:
    Role() {}
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
    ~Role() {}
    void swapLane()
    {
        int l;
        for(int i = 0; i != 5; ++i)
        {
            if(lane == Lane[i])
                l = i;
        }
        int opcija;
        do
        {
            cout << "Da li zelite da idete gore ili dole?" << endl;
            cout << "1 - Gore" << endl;
            cout << "2 - Dole" << endl;
            cin >> opcija;
            if(opcija < 1 || opcija > 2)
                cout << "Nepostojeca opcija" << endl;
        }
        while(opcija < 1 || opcija > 2);
        if(opcija == 1)
        {
            if(l == 4)
            {
                cout << "Na topu si, gde ces gore jarane?" << endl;
                return;
            }
            cout << "Vas trenutni lane je " << lane << ", pomerate se na " << Lane[l + 1] << endl;
            lane = Lane[l + 1];
        }
        if(opcija == 2)
        {
            if(l == 1)
            {
                cout << "Na supp si, gde ces dole jarane?" << endl;
                return;
            }
            cout << "Vas trenutni lane je " << lane << ", pomerate se na " << Lane[l - 1] << endl;
            lane = Lane[l - 1];
        }
    }
    ///----------------- GET:
    DinString getPlaystyle()const
    {
        return playstyle;
    }
    DinString getLane()const
    {
        return lane;
    }
    ///----------------- SET:
    void getPlaystyle(const DinString d)
    {
        playstyle = d;
    }
    void getLane(const DinString d)
    {
        lane = d;
    }
};

#endif // ROLE_HPP_INCLUDED
