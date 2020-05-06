#ifndef LOGININFO_HPP_INCLUDED
#define LOGININFO_HPP_INCLUDED
#include "dinstring.hpp"

enum Server {EUNE, EUWEST, NA, BRAZIL, TURKEY, LATIN_AMERICA, OCEANIA, RUSSIA, JAPAN, KOREA};

class LoginInfo
{
protected:
    DinString username;
    DinString password;
    DinString language;
    Server server;
public:
    LoginInfo() {}
    LoginInfo(DinString u, DinString p, DinString l, Server s)
    {
        username = u;
        password = p;
        language = l;
        server = s;
    }
    LoginInfo(const LoginInfo &li)
    {
        username = li.username;
        password = li.password;
        language = li.language;
        server = li.server;
    }
    ~LoginInfo() {}
    bool passwordStrength()
    {
        int counter = 0;
        char * sifra = password.getText();
        if(password.length() >= 8)
        {
            for(int i = 0; i != password.length(); ++i)
            {
                if(sifra[i] >=97 && sifra[i] <=122)
                    counter++;
            }
            if(counter > 0)
            {
                counter = 0;
                for(int i = 0; i != password.length(); ++i)
                {
                    if(sifra[i] >=48 && sifra[i] <=57)
                        counter++;
                }
                if(counter > 0)
                    return true;
            }
        }
        return false;
    }
    ///----------------- GET:
    DinString getUsername() const
    {
        return username;
    }
    DinString getPassword() const
    {
        return password;
    }
    DinString getLanguage() const
    {
        return language;
    }
    int getServer() const
    {
        return server;
    }
    ///----------------- SET:
    void setUsername(const DinString a)
    {
        username = a;
    }
    void setPassword(const DinString a)
    {
        password = a;
    }
    void setLanguage(const DinString a)
    {
        language = a;
    }
    void setServer(const Server s)
    {
        server = s;
    }
};

#endif // LOGININFO_HPP_INCLUDED
