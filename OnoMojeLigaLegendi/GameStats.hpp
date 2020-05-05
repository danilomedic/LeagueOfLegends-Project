#ifndef GAMESTATS_HPP_INCLUDED
#define GAMESTATS_HPP_INCLUDED

class GameStats
{
private:
    bool win;
    int kda[3];
    float csPerMin;
    int gold;
public:
    GameStats(){}
    GameStats(bool w, int k, int d, int a, float cs, int g)
    {
        win = w;
        kda[0] = k;
        kda[1] = d;
        kda[2] = a;
        csPerMin = cs;
        gold = g;
    }
    GameStats(const GameStats &gs)
    {
        win = gs.win;
        kda[0] = gs.kda[0];
        kda[1] = gs.kda[1];
        kda[2] = gs.kda[2];
        csPerMin = gs.csPerMin;
        gold = gs.gold;
    }
    ~GameStats(){}
};

#endif // GAMESTATS_HPP_INCLUDED
