#ifndef FRIEND_HPP_INCLUDED
#define FRIEND_HPP_INCLUDED
#include "dinstring.hpp"

enum PlayFrequency{NEVER, ONCE_MONTH, ONCE_WEEK, ONCE_DAY, PREMADE, RANKED_PREMADE};

class Friend
{
private:
    DinString summName;
    PlayFrequency freq;
    bool sameClub;
public:
    Friend(){}
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
    ~Friend(){}
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

};

#endif // FRIEND_HPP_INCLUDED
