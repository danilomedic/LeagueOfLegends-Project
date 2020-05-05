#ifndef RANKED_HPP_INCLUDED
#define RANKED_HPP_INCLUDED
#include "dinstring.hpp"
#include "PromoteDemoteSystem.hpp"

enum Division{IRON, BRONZE, SILVER, GOLD, PLATINUM, DIAMOND, MASTER, GRANDMASTER, CHALLENGER};

class Ranked : public PromoteDemoteSystem
{
private:
    Division shield;
    int divisionNum;
    int LP;
    int MMR;
public:
    Ranked(){}
    Ranked(Division s, int divN, int lp, int mmr)
    {
        shield = s;
        divisionNum = divN;
        LP = lp;
        MMR = mmr;
    }
    Ranked(const Ranked &r)
    {
        shield = r.shield;
        divisionNum = r.divisionNum;
        LP = r.LP;
        MMR = r.MMR;
    }
    ~Ranked(){}
    void promote()
    {
        if(divisionNum == 1)
        {
            int shieldCon = (int)shield;
            shieldCon++;
            shield = (Division)shieldCon;
            divisionNum = 4;
        }
        else
            divisionNum--;
    }
    void demote()
    {
        if(divisionNum == 4)
        {
            int shieldCon = (int)shield;
            shieldCon--;
            shield = (Division)shieldCon;
            divisionNum = 1;
        }
        else
            divisionNum++;
    }
};

#endif // RANKED_HPP_INCLUDED
