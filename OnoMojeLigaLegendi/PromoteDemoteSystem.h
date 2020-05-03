#ifndef  PROMOTEDEMOTESYSTEM_DEF
#define  PROMOTEDEMOTESYSTEM_DEF
#include <iostream>
using namespace std;

class PromoteDemoteSystem
{
public:
    virtual bool promote() = 0;
    virtual bool demote() = 0;
};

#endif
