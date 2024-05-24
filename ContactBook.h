#include "Contact.h"
using namespace std;
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
class ContactBook
{
public:
    ContactBook();
    ContactBook(int contact_size);
    void AddUser();
    void EditUser(int);
    void CountUser();
    void DeleteUser(int);
    //void ShowAll();
    void findAll(string key)const;
    void displaycontactsorted();
    void uniqueSearch();
    virtual~ContactBook();

private:
    int m_count;
    Contact *m_users; //composition class
    int m_size;//size of dynamic array of users
    static int counter;//counter for number of users created

};
#endif // CONTACTBOOK_H
