#ifndef CLUB_HPP_INCLUDED
#define CLUB_HPP_INCLUDED
#include "dinstring.hpp"
#include "PromoteDemoteSystem.hpp"
#include "Friend.hpp"

enum ClubRank {MEMBER, OFFICER, OWNER};

class Club : public PromoteDemoteSystem
{
private:
    DinString name;
    DinString tag;
    int numMembers;
    ClubRank role;
public:
    Club() {}
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
    ~Club() {}
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
    ///----------------- GET:
    DinString getName()const
    {
        return name;
    }
    DinString getTag()const
    {
        return tag;
    }
    int getNumMembers()const
    {
        return numMembers;
    }
    int getRole()const
    {
        return role;
    }
    ///----------------- SET:
    void setName(const DinString n)
    {
        name = n;
    }
    void setTag(const DinString n)
    {
        tag = n;
    }
    void setNumMembers(const int a)
    {
        numMembers = a;
    }
    void setRole(const ClubRank r)
    {
        role = r;
    }
    friend ostream& operator << (ostream &out, Club &c)
    {
        out << "******************************************************" << endl;
        out << "CLUB" << endl;
        out << "Name: " << c.getName() << " (" << c.getTag() << ")" << endl;
        switch(c.getRole())
        {
            case 0: out << c.getNumMembers() << " members, your role is: MEMBER" << endl; break;
            case 1: out << c.getNumMembers() << " members, your role is: OFFICER" << endl; break;
            case 2: out << c.getNumMembers() << " members, your role is: OWNER" << endl; break;
        }
        return out;
    }
};

#endif // CLUB_HPP_INCLUDED
