#ifndef CHAMPION_HPP_INCLUDED
#define CHAMPION_HPP_INCLUDED
#include "dinstring.hpp"
#include "list.hpp"
#include "ChampionStats.hpp"
#include "Ability.hpp"
#include "Skin.hpp"
#include "Role.hpp"

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
    int cenaBE, cenaRP;
    Role role;
    List<Ability> abilities;
    List<Skin> skins;
public:
    Champion(){}
    Champion(DinString Name, int CenaBE, int CenaRP, int indexRunetera, Role Role, List<Ability> Abilities, List<Skin> &Skins, int ms, int arm, int mr, int ap, int ad, int hp, int m, int cdr, int cch, float as) : role(Role)
    {
        movementSpeed = ms;
        armor = arm;
        magicResist = mr;
        AP = ap;
        AD = ad;
        health = hp;
        mana = m;
        cooldownReduction = cdr;
        critChance = cch;
        attackSpeed = as;
        name = Name;
        cenaBE = CenaBE;
        cenaRP = CenaRP;
        runetera = Runetera[indexRunetera];
        abilities = Abilities;
        skins = Skins;
    }
    Champion(const Champion &c) : role(c.role)
    {
        movementSpeed = c.movementSpeed;
        armor = c.armor;
        magicResist = c.magicResist;
        AP = c.AP;
        AD = c.AD;
        health = c.health;
        mana = c.mana;
        cooldownReduction = c.cooldownReduction;
        critChance = c.critChance;
        attackSpeed = c.attackSpeed;
        name = c.name;
        cenaBE = c.cenaBE;
        cenaRP = c.cenaRP;
        runetera = c.runetera;
        abilities = c.abilities;
        skins = c.skins;
    }
    ~Champion(){}
    void dodajSkin(Skin &skin)
    {
        skins.add(skins.size() + 1, skin);
    }
    void buff()
    {
        int opcija;
        do
        {
            cout << "Izaberite koji stat zelite da dobije buff: " << endl;
            cout << "1 - Movement speed" << endl;
            cout << "2 - Armor" << endl;
            cout << "3 - Magic Resist" << endl;
            cout << "4 - AP" << endl;
            cout << "5 - AD" << endl;
            cout << "6 - Health " << endl;
            cout << "7 - Mana" << endl;
            cout << "8 - CDR" << endl;
            cout << "9 - Crit Chance" << endl;
            cout << "10 - Attack Speed" << endl;
            cin >> opcija;
            if(opcija < 1 || opcija > 10)
                cout << "Nepostojeca opcija" << endl;
        }
        while(opcija < 1 || opcija > 10);
        int amount;
        switch(opcija)
        {
            case 1:
                cout << "Koliko MS zelite da dodate?" << endl;
                cin >> amount;
                movementSpeed += amount;
                break;
            case 2:
                cout << "Koliko ARM zelite da dodate?" << endl;
                cin >> amount;
                armor += amount;
                break;
            case 3:
                cout << "Koliko MR zelite da dodate?" << endl;
                cin >> amount;
                magicResist += amount;
                break;
            case 4:
                cout << "Koliko AP zelite da dodate?" << endl;
                cin >> amount;
                AP += amount;
                break;
            case 5:
                cout << "Koliko AD zelite da dodate?" << endl;
                cin >> amount;
                AD += amount;
                break;
            case 6:
                cout << "Koliko HP zelite da dodate?" << endl;
                cin >> amount;
                health += amount;
                break;
            case 7:
                cout << "Koliko MANA zelite da dodate?" << endl;
                cin >> amount;
                mana += amount;
                break;
            case 8:
                cout << "Koliko CDR zelite da dodate?" << endl;
                cin >> amount;
                cooldownReduction += amount;
                break;
            case 9:
                cout << "Koliko CRITCHANCE zelite da dodate?" << endl;
                cin >> amount;
                critChance += amount;
                break;
            case 10:
                cout << "Koliko AS zelite da dodate?" << endl;
                cin >> amount;
                attackSpeed += amount;
                break;
        }
    }
    void nerf()
    {
        int opcija;
        do
        {
            cout << "Izaberite koji stat zelite da dobije nerf: " << endl;
            cout << "1 - Movement speed" << endl;
            cout << "2 - Armor" << endl;
            cout << "3 - Magic Resist" << endl;
            cout << "4 - AP" << endl;
            cout << "5 - AD" << endl;
            cout << "6 - Health " << endl;
            cout << "7 - Mana" << endl;
            cout << "8 - CDR" << endl;
            cout << "9 - Crit Chance" << endl;
            cout << "10 - Attack Speed" << endl;
            cin >> opcija;
            if(opcija < 1 || opcija > 10)
                cout << "Nepostojeca opcija" << endl;
        }
        while(opcija < 1 || opcija > 10);
        int amount;
        switch(opcija)
        {
            case 1:
                cout << "Koliko MS zelite da oduzmete?" << endl;
                cin >> amount;
                movementSpeed -= amount;
                break;
            case 2:
                cout << "Koliko ARM zelite da oduzmete?" << endl;
                cin >> amount;
                armor -= amount;
                break;
            case 3:
                cout << "Koliko MR zelite da oduzmete?" << endl;
                cin >> amount;
                magicResist -= amount;
                break;
            case 4:
                cout << "Koliko AP zelite da oduzmete?" << endl;
                cin >> amount;
                AP -= amount;
                break;
            case 5:
                cout << "Koliko AD zelite da oduzmete?" << endl;
                cin >> amount;
                AD -= amount;
                break;
            case 6:
                cout << "Koliko HP zelite da oduzmete?" << endl;
                cin >> amount;
                health -= amount;
                break;
            case 7:
                cout << "Koliko MANA zelite da oduzmete?" << endl;
                cin >> amount;
                mana -= amount;
                break;
            case 8:
                cout << "Koliko CDR zelite da oduzmete?" << endl;
                cin >> amount;
                cooldownReduction -= amount;
                break;
            case 9:
                cout << "Koliko CRITCHANCE zelite da oduzmete?" << endl;
                cin >> amount;
                critChance -= amount;
                break;
            case 10:
                cout << "Koliko AS zelite da oduzmete?" << endl;
                cin >> amount;
                attackSpeed -= amount;
                break;
        }
    }
};

#endif // CHAMPION_HPP_INCLUDED
