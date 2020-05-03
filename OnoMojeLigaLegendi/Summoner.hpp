#ifndef SUMMONER_HPP_INCLUDED
#define SUMMONER_HPP_INCLUDED
#include "dinstring.hpp"
#include "list.hpp"
#include "Role.hpp"
#include "Mastery.hpp"
#include "Runes.hpp"
#include "LoginInfo.hpp"
#include "Club.hpp"
#include "Ranked.hpp"
#include "Friend.hpp"
#include "Currencies.hpp"
#include "Crafting.hpp"

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

#endif // SUMMONER_HPP_INCLUDED
