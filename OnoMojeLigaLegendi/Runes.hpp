#ifndef RUNES_HPP_INCLUDED
#define RUNES_HPP_INCLUDED
#include "dinstring.hpp"
#define POLJA_1 3
#define POLJA_2 2


enum RuneType
{
    SORCERY, DOMINATION, INSPIRATION, RESOLVE, PRECISION
};

class Primary
{
private:
    RuneType type;
    int field1;
    int field2;
    int field3;
    DinString rune;
public:
    Primary() {}
    Primary(RuneType t, int f1, int f2, int f3, DinString r)
    {
        type = t;
        field1 = f1;
        field2 = f2;
        field3 = f3;
        rune = r;
    }
    Primary(const Primary &p)
    {
        type = p.type;
        field1 = p.field1;
        field2 = p.field2;
        field3 = p.field3;
        rune = p.rune;
    }
    ~Primary() {}
    ///----------------- GET:
    int getType()const
    {
        return type;
    }
    int getField1()const
    {
        return field1;
    }
    int getField2()const
    {
        return field2;
    }
    int getField3()const
    {
        return field3;
    }
    DinString getRune()const
    {
        return rune;
    }
    ///----------------- SET:
    void setType(const RuneType a)
    {
        type = a;
    }
    void setField1(const int a)
    {
        field1 = a;
    }
    void setField2(const int a)
    {
        field2 = a;
    }
    void setField3(const int a)
    {
        field3 = a;
    }
    void setRune(const DinString a)
    {
        rune = a;
    }
};

class Secondary
{
private:
    RuneType type;
    int field1;
    int field2;
public:
    Secondary() {}
    Secondary(RuneType t, int ff1, int ff2)
    {
        type = t;
        field1 = ff1;
        field2 = ff2;
    }
    Secondary(const Secondary &s)
    {
        type = s.type;
        field1 = s.field1;
        field2 = s.field2;
    }
    ~Secondary() {}
    ///----------------- GET:
    int getType()const
    {
        return type;
    }
    int getField1()const
    {
        return field1;
    }
    int getField2()const
    {
        return field2;
    }
    ///----------------- SET:
    void setType(const RuneType a)
    {
        type = a;
    }
    void setField1(const int a)
    {
        field1 = a;
    }
    void setField2(const int a)
    {
        field2 = a;
    }
};

class RunePage
{
private:
    Primary rightSide;
    Secondary leftSide;
public:
    RunePage() {}
    RunePage(Primary p, Secondary s) : rightSide(p), leftSide(s){}
    RunePage(const RunePage &rp) : rightSide(rp.rightSide), leftSide(rp.leftSide) {}
    ~RunePage() {}
    friend ostream& operator << (ostream &out, RunePage &r)
    {
        out << "******************************************************" << endl;
        out << "RUNE PAGE" << endl << "Primary - ";
        switch(r.rightSide.getType())
        {
            case 0: out << "Sorcery, "; break;
            case 1: out << "Domination, "; break;
            case 2: out << "Inspiration, "; break;
            case 3: out << "Resolve, "; break;
            case 4: out << "Precision, "; break;
        }
        out << r.rightSide.getRune() << endl << "Secondary - ";
        switch(r.leftSide.getType())
        {
            case 0: out << "Sorcery" << endl; break;
            case 1: out << "Domination" << endl; break;
            case 2: out << "Inspiration" << endl; break;
            case 3: out << "Resolve" << endl; break;
            case 4: out << "Precision" << endl; break;
        }
        return out;
    }
};

#endif // RUNES_HPP_INCLUDED
