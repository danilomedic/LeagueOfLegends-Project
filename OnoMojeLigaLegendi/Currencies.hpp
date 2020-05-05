#ifndef CURRENCIES_HPP_INCLUDED
#define CURRENCIES_HPP_INCLUDED

class Currencies
{
private:
    int RP;
    int BE;
public:

    Currencies()
    {
        RP = 0;
        BE = 0;
    }
    Currencies(int rp, int be)
    {
        RP = rp;
        BE = be;
    }
    Currencies(const Currencies &c)
    {
        RP = c.RP;
        BE = c.BE;
    }
    ~Currencies(){}
    void spend(int spender)
    {
        cout << "Stanje: " << BE << "BE, " << RP << "RP." << endl;
        int option;
        do
        {
            cout << "Izaberite opciju:" << endl;
            cout << "1 - Blue Essence" << endl;
            cout << "2 - Riot Points" << endl;
            cout << "3 - Ne trosi" << endl;
            cin >> option;
            if (option < 1 || option > 3)
                cout << "Nepostojeca opcija!" << endl;
        }
        while(option < 1 || option > 2);
        switch(option)
        {
            case 1:
                if(BE > spender)
                    BE -= spender;
                else
                    cout << "Nemate dovoljno Blue Essence za ovu kupovinu!" << endl;
                break;
            case 2:
                if(RP > spender)
                    RP -= spender;
                else
                    cout << "Nemate dovoljno Riot Points za ovu kupovinu!" << endl;
                break;
            case 3:
                return;
        }
    }
};

#endif // CURRENCIES_HPP_INCLUDED
