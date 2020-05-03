#ifndef CRAFTING_DEF
#define CRAFTING_DEF
#include <iostream>
using namespace std;

class Crafting
{
private:
    int box, key, keyFrag, orangeEssence;
public:
    bool buySkin();
    bool openBox();
    bool forgeKey();
};

#endif
