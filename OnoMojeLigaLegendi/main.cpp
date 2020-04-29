#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;

enum ItemType      {VISION, CONSUMABLE, MOVEMENT, MANA, MANA_REGEN, AP, CDR, MAGIC_PEN, DMG, CRIT, AS, LS, ARMOR_PEN, HEALTH, HEALTH_REGEN, MR, ARMOR};
enum AbilityType   {PASSIVE, DAMAGE, HEAL, CC, MODE_SWAP, SHIELD, DASH};
enum PlayFrequency {NEVER, ONCE_MONTH, ONCE_WEEK, ONCE_DAY, PREMADE, RANKED_PREMADE};
enum Division      {IRON, BRONZE, SILVER, GOLD, PLATINUM, DIAMOND, MASTER, GRANDMASTER, CHALLENGER};
enum ClubRank      {MEMBER, OFFICER, OWNER};
enum Server        {EUNE, EUWEST, NA, BRAZIL, TURKEY, LATIN_AMERICA, OCEANIA, RUSSIA, JAPAN, KOREA};
enum RuneType      {SORCERY, DOMINATION, INSPIRATION, RESOLVE, PRECISION};

class Map
{
private:
    DinString name;
    int players;
    int numLanes;
    int numObjectives;
    DinString * lanes;
};

class Item
{
private:
    Map gamemode;
    DinString name;
    ItemType type;
    bool active;
    int price;
};

class SummonerSpell
{
private:
    DinString name;
    char key; /// (D ili F)
    int cooldown;
};

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

class Primary
{
private:
    RuneType type;
    int Fields[3];
    DinString runa;
};

class Secondary
{
private:
    RuneType type;
    int Fields[2];
};

class RunePage
{
private:
    Primary rightSide;
    Secondary leftSide;
};

class Ability
{
private:
    DinString name;
    int cooldown, manaCost;
    char key; ///(Q, W, E, R ili P za passive)
    AbilityType type;
};

class Skin
{
private:
    DinString name;
    int price;
    DinString SkinRarity[6]
    {
        "COMMON", "RARE", "EPIC", "LEGENDARY", "ULTIMATE", "MYTHIC"
    };
    DinString skinRarity;
    bool legacy;
};

class ChampionStats
{
protected:
    int movementSpeed;
    int armror, magicResist;
    int AP, AD;
    int health, mana;
    int cooldownReduction = 0, critChance = 0;
    float attackSpeed;
};

class Champion : public ChampionStats
{
private:
    const DinString Runetera[11]
    {
        "PILTOVER", "DEMACIA", "NOXUS", "IONIA", "FRELJORD", "TARGON", "SHURIMA", "IXTAL", "ZAUN", "BILGEWATER", "SHADOW_ISLES"
    };
    DinString runetera;
    DinString name;
    int cenaBE, cenaRP; ///odredjene vrednosti
    Role role;
    Ability * abilities = (Ability*)malloc(sizeof(Ability) * 5);
    List<Skin> skins;
public:
    /// u mainu napraviti niz Abilities, Champion(..., &Abilities)
    Champion(DinString Name, int CenaBE, int CenaRP, int indexRunetera, Role Role, Ability * Abilities, List<Skin> &Skins)
    {
        name = Name;
        cenaBE = CenaBE;
        cenaRP = CenaRP;
        runetera = Runetera[indexRunetera];
        role = Role;
        abilities = Abilities;
        skins = Skins;
    }
    void dodajSkin(Skin &skin)
    {
        skins.add(skins.size() + 1, skin);
    }
    bool buff();
    bool nerf();
};

class GameStats
{
private:
    bool win;
    int kda[3];
    float csPerMin;
    int gold;
};

class Mastery
{
private:
    Champion champ;
    int level; ///(1 - 7)
    int points;
    float winrate;
    GameStats avgstats;
    List<GameStats> stats;
public:
    bool upgradeLevel();
    bool playGame(); /// +1 na listu, novi prosek, +1000 poena if win
};

class Crafting
{
private:
    int box, key, keyFrag, orangeEssence;
public:
    bool buySkin();
    bool openBox();
    bool forgeKey();
};

class Currencies
{
private:
    int RP, BE;
public:
    bool spend();
};

class Friend
{
private:
    DinString summName;
    PlayFrequency freq;
    bool sameClub;
public:
    bool playMoreOften();
};

class PromoteDemoteSystem
{
public:
    virtual bool promote() = 0;
    virtual bool demote() = 0;
};

class Ranked : public PromoteDemoteSystem
{
private:
    Division shield;
    int divisionNum, LP, mmr;
public:
    bool promote();
    bool demote();
};

class Club : public PromoteDemoteSystem
{
private:
    DinString name;
    DinString tag;
    int numMembers;
    ClubRank role;
public:
    bool promote();
    bool demote();
};

class LoginInfo
{
protected:
    DinString username;
    DinString password;
    DinString language;
    Server server;
public:
    bool passwordStrength;
};

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











int main()
{
    return 0;
}
