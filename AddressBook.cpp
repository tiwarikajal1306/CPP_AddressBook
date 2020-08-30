#include <iostream>
#include <string>
#include <list>
#include "AddressBookOperation.h"
#include <stdlib.h>

using namespace std;

int main()
{
    cout << "**********Welcome To AddressBook***********" << endl;

    addressBook_Operation operation;
   
    int choice;
    int repeat = 1;
    while(repeat == 1) {
      cout << "Enter The Choice  \n1. Add The Person \n2. View Records" << endl;
      cin >> choice;
      cin.ignore(1, '\n');
      switch(choice) {
        case 1:
             operation.addPerson();
             break;
        case 2:
             operation.viewRecords();
             break;
        default:
            cout << "Invalid choice!" <<endl;
            break;
     }
      cout << "To continue press 1\n and for exit press any number " << endl;
      cin >> repeat;
    }

    if(repeat != 2){
         cout << "Exit" << endl;
    }

     return 0;
}
