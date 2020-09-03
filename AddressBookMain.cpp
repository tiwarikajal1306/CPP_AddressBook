#include <iostream>
#include <string>
#include <list>
#include "AddressBook.h"
#include <stdlib.h>

using namespace std;

addressBook o_AddressBook;

Person takeUserInput(string firstName, string lastName)
{
     Person person(firstName, lastName);

     cout << "---> State Name   :\t";
     string state;
     getline(cin, state);
     person.setState(state);

     cout << "---> City Name    :\t";
     string city;
     getline(cin, city);
     person.setCity(city);

     cout << "---> Zip Number   :\t";
     string zip;
     getline(cin, zip);
     person.setZip(zip);

     cout << "---> Phone Number :\t";
     string phoneNumber;
     getline(cin, phoneNumber);
     person.setPhoneNumber(phoneNumber);
     
     return person;
}

void addPersonToAddressBook()
{
     int NumberOfPerson;
     cout << "---> Enter Number Of Person You Want To Add\n" << endl;
     cin >> NumberOfPerson;
     cin.ignore(1, '\n');

     for (int i = 0; i < NumberOfPerson; i++)
     {
          if (i > 0)
          {
               cout << "\n---> Next Entry...\n"
                    << endl;
          }

          cout << "---> First Name   :\t";
          string firstName;
          getline(cin, firstName);
          cout << "---> Last Name    :\t";
          string lastName;
          getline(cin, lastName);
          bool check_Duplicate = o_AddressBook.checkDuplicatePerson(firstName, lastName);
          if (check_Duplicate)
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
     cout << "\n\t\t\t\t\t\t\t\t************Welcome To Address Book************ " << endl;
     cout << "\t\t\t\t\t\t\t===============================================================" << endl; 
}

void display_Menu_Option()
{
     cout << "\t\t\t\t\t\t\t*********Enter Your Choice Which You Want To Perform***********\n" << endl;
     cout << "\t\t\t\t\t\t\t|1| Add New Person\t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|2| Display Person Details\t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|3| Edit Person Details\t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|4| Delete Person \t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|5| Sort Person(s) By Name \t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|6| Sort Person(s) By Address Details \t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|7| Search Person(s) By City And State \t\t \n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|8| Search Person(s) By City Or State \t\t \n"
          << "----------------------------------------------------------------------------------------------"
          << "----------------------------------------------------------------------------------------------------"
          << endl;
}

void display_Person_Detail()
{
     o_AddressBook.viewPersonDetail();
}

void editPersonDetail()
{
     cout << "\n-----------------------------------------------------------------\n"
          << "|1| Edit City\n|2| Edit State\n|3| Edit Zip\n|4| Edit PhoneNumber\n"
          << "-----------------------------------------------------------------\n" << endl;
     cout << "---> Enter The Choice Which You Want To Edit" << endl;

     int option;
     cin >> option;
     cin.ignore(1, '\n');
     cout << "---> First Name   :\t";
     string firstName;
     getline(cin, firstName);
     cout << "---> Last Name    :\t";
     string lastName;
     getline(cin, lastName);
     cout << "\n--> Enter new Detail  :\t" << endl;
     string updatedDeatil;
     getline(cin, updatedDeatil);

     o_AddressBook.editPersonDetails(firstName, lastName, option, updatedDeatil);
}

void deletePersonDetail()
{
     cout << "---> First Name   :\t";
     string firstName;
     getline(cin, firstName);
     cout << "---> Last Name    :\t";
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
     SORT_PERSON_NAME,
     SORT_PERSON_ADDRESS,
     SEARCH_CITY_AND_STATE,
     SEARCH_CITY_OR_STATE
};

void sortDetailByAddress()
{
     cout << "\n\t\t\t\t\t--->Enter The Choice On The Basis Of Which You Want To Sort The Record.\n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|1| Sort Address Book Record According To Person City.\n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|2| Sort Address Book Record According To Person State.\n"
          << "\t\t\t\t\t\t\t--------------------------------------------------------------\n"
          << "\t\t\t\t\t\t\t|3| Sort Address Book Record According To Person Zip.\n"
          << endl;

     int choice;
     cin >> choice;
     cin.ignore(1, '\n');

     enum sort_choice
     {
          SORT_BY_CITY,
          SORT_BY_STATE,
          SORT_BY_ZIP
     };

     switch (choice - 1)
     {
     case sort_choice::SORT_BY_CITY:
          o_AddressBook.sortDetailByCity();
          break;
     case sort_choice::SORT_BY_STATE:
          o_AddressBook.sortDetailByState();
          break;
     case sort_choice::SORT_BY_ZIP:
          o_AddressBook.sortDetailByZip();
          break;
     default:
          cout << "Invalid Input, Try Again..." << endl;
          break;
     }
}

void search_Person_By_City_And_State()
{
     cout << "---> City Name   :\t";
     string cityName;
     getline(cin, cityName);

     cout << "---> State Name   :\t";
     string stateName;
     getline(cin, stateName);

     o_AddressBook.searchPersonBYCityAndState(cityName, stateName);
}

void search_Person_By_City_Or_State()
{
    cout << "---> City Or State Name   :\t";
    string city_Or_State_Name;
    getline(cin, city_Or_State_Name);

    o_AddressBook.searchPersonBYCityOrState(city_Or_State_Name);
}

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
          case choice ::ADD_NEW_PERSON:
               addPersonToAddressBook();
               break;
          case choice ::DISPLAY_PERSON:
               display_Person_Detail();
               break;
          case choice ::EDIT_PERSON_DETAIL:
               editPersonDetail();
               break;
          case choice ::DELETE_PERSON:
               deletePersonDetail();
               break;
          case choice ::SORT_PERSON_NAME:
               o_AddressBook.sortDetailByName();
               break;
          case choice ::SORT_PERSON_ADDRESS:
               sortDetailByAddress();
               break;
          case choice ::SEARCH_CITY_AND_STATE:
               search_Person_By_City_And_State();
               break;
          case choice ::SEARCH_CITY_OR_STATE:
               search_Person_By_City_Or_State();
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