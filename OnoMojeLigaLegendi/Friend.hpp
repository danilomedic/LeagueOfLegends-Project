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
    bool playMoreOften();
};

#endif // FRIEND_HPP_INCLUDED
