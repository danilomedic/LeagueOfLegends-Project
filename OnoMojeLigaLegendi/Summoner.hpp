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
    Summoner(DinString ausername, DinString apassword, DinString alanguage, Server aserver, DinString sN, int lvl, int ch, int hon, Role mPR, Currencies m, Crafting c, Ranked f, Ranked s, List<Club> &cc, List<Mastery> &mm, List<Friend> &fL, List<RunePage> &rp) : mostPlayedRole(mPR), money(m), materials(c), flex(f), soloduo(s)
    {
        username = ausername;
        password = apassword;
        language = alanguage;
        server = aserver;
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
        username = s.username;
        password = s.password;
        language = s.language;
        server = s.server;
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
    void operator~ ()
    {
        ~Summoner();
    }
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
    void flame()
    {
        if(honorLevel > 0)
            honorLevel--;
        else
        {
            cout << "RIOT GAMES: Sorry, but due to your inappropriate behaviour we have to ban your account!" << endl;
            ~Summoner();
        }
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
    ///----------------- GET:
    DinString getSummName()const
    {
        return summName;
    }
    int getSummLevel()const
    {
        return summLevel;
    }
    int getOwnedChamps()const
    {
        return ownedChamps;
    }
    int getHonorLevel()const
    {
        return honorLevel;
    }
    List<Club> getClubs()const
    {
        return clubs;
    }
    List<Mastery> getFavChamps()const
    {
        return favChamps;
    }
    List<Friend> getFriendList()const
    {
        return friendList;
    }
    List<RunePage> getRunes()const
    {
        return runes;
    }
    ///----------------- SET:
    void setSummName(const DinString a)
    {
        summName = a;
    }
    void setSummLevel(const int a)
    {
        summLevel = a;
    }
    void setOwnedChamps(const int a)
    {
        ownedChamps = a;
    }
    void setHonorLevel(const int a)
    {
        honorLevel = a;
    }
    void setClubs(const List<Club> a)
    {
        clubs = a;
    }
    void setFavChamps(const List<Mastery> a)
    {
        favChamps = a;
    }
    void setFriendList(const List<Friend> a)
    {
        friendList = a;
    }
    void setRunes(const List<RunePage> a)
    {
        runes = a;
    }
    ///----------------- ADD:
    bool addClub(const Club &c)
    {
        if(clubs.size() < 3)
            return clubs.add(clubs.size() + 1, c);
        else
            return false;
    }
    bool addFriend(const Friend &f)
    {
        if(friendList.size() < 3)
            return friendList.add(friendList.size() + 1, f);
        else
            return false;
    }
    bool addFavouriteChampion(const Mastery &m)
    {
        if(favChamps.size() < 3)
            return favChamps.add(favChamps.size() + 1, m);
        else
            return false;
    }
    bool addRunePage(const RunePage &r)
    {
        if(runes.size() < 3)
            return runes.add(runes.size() + 1, r);
        else
            return false;
    }
    ///----------------- LIST:
    void listClubs()
    {
        if(clubs.size() == 0)
            cout << "Niste clan ni jednog kluba!" << endl;
        else
        {
            Club c;
            for(int i = 1; i <= clubs.size(); ++i)
            {
                clubs.read(i, c);
                cout << c;
            }
        }
    }
    void listFriendList()
    {
        if(friendList.size() == 0)
            cout << "Nemate ni jednog prijatelja!" << endl;
        else
        {
            Friend f;
            for(int i = 1; i <= friendList.size(); ++i)
            {
                friendList.read(i, f);
                cout << f;
            }
        }
    }
    void listFavouriteChampions()
    {
        if(favChamps.size() == 0)
            cout << "Nemate ni jednog najigranijeg championa!" << endl;
        else
        {
            Mastery m;
            for(int i = 1; i <= favChamps.size(); ++i)
            {
                favChamps.read(i, m);
                cout << m;
            }
        }
    }
    void listRunePages()
    {
        if(runes.size() == 0)
            cout << "Nemate ni jedan rune page!" << endl;
        else
        {
            RunePage r;
            for(int i = 1; i <= runes.size(); ++i)
            {
                runes.read(i, r);
                cout << r;
            }
        }
    }
    friend ostream& operator << (ostream &out, Summoner &s)
    {
        out << "******************************************************" << endl;
        out << "SUMMONER PROFILE" << endl;
        out << "Summoner Name: " << s.getSummName() << " (level " << s.getSummLevel() << ")" << endl;
        out << "Honor level: " << s.getHonorLevel() <<  endl;
        out << "Owned champions: " << s.getOwnedChamps() <<  endl;
        out << "******************************************************" << endl;
        out << "FAV ROLE" << endl;
        out << "Fav. lane: " << s.mostPlayedRole.getLane() << " Fav. playstyle: " << s.mostPlayedRole.getPlaystyle() << endl;
        out << "******************************************************" << endl;
        out << "CURRENCIES" << endl;
        out << "BE: " << s.money.getBE() << " RP: " << s.money.getRP() << endl;
        out << "******************************************************" << endl;
        out << "LOOT" << endl;
        out << "Box: " << s.materials.getBox() << " Key: " << s.materials.getKey() << " KeyFragments: " << s.materials.getKeyFrag() << " OrangeEssence: " << s.materials.getOrangeEssence() << endl;
        out << "******************************************************" << endl;
        out << "RANKED" << endl;
        out << "SoloDuo: ";
        switch(s.soloduo.getShield())
        {
            case 0: out << "Iron "; break;
            case 1: out << "Bronze "; break;
            case 2: out << "Silver "; break;
            case 3: out << "Gold "; break;
            case 4: out << "Platinum "; break;
            case 5: out << "Diamond "; break;
            case 6: out << "Master "; break;
            case 7: out << "Grandmaster "; break;
            case 8: out << "Challenger "; break;
        }
        out << s.soloduo.getDivisionNum() << " Flex: ";
        switch(s.flex.getShield())
        {
            case 0: out << "Iron "; break;
            case 1: out << "Bronze "; break;
            case 2: out << "Silver "; break;
            case 3: out << "Gold "; break;
            case 4: out << "Platinum "; break;
            case 5: out << "Diamond "; break;
            case 6: out << "Master "; break;
            case 7: out << "Grandmaster "; break;
            case 8: out << "Challenger "; break;
        }
        out << s.flex.getDivisionNum() << endl;
        s.listClubs();
        s.listFriendList();
        s.listFavouriteChampions();
        s.listRunePages();
        return out;
    }
    Summoner& operator= (Summoner& s)
    {
        summName = s.summName;
        summLevel = s.summLevel;
        ownedChamps = s.ownedChamps;
        honorLevel = s.honorLevel;
        mostPlayedRole = s.mostPlayedRole;
        money = s.money;
        materials = s.materials;
        flex = s.flex;
        soloduo = s.soloduo;
        clubs = s.clubs;
        favChamps = s.favChamps;
        friendList = s.friendList;
        runes = s.runes;
        return *this;
    }
    friend bool operator== (Summoner& s1, Summoner &s2)
    {
        if(
           s1.getUsername() != s2.getUsername() ||
           s1.getPassword() != s2.getPassword() ||
           s1.getSummName() != s2.getSummName() ||
           s1.getSummLevel() != s2.getSummLevel() ||
           s1.getOwnedChamps() != s2.getOwnedChamps() ||
           s1.getHonorLevel() != s2.getHonorLevel() ||
           s1.money.getBE() != s2.money.getBE() ||
           s1.money.getRP() != s2.money.getRP() ||
           s1.mostPlayedRole.getLane() != s2.mostPlayedRole.getLane() ||
           s1.mostPlayedRole.getPlaystyle() != s2.mostPlayedRole.getPlaystyle() ||
           s1.flex.getShield() != s2.flex.getShield() ||
           s1.flex.getDivisionNum() != s2.flex.getDivisionNum() ||
           s1.soloduo.getShield() != s2.soloduo.getShield() ||
           s1.soloduo.getDivisionNum() != s2.soloduo.getDivisionNum()
           )
            return false;
        else
            return true;
    }
    friend bool operator!= (Summoner& s1, Summoner &s2)
    {
        if(s1 == s2)
            return false;
        else
            return true;
    }
    friend bool operator> (Summoner& s1, Summoner &s2)
    {
        if(s1.getSummLevel() > s2.getSummLevel())
            return true;
        else
            return false;
    }
    friend bool operator< (Summoner& s1, Summoner &s2)
    {
        if(s1.getSummLevel() < s2.getSummLevel())
            return true;
        else
            return false;
    }
};

#endif // SUMMONER_HPP_INCLUDED
