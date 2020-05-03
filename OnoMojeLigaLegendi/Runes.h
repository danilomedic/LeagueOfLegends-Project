#ifndef RUNES_DEF
#define RUNES_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

enum RuneType
{
    SORCERY, DOMINATION, INSPIRATION, RESOLVE, PRECISION
};

class Primary
{
private:
    RuneType type;
    int fields[3];
    DinString rune;
public:
    Primary(RuneType t, int f[3], DinString r)
    {
        type = t;
        for(int i = 0; i !=3; ++i)
            fields[i] = f[i];
        rune = r;
    }
    ~Primary(){}
};

class Secondary
{
private:
    RuneType type;
    int fields[2];
public:
    Secondary(RuneType t, int f[2])
    {
        type = t;
        for(int i = 0; i !=2; ++i)
            fields[i] = f[i];
    }
    ~Secondary(){}
};

class RunePage
{
private:
    Primary rightSide;
    Secondary leftSide;
public:
    RunePage(RuneType t, RuneType tt, int f[3], int ff[2], DinString r) : rightSide(t, f, r), leftSide(tt, ff){}
    ~RunePage(){}
};

#endif
