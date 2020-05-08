#ifndef MATCH_HPP_INCLUDED
#define MATCH_HPP_INCLUDED
#include "Map.hpp"
#include "Player.hpp"
#include "list.hpp"

class Match()
{
private:
    Map mapa;
    List<Player> redTeam;
    List<Player> blueTeam;
public:
    Match(){}
    Match(Map m, List<Player> r, List<Player> b) : mapa(m), redTeam(r), blueTeam(b) {}
    Match(const Match &m) : mapa(m.mapa), redTeam(m.redTeam), blueTeam(m.blueTeam) {}
    ~Match(){}
    void kill(const Player killer, const Player dier, const Player assistant)
    {
        killer.setKills(killer.getKills() + 1);
        dier.setDeaths(dier.getDeaths() + 1);
        assistant.setAssists(assistant.getAssists() + 1);
    }
};

#endif // MATCH_HPP_INCLUDED
