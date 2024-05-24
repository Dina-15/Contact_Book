#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include "ContactBook.h"
#include "Contact.h"
#include "PhoneNumber.h"
using namespace std;

int main()
{
    system("Color D0");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t*********************************\n";
    cout<<"\t\t\t\t\t** Welcome To Contact Book App **\n";
    cout<<"\t\t\t\t\t*********************************";
    getch();
    int ch,opt=-1;
    ContactBook user(100);//max number of users
    while( opt !=0)
    {
        system("cls");
        system("Color 03");
        cout<<" \n\n\t\tMAIN MENU \n"
            <<"\t    =================\n\n"
            <<"[1] Add A New Contact\n[2] Delete A Contact\n[3] Search For A Contact\n"
            <<"[4] Edit A Contact\n[5] Display All Contacts\n[6] Unique Search\n"
            <<"[0] Exit The Program\n"<<endl;
        cout<<"Your Choice Is : ";
        cin>>ch;
        system("cls");

        switch(ch)
        {
        case 1 ://add new contact
        {
            system("cls");
            cout<<"\n\tNow you are creating a new Contact \x06\n\n";
            user.AddUser();

        }
        break;
        case 2 ://delete a contact
        {
            system("cls");
            cout<<"\n\tTake care ! You are going to DELETE a Contact \x05\n\n";
            int del_id=0;
            cout<<"\n\tEnter contact id to delete : ";
            cin>>del_id;
            user.DeleteUser(del_id);
        }
        break;
        case 3 ://search for a contact
        {
            system("cls");
            string key;
            cout<<"\n\tEnter keyword (Name , Phone Number or city) to find : ";
            cin>>key;
            user.findAll(key);
        }
        break;
        case 4://Edit a contact
        {
            system("cls");
            int edit_id;
            cout<<"\n\tEnter User ID to Edit : ";
            cin>> edit_id;
            user.EditUser(edit_id);
        }
        break;
        case 5 :// show all contacts
        {
            system("cls");
            cout<<"\n\tThis is All Contacts till now \x06\n\n";
            user.displaycontactsorted();
        }
        break;
        case 6:
        {
            system("cls");
            cout<<"Enter (first name or phone number) to search .. "<<endl;
            user.uniqueSearch();
        }
        break;
        case 0://exit program
            exit(0);
            break;
        default:
        {
            cout<< "\n\tOops ! Please , Enter A Valid Choice \x02\n" ;
            sleep(2);
            system("cls");
            continue;
        }
        }
        cout<<"\n\n..Enter your choice : \n[1] main Menu\t\t[0]Exit\n";
        cin>>opt;
        system ("cls");
    }
    cout<<"\n\tThanks \x03";
    return 0;
}
