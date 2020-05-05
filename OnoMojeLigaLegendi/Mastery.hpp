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
    Mastery(){}
    Mastery(Champion c, int lvl, int pt, float wr, GameStats avg, List<GameStats> s) : champ(c), avgStats(avg)
    {
        level = lvl;
        points = pt;
        winrate = wr;
        stats = s;
    }
    Mastery(const Mastery &m) : champ(m.champ), avgStats(m.avgStats)
    {
        level = m.level;
        points = m.points;
        winrate = m.winrate;
        stats = m.stats;
    }
    ~Mastery(){}
    bool upgradeLevel();
    bool playGame(); /// +1 na listu, novi prosek, +1000 poena if win
};

#endif // MASTERY_HPP_INCLUDED
