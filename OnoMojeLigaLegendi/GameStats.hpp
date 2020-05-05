#ifndef GAMESTATS_HPP_INCLUDED
#define GAMESTATS_HPP_INCLUDED

class GameStats
{
private:
    bool win;
    int kills, deaths, assists;
    float csPerMin;
    int gold;
public:
    GameStats(){}
    GameStats(bool w, int k, int d, int a, float cs, int g)
    {
        win = w;
        kills = k;
        deaths = d;
        assists = a;
        csPerMin = cs;
        gold = g;
    }
    GameStats(const GameStats &gs)
    {
        win = gs.win;
        kills = gs.kills;
        deaths = gs.deaths;
        assists = gs.assists;
        csPerMin = gs.csPerMin;
        gold = gs.gold;
    }
    ~GameStats(){}
    ///----------------- GET:
    bool getWin() const
    {
        return win;
    }
    int getKills() const
    {
        return kills;
    }
    int getDeaths() const
    {
        return deaths;
    }
    int getAssists() const
    {
        return assists;
    }
    float getCS() const
    {
        return csPerMin;
    }
    int getGold() const
    {
        return gold;
    }
    ///----------------- SET:
    void setKills(const int a)
    {
        kills = a;
    }
    void setDeaths(const int a)
    {
        deaths = a;
    }
    void setAssists(const int a)
    {
        assists = a;
    }
    void setCS(const float a)
    {
        csPerMin = a;
    }
    void setGold(const int a)
    {
        gold = a;
    }
};

#endif // GAMESTATS_HPP_INCLUDED
