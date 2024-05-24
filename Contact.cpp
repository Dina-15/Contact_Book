#include "Contact.h"
#include <ctime>
#include <bits/stdc++.h>
Contact::Contact()
{
    //nothing to initialize
}
Contact::Contact(int m_p_size)
{
    m_phone_size = m_p_size;
    m_phones = new PhoneNumber[m_phone_size];
    m_phone_count=0;
}
Contact::~Contact()
{
    delete []m_phones;
}
void Contact::ReadInput()
{
    system("Color 05");
    cout<<"Please Enter User information ..\n";
    cout<<"First Name : ";
    cin>>m_fname;
    cout<<"Last Name : ";
    cin>>m_lname;
    cout<<"Enter id : ";
    cin>>m_id;
    cout<<"Age : ";
    cin>>m_age;
    cout<<"Gender (0-male , 1-female) : ";
    cin>>m_gender;
    cout<<"City : ";
    cin>>m_city;
    cout<<"Any Notes : ";
    cin>>m_note;
    cout<<"Email Address : ";
    cin>>m_email;
    cout<<"Number of Phone Numbers (0 - "<<m_phone_size<<" ) : ";
    cin>>p_count;
    for(int i=0 ; i< p_count ; i++)
    {
        cout<<"Phone Number "<<"("<<i+1<<")  ";
        cin>>U_phone;
        m_phones[i].setPhone(U_phone);
        cout<<"Phone Type : ";
        cin>>U_type;
        m_phones[i].setPhone(U_type);
        //create new phone object
        PhoneNumber *new_phone=new PhoneNumber(U_phone,U_type);
        //store to phone array
        m_phones[m_phone_count++]=*new_phone;

    }
    //char* dt;//set date and time creating the new contact
    time_t now = time(0); //current date/time
    dt = ctime(&now); //convert now to string form
}
void Contact::setFName(string m_fname)
{
    this->m_fname=m_fname;
}
string Contact::getFName()
{
    return this->m_fname;
}
void Contact::setLName(string m_lname)
{
    this->m_lname=m_lname;
}
void Contact::setage(int m_age)
{
    this->m_age=m_age;
}
void Contact::setId(int m_id)
{
    this->m_id=m_id;
}
void Contact::setGender(int m_gender )
{
    this->m_gender=m_gender;
}
void Contact::setCity(string m_city )
{
    this->m_city=m_city;
}
void Contact::setNote(string m_note)
{
    this->m_note=m_note;
}
void Contact::setEmail(string m_email)
{
    this->m_email=m_email;
}
int Contact::getUserId()
{
    return m_id;
}
void Contact::Show()
{
    system("Color 02");
    cout<<"************************************************"
        <<"\nName : "<< m_fname<<" "<<m_lname
        <<"\nGender : "<<(m_gender==0?"MALE":"FEMALE")
        <<"\nID : "<<m_id
        <<"\nAge : "<<m_age
        <<"\nNote : "<<m_note
        <<"\nCity : "<<m_city
        <<"\nEmail Address : "<<m_email
        <<"\nAdded Date : "<<dt<<endl;
    if(m_phone_count>0)
    {
        cout<<"Phone List : \n";
        for(int i=0 ; i<m_phone_count; i++)
        {
            cout<<"  "<<i+1<<" - \t";
            m_phones[i].printPhone();
        }
    }
    cout<<"************************************************"
        <<endl;
}
bool Contact::FindAny(string key)const
{
    if(m_fname.compare(key)==0)
        return true;
    if(m_phone_count>0)
    {
        for(int i=0; i<m_phone_count; i++)
        {
            if(m_phones[i].isMatched(key))
                return true;
        }
    }
    if(m_city.compare(key)==0)
        return true;
    return false;
}
bool Contact::findname(string k,string name)
{
    if(name.compare(k)==0)
        return true;
}
bool Contact::findPhone(string k,string phone)
{

    if(phone.compare(k)==0)
        return true;
}
string Contact::getphonenum(int j)
{
    return m_phones[j].getPhone();
}
string Contact::phoneChar(int c,int x)
{
    string phone="";

    char ch[m_phones[x].getPhone().length()];
    strcpy(ch,m_phones[x].getPhone().c_str());
    for(int i=0; i<c; ++i)
    {
        phone+=ch[i];

    }
    return phone ;
}
int Contact::getm_phone_count()
{
    return m_phone_count;
}
char Contact::fChar()// get first letter of first name
{
    char ch[m_fname.length()];
    strcpy(ch,m_fname.c_str());
    return ch[0];
}
string Contact::nameChar(int c)// get parts of first name
{
    string name;
    char ch[m_fname.length()];
    strcpy(ch,m_fname.c_str());
    for(int i=0; i<c; ++i)
    {
        name+=ch[i];

    }
    return name ;

}
