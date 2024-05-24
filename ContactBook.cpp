#include "ContactBook.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int ContactBook::counter=0;
ContactBook::ContactBook()
{
    //nothing to initialize
}
ContactBook::ContactBook(int contact_size)
{
    m_size=contact_size;
    m_users= new Contact[m_size];//dynamic array
    m_count=0;//index of user array
}

ContactBook::~ContactBook()
{
    delete[]m_users;
}
void ContactBook:: AddUser()
{
    Contact *new_user =new Contact(5);
    new_user->ReadInput();
    m_users[m_count++]=*new_user;
    counter++;
}
void ContactBook:: EditUser(int edit_id)
{
    bool edited=false;
    if(m_count==0)
    {
        cout<<"NO USER EXIST !\n";
        return;
    }
    for(int i=0; i<m_count; i++)
    {
        if(m_users[i].getUserId()==edit_id)
        {
            m_users[i].ReadInput();//edit all information of this user
            edited=true;
            break;
        }

    }
    if(edited)
        cout<<"USER EDITED SUCCESSFULY !\n";
    else
        cout<<"This User Is Not Found !\n";
}
void ContactBook:: CountUser()
{
    cout<<"There are ( "<<counter<<" ) user in your Contact Book :)";
}

void ContactBook:: DeleteUser(int del_id)
{
    if(m_count==0)
    {
        cout<<"NO USER EXIST !\n";
        return;
    }
    bool deleted=false;
    for(int i=0; i<m_count; i++)
    {
        if(m_users[i].getUserId()==del_id)
        {
            //delete from array
            if(i==m_count-1)//last element
                m_count--;
            else
            {
                //replace deleted with last user
                m_users[i]=m_users[m_count-1];
                m_count--;
            }
            deleted=true;
            break;

        }
    }
    if(deleted)
    {
        cout<<"User Deleted Successfully !\n";
        counter--;
    }
    else
        cout<<"This User is not Exist ,Try again !\n";


}
/*void ContactBook:: ShowAll()
{
    for(char a=65 ; a<=122 ; ++a)
    {
        for (int b=0 ; b<m_count; ++b)
        {
            if(a == m_users[b].fChar())
                m_users[b].Show();
        }

    }
}*/
void ContactBook::displaycontactsorted()
{
    if(m_size>0)
    {
        bool flg[m_count] = {0};//set all flags =0

        for(int j=0; j<m_count; j++)
        {
            int k = 0;
            while(flg[k]==1)
            {
                k++; // skip it from comparing as it was printed already
            }
            int min_idx = k;

            for(int i=k; i<m_count; i++)// search for any min between only 0 flags
            {
                if(flg[i]==0 && m_users[min_idx].getFName().compare(m_users[i].getFName()) >0 )
                {
                    min_idx = i;
                }
            }
            //display min and set flag = 1
            m_users[min_idx].Show();
            flg[min_idx] = 1; // mark the printed elements by 1; in order to not be compared again
        }
    }
    if(m_count == 0)
    {
        cout<<"\t\t\t\tThere are no contacts to show! \n";
    }

    CountUser();//display their total count
    cout<<endl;
}

void ContactBook::findAll(string key)const
{
    int found_c=0;
    for(int i=0 ; i<m_count; i++)
    {
        if(m_users[i].FindAny(key))
        {
            m_users[i].Show();
            found_c++;
        }
    }
    if(found_c==0)
        cout<<"\nNO CONTACT FOUND !\n";
    else if(found_c>1)
        cout<<"\n-> Oops! Contacts OverLapped ! please, search with another keyword .. ";
    else
        cout<<"\nFound !\n";

}
void ContactBook::uniqueSearch()
{
    int index,line;
    string k,key;
    cout<<"Press Enter to get ..\n";
    for(int i=1 ; i<15 ; ++i)
    {
        line=0;
        k=getche();
        if(k[0]=='\r')
        {
            break;
        }
        sleep(0.1);
        system("cls");
        key+=k;
        for(int j=0 ; j<m_count; ++j)
        {

            if(m_users[j].findname(key,m_users[j].nameChar(i)))
            {
                cout<<"\033["<<10+j<<";"<<1<<"H";
                system("Color 06");
                cout<<m_users[j].getFName()<<endl;
                index=j;
            }
            else
            {
                for(int x=0; x<m_users[j].getm_phone_count(); ++x)
                {
                    if(m_users[j].findPhone(key,m_users[j].phoneChar(i,x)))
                    {

                        cout<<"\033["<<10+x+line<<";"<<1<<"H";
                        system("Color 04");
                        cout<<m_users[j].getphonenum(x)<<endl;
                        index=j;

                    }
                }
            }
            line+=m_users[j].getm_phone_count();
        }
        cout<<"\033["<<3<<";"<<i+1<<"H";

    }
    cout<<"\n\tfound ! \n";
    m_users[index].Show();
}

