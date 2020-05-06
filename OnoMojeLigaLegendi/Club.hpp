#ifndef CLUB_HPP_INCLUDED
#define CLUB_HPP_INCLUDED
#include "dinstring.hpp"
#include "PromoteDemoteSystem.hpp"
#include "Friend.hpp"

enum ClubRank{MEMBER, OFFICER, OWNER};

class Club : public PromoteDemoteSystem
{
private:
    DinString name;
    DinString tag;
    int numMembers;
    ClubRank role;
public:
    Club(){}
    Club(DinString n, DinString t, int nM, ClubRank r)
    {
        name = n;
        tag = t;
        numMembers = nM;
        role = r;
    }
    Club(const Club &cr)
    {
        name = cr.name;
        tag = cr.tag;
        numMembers = cr.numMembers;
        role = cr.role;
    }
    ~Club(){}
    void promote()
    {
        if(role == MEMBER)
        {
            role = OFFICER;
        }
    }
    void demote()
    {
        if(role == OFFICER)
        {
            role = MEMBER;
        }
    }
    void transferOwnership()
    {
        if(role == OFFICER)
        {
            role = OWNER;
        }
    }
};

#endif // CLUB_HPP_INCLUDED
