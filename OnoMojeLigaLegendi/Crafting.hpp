#ifndef CRAFTING_HPP_INCLUDED
#define CRAFTING_HPP_INCLUDED
#include <cmath>

class Crafting
{
private:
    int box, key, keyFrag, orangeEssence, skins;
public:
    Crafting()
    {
        box = 0;
        key = 0;
        keyFrag = 0;
        orangeEssence = 0;
        skins = 0;
    }
    Crafting(int b, int k, int kf, int oE, int s)
    {
        box = b;
        key = k;
        keyFrag = kf;
        orangeEssence = oE;
        skins = s;
    }
    Crafting(const Crafting &c)
    {
        box = c.box;
        key = c.key;
        keyFrag = c.keyFrag;
        orangeEssence = c.orangeEssence;
        skins = c.skins;
    }
    ~Crafting(){}
    void buySkin()
    {
        if(skins == 0)
        {
            cout << "Nemate skinova na stanju!" << endl;
            return;
        }
        int price;
        cout << "Vase stanje: " << orangeEssence << " orange essence" << endl;
        cout << "Koliko kosta skin: ";
        cin >> price;
        if(orangeEssence > price)
            orangeEssence -= price;
        else
            cout << "Nemate dovoljno orange essence!" << endl;
    }
    void openBox()
    {
        if(box == 0)
        {
            cout << "Nemate ni jednu kutiju!" << endl;
            return;
        }
        int option = rand() % 2 + 1;
        int oE = rand() % 1000 + 1;
        if(option == 1)
        {
            orangeEssence += oE;
            cout << "Dobili ste " << oE << "orange essenca i stanje vam je " << orangeEssence << "." << endl;
        }
        if(option == 2)
        {
            skins += 1;
            cout << "Dobili ste 1 skin i sad ih imate " << skins << "." << endl;
        }
        box -= 1;
    }
    void forgeKey()
    {
        if(keyFrag >= 3)
        {
            keyFrag -= 3;
            key += 1;
            cout << "Sad imate " << keyFrag << "fragmenta i " << key << "kljuceva" << endl;
        }
        else
            cout << "Nemate dovoljno fragmenta!" << endl;
    }
};

#endif // CRAFTING_HPP_INCLUDED
