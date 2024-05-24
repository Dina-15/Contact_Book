#include "PhoneNumber.h"
PhoneNumber::PhoneNumber()//ctor
{
    //nothing to initialize
}
PhoneNumber::PhoneNumber(string phone,string type)
{
    setPhone(phone);
    setType(type);

}
void PhoneNumber:: setPhone(string phone)
{
    m_phone=phone;
}
void PhoneNumber:: setType(string type)
{
    m_type=type;
}
void PhoneNumber::printPhone()const
{
    cout<<"Phone Number : "<<m_phone<<"\t|"<<m_type<<endl;
}
string PhoneNumber::getPhone()
{
    return m_phone;
}
string PhoneNumber::getType()
{
    return m_type;
}
bool PhoneNumber::isMatched(string key)
{
    return (m_phone.compare(key)==0);
}

