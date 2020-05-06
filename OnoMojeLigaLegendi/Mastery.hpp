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
    Mastery(Champion c, int lvl, int pt, float wr, GameStats avg, List<GameStats> &s) : champ(c), avgStats(avg)
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
    void avarage()
    {
        int Uwins = 0;
        int Ukills = 0, Udeaths = 0, Uassists= 0;
        float UcsPerMin= 0;
        int Ugold= 0;
        GameStats gs;
        for(int i = 1; i != stats.size(); ++i)
        {
            stats.read(i, gs);
            if(gs.getWin())
            {
                Uwins++;
            }
            Ukills += gs.getKills();
            Udeaths += gs.getDeaths();
            Uassists += gs.getAssists();
            UcsPerMin += gs.getCS();
            Ugold += gs.getGold();
        }
        avgStats.setKills(Ukills / stats.size());
        avgStats.setDeaths(Udeaths / stats.size());
        avgStats.setAssists(Uassists / stats.size());
        avgStats.setCS(UcsPerMin / stats.size());
        avgStats.setGold(Ugold / stats.size());
        winrate = (Uwins * 100) / stats.size();
    }
    void playGame(GameStats &stat)
    {
        stats.add(stats.size() + 1, stat);
        avarage();
    }
    Mastery& operator=(const Mastery& m)
    {
        avgStats = m.avgStats;
        champ = m.champ;
        level = m.level;
        points = m.points;
        winrate = m.winrate;
        stats = m.stats;
        return *this;
    }
};

#endif // MASTERY_HPP_INCLUDED
