#ifndef FRIEND_DEF
#define FRIEND_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

enum PlayFrequency{NEVER, ONCE_MONTH, ONCE_WEEK, ONCE_DAY, PREMADE, RANKED_PREMADE};

class Friend
{
private:
    DinString summName;
    PlayFrequency freq;
    bool sameClub;
public:
    bool playMoreOften();
};

#endif
