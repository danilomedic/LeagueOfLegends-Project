#include <iostream>
using namespace std;
enum ItemType      {VISION, CONSUMABLE, MOVEMENT, MANA, MANA_REGEN, AP, CDR, MAGIC_PEN, DMG, CRIT, AS, LS, ARMOR_PEN, HEALTH, HEALTH_REGEN, MR, ARMOR};
enum AbilityType   {PASSIVE, DAMAGE, HEAL, CC, MODE_SWAP, SHIELD, DASH};
enum SkinRarity    {COMMON, RARE, EPIC, LEGENDARY, ULTIMATE, MYTHIC};
enum Runetera      {PILTOVER, DEMACIA, NOXUS, IONIA, FRELJORD, TARGON, SHURIMA, IXTAL, ZAUN, BILGEWATER, SHADOW_ISLES};
enum Lane          {TOP, JUNGLE, MID, ADC, SUPP};
enum Playstyle     {ASSASIN, MAGE, TANK, FIGHTER, SUPPORT, MARKSMAN};
enum PlayFrequency {NEVER, ONCE_MONTH, ONCE_WEEK, ONCE_DAY, PREMADE, RANKED_PREMADE};
enum Division      {IRON, BRONZE, SILVER, GOLD, PLATINUM, DIAMOND, MASTER, GRANDMASTER, CHALLENGER};
enum ClubRank      {MEMBER, OFFICER, OWNER};
enum Server        {EUNE, EUWEST, NA, BRAZIL, TURKEY, LATIN_AMERICA, OCEANIA, RUSSIA, JAPAN, KOREA};
enum RuneType      {SORCERY, DOMINATION, INSPIRATION, RESOLVE, PRECISION};

class Map
{
private:
    char * naziv;
    int players;
    int numLanes;
    int numObjectives;
    Lane * lanes;
};

class Item
{
private:
    Map gamemode;
    char * name;
    ItemType type;
    bool active;
    int price;
};

class SummonerSpell
{
private:
    char * name;
    char key; /// (D ili F)
    int cooldown;
};

class Role
{
private:
    Playstyle playstyle;
    Lane lane;
public:
    bool swapLane();
};

class Primary
{
private:
    RuneType type;
    int Fields[3];
    char * runa;
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
    char * name;
    int cooldown, manaCost;
    char key; ///(Q, W, E, R ili P za passive)
    AbilityType type;
};

class Skin
{
private:
    char * name;
    int price;
    SkinRarity rarity;
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
    char * name;
    int cenaBE, cenaRP; ///odredjene vrednosti
    Runetera origin;
    Role role;
    Ability abilities[5];
    Skin * skins;
public:
    bool dodajSkin();
    bool buff();
    bool nerf();
};

class GameStats
{
private:
    bool win;
    float kda;
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
    GameStats * stats;
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
    char * summName;
    PlayFrequency freq;
    bool sameClub;
public:
    bool playMoreOften();
};

class PromoteDemoteSystem
{
public:
    virtual bool promote();
    virtual bool demote();
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
    char * name;
    char tag[5];
    int numMembers;
    ClubRank role;
public:
    bool promote();
    bool demote();
};

class LoginInfo
{
protected:
    char * username;
    char * password;
    char * language;
    Server server;
public:
    bool passwordStrength;
};

class Summoner : public LoginInfo
{
private:
    char * summName;
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
