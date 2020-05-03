#ifndef MAP_DEF
#define MAP_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

class Map
{
private:
s    DinString name;
    int numPlayers;
    List<DinString> lanes;
public:
    Map(){}
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
    ~Map(){}
};

#endif
