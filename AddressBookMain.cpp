#include <iostream>
#include <string>
#include <list>
#include "AddressBook.h"
#include <stdlib.h>

using namespace std;

addressBook o_AddressBook;

Person takeUserInput(string firstName, string lastName)
{

     cout << "Enter the state of Person: " << endl;
     string state;
     getline(cin, state);

     cout << "Enter the city of person: " << endl;
     string city;
     getline(cin, city);

     cout << "Enter the zipCode of person: " << endl;
     string zip;
     getline(cin, zip);

     cout << "Enter the phoneNumber: " << endl;
     string phoneNumber;
     getline(cin, phoneNumber);

     Person person(firstName, lastName, state, city, zip, phoneNumber);

     return person;
}

void addPersonToAddressBook()
{
     int NumberOfPerson;
     cout << "Enter How Many Person You Want To Add In Address Book" << endl;
     cin >> NumberOfPerson;
     cin.ignore(1, '\n');

     for (int i = 0; i < NumberOfPerson; i++)
     {
          if(i > 0)
          {
               cout << "Enter the next Person Detail \n" << endl;
          }

          cout << "Enter first Name Of Person" << endl;
          string firstName;
          getline(cin, firstName);
          cout << "Enter Last Name Of Person" << endl;
          string lastName;
          getline(cin, lastName);
          bool check_Duplicate = o_AddressBook.checkDuplicatePerson(firstName, lastName);
          if(check_Duplicate)
          {
               Person person = takeUserInput(firstName, lastName);
               o_AddressBook.addPerson(person);
          }
          else
          {
               break;
          }
          
     }
}

void show_Welcome_msg()
{
     cout << "\n************Welcome To Address Book************\n " << endl;
}

void display_Menu_Option()
{
     cout << "Enter Your Choice Which You Want To Perform..." << endl;
     cout << "1. Add The Person In Address Book. \n"
          << "2. Display Person In Address Book. \n"
          << "3. Edit Detail Of Person From Address Book.\n"
          << "4. Delete Detail Of Person From Address Book. \n" 
          << "5. Sort The Person By Name. \n" << endl;
}

void display_Person_Detail()
{
     o_AddressBook.viewPersonDetail();
}

void editPersonDetail()
{
     cout << "\n1. Edit City\n2. Edit State\n3. Edit Zip\n4. Edit PhoneNumber" << endl;
     cout << "Enter The Choice Which You Want To Edit" << endl;

     int option;
     cin >> option;
     cin.ignore(1, '\n');
     cout << "Enter first Name Of Person" << endl;
     string firstName;
     getline(cin, firstName);
     cout << "Enter Last Name Of Person" << endl;
     string lastName;
     getline(cin, lastName);
     cout << "Enter new Detail " << endl;
     string updatedDeatil;
     getline(cin, updatedDeatil);

     o_AddressBook.editPersonDetails(firstName, lastName, option, updatedDeatil);
}

void deletePersonDetail()
{
     cout << "Enter first Name Of Person" << endl;
     string firstName;
     getline(cin, firstName);
     cout << "Enter Last Name Of Person" << endl;
     string lastName;
     getline(cin, lastName);

     o_AddressBook.deletePerson(firstName, lastName);
}

enum choice
{
     ADD_NEW_PERSON,
     DISPLAY_PERSON,
     EDIT_PERSON_DETAIL,
     DELETE_PERSON,
     SORT_PERSON_NAME
};

void perform_Operation()
{
     int menuChoice;
     int repeat = 1;

     while (repeat == 1)
     {
          display_Menu_Option();
          cin >> menuChoice;
          cin.ignore(1, '\n');

          switch (menuChoice - 1)
          {
          case choice :: ADD_NEW_PERSON:
               addPersonToAddressBook();
               break;
          case choice :: DISPLAY_PERSON:
               display_Person_Detail();
               break;
          case choice :: EDIT_PERSON_DETAIL:
               editPersonDetail();
               break;
          case choice :: DELETE_PERSON:
               deletePersonDetail();
               break;
          case choice :: SORT_PERSON_NAME:
               o_AddressBook.sortDetailByName();
               break;
          default:
               cout << "Invalid Choice!...Please Enter Valid Choice. " << endl;
               break;
          }
          cout << "\nTo Continue press 1\nAnd for Exit Press Any Number " << endl;
          cin >> repeat;
     }

     if (repeat != 2)
     {
          cout << "Exit" << endl;
     }
}

int main()
{
     show_Welcome_msg();
     perform_Operation();
     return 0;
}