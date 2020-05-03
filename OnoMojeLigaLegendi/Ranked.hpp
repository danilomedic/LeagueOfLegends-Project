#ifndef RANKED_HPP_INCLUDED
#define RANKED_HPP_INCLUDED
#include "dinstring.hpp"
#include "PromoteDemoteSystem.hpp"

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

#endif // RANKED_HPP_INCLUDED
