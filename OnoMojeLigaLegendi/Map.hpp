#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
#include "dinstring.hpp"

class Map
{
private:
    DinString name;
    int numPlayers;
    List<DinString> lanes;
public:
    Map() {}
    Map(DinString n, int nP, List<DinString> &l)
    {
        name = n;
        numPlayers = nP;
        lanes = l;
    }
    Map(const Map &m)
    {
        name = m.name;
        numPlayers = m.numPlayers;
        lanes = m.lanes;
    }
    ~Map() {}
    ///----------------- GET:
    DinString getName() const
    {
        return name;
    }
    int getNumPlayers() const
    {
        return numPlayers;
    }
    List<DinString> getLanes() const
    {
        return lanes;
    }
    ///----------------- SET:
    void setName(const DinString n)
    {
        name = n;
    }
    void setNumPlayers(const int n)
    {
        numPlayers = n;
    }
    void setLanes(const List<DinString> l)
    {
        lanes = l;
    }
};

#endif // MAP_HPP_INCLUDED
