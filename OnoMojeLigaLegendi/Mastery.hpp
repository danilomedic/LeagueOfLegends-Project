#ifndef MASTERY_HPP_INCLUDED
#define MASTERY_HPP_INCLUDED
#include "list.hpp"
#include "Champion.hpp"
#include "GameStats.hpp"

class Mastery
{
private:
    Champion champ;
    int level; ///(1 - 7)
    int points;
    float winrate;
    GameStats avgStats;
    List<GameStats> stats;
public:
    bool upgradeLevel();
    bool playGame(); /// +1 na listu, novi prosek, +1000 poena if win
};

#endif // MASTERY_HPP_INCLUDED
