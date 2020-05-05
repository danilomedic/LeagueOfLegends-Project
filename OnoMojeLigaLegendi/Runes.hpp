#ifndef RUNES_HPP_INCLUDED
#define RUNES_HPP_INCLUDED
#include "dinstring.hpp"

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
    Primary() {}
    Primary(RuneType t, int f[3], DinString r)
    {
        type = t;
        for(int i = 0; i != 3; ++i)
            fields[i] = f[i];
        rune = r;
    }
    Primary(const Primary &p)
    {
        type = p.type;
        for(int i = 0; i != 3; ++i)
            fields[i] = p.fields[i];
        rune = p.rune;
    }
    ~Primary() {}
};

class Secondary
{
private:
    RuneType type;
    int fields[2];
public:
    Secondary() {}
    Secondary(RuneType t, int f[2])
    {
        type = t;
        for(int i = 0; i != 2; ++i)
            fields[i] = f[i];
    }
    Secondary(const Secondary &s)
    {
        type = s.type;
        for(int i = 0; i != 2; ++i)
            fields[i] = s.fields[i];
    }
    ~Secondary() {}
};

class RunePage
{
private:
    Primary rightSide;
    Secondary leftSide;
public:
    RunePage(){}
    RunePage(RuneType t, RuneType tt, int f[3], int ff[2], DinString r) : rightSide(t, f, r), leftSide(tt, ff) {}
    RunePage(const RunePage &rp) : rightSide(rp.rightSide), leftSide(rp.leftSide) {}
    ~RunePage() {}
};

#endif // RUNES_HPP_INCLUDED
