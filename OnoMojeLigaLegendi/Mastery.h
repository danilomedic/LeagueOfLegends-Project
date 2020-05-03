#ifndef MASTERY_DEF
#define MASTERY_DEF
#include <iostream>
#include "list.hpp"
#include "Champion.h"
#include "GameStats.h"
using namespace std;

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

#endif
