#ifndef LOGININFO_DEF
#define LOGININFO_DEF
#include <iostream>
#include "dinstring.hpp"
using namespace std;

enum Server{EUNE, EUWEST, NA, BRAZIL, TURKEY, LATIN_AMERICA, OCEANIA, RUSSIA, JAPAN, KOREA};

class LoginInfo
{
protected:
    DinString username;
    DinString password;
    DinString language;
    Server server;
public:
    bool passwordStrength;
};

#endif
