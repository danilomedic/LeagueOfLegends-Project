#ifndef LOGININFO_HPP_INCLUDED
#define LOGININFO_HPP_INCLUDED
#include "dinstring.hpp"

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

#endif // LOGININFO_HPP_INCLUDED
