#ifndef CLUB_HPP_INCLUDED
#define CLUB_HPP_INCLUDED
#include "dinstring.hpp"
#include "PromoteDemoteSystem.hpp"

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

#endif // CLUB_HPP_INCLUDED
