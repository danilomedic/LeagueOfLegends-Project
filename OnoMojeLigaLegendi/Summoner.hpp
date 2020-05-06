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
    List<Club> clubs;
    List<Mastery> favChamps;
    List<Friend> friendList;
    List<RunePage> runes;
public:
    Summoner() {}
    Summoner(DinString sN, int lvl, int ch, int hon, Role mPR, Currencies m, Crafting c, Ranked f, Ranked s, List<Club> &cc, List<Mastery> &mm, List<Friend> &fL, List<RunePage> &rp) : mostPlayedRole(mPR), money(m), materials(c), flex(f), soloduo(s)
    {
        summName = sN;
        summLevel = lvl;
        ownedChamps = ch;
        honorLevel = hon;
        clubs = cc;
        favChamps = mm;
        friendList = fL;
        runes = rp;
    }
    Summoner(const Summoner &s) : mostPlayedRole(s.mostPlayedRole), money(s.money), materials(s.materials), flex(s.flex), soloduo(s.soloduo)
    {
        summName = s.summName;
        summLevel = s.summLevel;
        ownedChamps = s.ownedChamps;
        honorLevel = s.honorLevel;
        clubs = s.clubs;
        favChamps = s.favChamps;
        friendList = s.friendList;
        runes = s.runes;
    }
    ~Summoner() {}
    void levelUp()
    {
        summLevel++;
    }
    void beHonored()
    {
        if(honorLevel < 5)
            honorLevel++;
        else
            cout << "Vec si zlatno dete!" << endl;
    }
    void flame() /// DODATI BAN U else!!!!!!!
    {
        if(honorLevel > 0)
            honorLevel--;
        else
        {
            cout << "RIOT GAMES: Sorry, but due to your inappropriate behaviour we have to ban your account!" << endl;
            ~Summoner();
        }
    }
    void joinCLub(const Club &club)
    {
        if(clubs.size() < 3)
            clubs.add(clubs.size() + 1, club);
        else
            cout << "Vec si clan 3 kluba" << endl;
    }
    void addFriend(const Friend &f)
    {
        friendList.add(friendList.size() + 1, f);
    }
    void buyRunePage(const RunePage &r)
    {
        runes.add(runes.size() + 1, r);
    }
    void leaveCLub(int koji)
    {
        if(clubs.size() > 0)
            clubs.remove(koji);
        else
            cout << "Nisi clan ni jednog kluba!" << endl;
    }
    void deleteFriend(int koji)
    {
        friendList.remove(koji);
    }
    void buyChampion(int price)
    {
        if(money.spend(price))
            ownedChamps++;
    }
    void operator~ ()
    {
        ~Summoner();
    }
};

#endif // SUMMONER_HPP_INCLUDED
