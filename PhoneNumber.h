#include<string.h>
#include <iostream>
using namespace std;
#ifndef PHONENUMBER_H
#define PHONENUMBER_H
class PhoneNumber
{
public:
    PhoneNumber();
    PhoneNumber(string,string);
    void setPhone(string phone);
    void setType(string type);
    string getPhone();
    string getType();
    void printPhone()const;
    bool isMatched(string key);

    //virtual ~PhoneNumber();
private:
    string m_phone,m_type;
};

#endif // PHONENUMBER_H
