#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include "Friend.hpp"
#include "Champion.hpp"
#include "SummonerSpell.hpp"
#include "Runes.hpp"

class Player
{
private:
    Friend summoner;
    Champion champ;
    SummonerSpell F;
    SummonerSpell D;
    Role role;
    RunePage rune;
    int kills;
    int deaths;
    int assists;
public:
    Player()
    {
        kills = 0;
        deaths = 0;
        assists = 0;
    }
    Player(Friend f, Champion c, SummonerSpell f, SummonerSpell d, RunePage r, Role rr) : summoner(f), champ(c), F(f), D(d), rune(r), role(rr)
    {
        kills = 0;
        deaths = 0;
        assists = 0;
    }
    Player(const Player p&) : summoner(p.summoner), champ(p.champ), F(p.F), D(p.D), rune(p.rune), role (p.role)
    {
        kills = 0;
        deaths = 0;
        assists = 0;
    }
    ~Player(){}
    ///----------------- GET:
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
    ///----------------- SET:
    void setKills(const int k)
    {
        kills = k;
    }
    void setDeaths(const int d)
    {
        deaths = d;
    }
    void setAssists(const int a)
    {
        assists = a
    }
};
#endif // PLAYER_HPP_INCLUDED
