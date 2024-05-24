#include<string.h>
#include"PhoneNumber.h"
using namespace std;
#ifndef CONTACT_H
#define CONTACT_H
class Contact
{
public:
    Contact();
    Contact(int m_p_size);
    void setFName(string);
    void setLName(string);
    void setId(int);
    void setage(int);
    void setGender(int);
    void setCity(string);
    void setNote(string);
    void setEmail(string);
    int getUserId();
    void ReadInput();
    void Show();
    bool FindAny(string key)const;
    char fChar();
    string getFName();
    string nameChar(int c);
    bool findname(string k,string name);
    bool findPhone(string k,string phone);
    string phoneChar(int c,int x);
    int getm_phone_count();
    string getphonenum(int j);
    virtual ~Contact();
private:
    PhoneNumber *m_phones;
    int m_phone_size;
    int p_count=0;
    int m_phone_count;
    int m_id,m_age,m_gender;
    char* dt;//set date and time creating the new contact
    string m_fname,m_lname,m_note,m_city,m_email,U_phone,U_type;
};

#endif // CONTACT_H
