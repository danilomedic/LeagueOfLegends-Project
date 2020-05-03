#ifndef SUMMONER_DEF
#define SUMMONER_DEF
#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include "Role.h"
#include "Mastery.h"
#include "Runes.h"
#include "LoginInfo.h"
#include "Club.h"
#include "Ranked.h"
#include "Friend.h"
#include "Currencies.h"
#include "Crafting.h"
using namespace std;

class Summoner : public LoginInfo
{
private:
    DinString summName;
    int summLevel;
    int ownedChamps;
    int honorLevel; ///(1 - 5)
    Role mostPlayedRole;
    Currencies money;
    Crafting materials;
    Ranked flex;
    Ranked soloduo;
    Club clubs[3];
    Mastery favChamps[3];
    Friend * friendList;
    RunePage * runePages;
public:
    bool levelUp();
    bool beHonored();///honorLevel++
    bool flame(); ///honorLevel--, ban if 0
    bool addCLub();
    bool addFriend();
    bool addRunePage();
    bool buyChampion();
};

#endif
