#ifndef CHAMPION_DEF
#define CHAMPION_DEF
#include "dinstring.hpp"
#include "list.hpp"
#include "ChampionStats.h"
#include "Ability.h"
#include "Skin.h"
#include "Role.h"
using namespace std;

class Champion : public ChampionStats
{
private:
    const DinString Runetera[11]
    {
        "PILTOVER", "DEMACIA", "NOXUS", "IONIA", "FRELJORD", "TARGON",
        "SHURIMA", "IXTAL", "ZAUN", "BILGEWATER", "SHADOW_ISLES"
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

#endif
