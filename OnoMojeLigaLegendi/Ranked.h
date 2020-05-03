#ifndef RANKED_DEF
#define RANKED_DEF
#include <iostream>
#include "dinstring.hpp"
#include "PromoteDemoteSystem.h"
using namespace std;

enum Division{IRON, BRONZE, SILVER, GOLD, PLATINUM, DIAMOND, MASTER, GRANDMASTER, CHALLENGER};

class Ranked : public PromoteDemoteSystem
{
private:
    Division shield;
    int divisionNum, LP, mmr;
public:
    bool promote();
    bool demote();
};

#endif
