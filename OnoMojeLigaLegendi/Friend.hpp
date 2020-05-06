#ifndef FRIEND_HPP_INCLUDED
#define FRIEND_HPP_INCLUDED
#include "dinstring.hpp"

enum PlayFrequency {NEVER, ONCE_MONTH, ONCE_WEEK, ONCE_DAY, PREMADE, RANKED_PREMADE};

class Friend
{
private:
    DinString summName;
    PlayFrequency freq;
    bool sameClub;
public:
    Friend() {}
    Friend(DinString sN, PlayFrequency f, bool sC)
    {
        summName = sN;
        freq = f;
        sameClub = sC;
    }
    Friend(const Friend &f)
    {
        summName = f.summName;
        freq = f.freq;
        sameClub = f.sameClub;
    }
    ~Friend() {}
    void playMoreOften()
    {
        if(freq != RANKED_PREMADE)
        {
            int freqCon = (int)freq;
            freqCon++;
            freq = (PlayFrequency)freqCon;
        }
        else
            cout << "Nije moguce igrati vise, nadji zivot!" << endl;
    }
    ///----------------- GET:
    DinString getSummName() const
    {
        return summName;
    }
    int getFreq() const
    {
        return freq;
    }
    bool getSameClub() const
    {
        return sameClub;
    }
    ///----------------- SET:
    void setSummName(const DinString n)
    {
        summName = n;
    }
    void setFreq(const PlayFrequency f)
    {
        freq = f;
    }
    void setSameClub(const bool sC)
    {
        sameClub = sC;
    }
    friend ostream& operator << (ostream &out, Friend &f)
    {
        out << "******************************************************" << endl;
        out << "FRIEND" << endl;
        out << "Name: " << f.getSummName() << endl;
        if(f.getSameClub())
            out << "U istom ste klubu" << endl;
        switch(f.getFreq())
        {
            case 0: cout << "Ne igrate nikad zajedno" << endl; break;
            case 1: cout << "Zajedno igrate jednom mesecno" << endl; break;
            case 2: cout << "Zajedno igrate jednom nedeljno" << endl; break;
            case 3: cout << "Zajedno igrate jednom dnevno" << endl; break;
            case 4: cout << "Zajedno igrate uvek" << endl; break;
            case 5: cout << "Zajedno igrate ranked" << endl; break;
        }
        return out;
    }
};

#endif // FRIEND_HPP_INCLUDED
