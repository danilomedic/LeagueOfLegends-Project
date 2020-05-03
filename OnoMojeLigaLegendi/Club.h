#ifndef CLUB_DEF
#define CLUB_DEF
#include <iostream>
#include "dinstring.hpp"
#include "PromoteDemoteSystem.h"
using namespace std;

enum ClubRank{MEMBER, OFFICER, OWNER};

class Club : public PromoteDemoteSystem
{
private:
    DinString name;
    DinString tag;
    int numMembers;
    ClubRank role;
public:
    bool promote();
    bool demote();
};


#endif
