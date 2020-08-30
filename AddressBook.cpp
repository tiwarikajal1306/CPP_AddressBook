#include <iostream>
#include <string>
#include <list>
#include "Person.h"

using namespace std;
list<Person> record;
int main()
{
    Person p;
    cout << "**********Welcome To AddressBook***********" << endl;
    cout << "Enter the first Name of person: " << endl;
    string firstName;
    getline (cin, firstName);
    p.setFirstName(firstName);
    cout << "Enter the last Name of the Person: " << endl;
    string lastName;
    getline (cin, lastName);
    p.setLastName(lastName);
    cout << "Enter the state of Person: " << endl;
    string state;
    getline (cin, state);
    p.setState(state);
    cout << "Enter the city of person: " << endl;
    string city;
    getline (cin, city);
    p.setCity(city);
    cout << "Enter the zipCode of person: " << endl;
    string zip;
    getline (cin, zip);
    p.setZip(zip); 
    cout << "Enter the phoneNumber: " << endl;
    string phoneNumber;
    getline (cin, phoneNumber);
    p.setPhoneNumber(phoneNumber);
    record.push_back(p);

    cout << "view the record" << endl;
    for(Person data : record) {
        cout<< "FirstName = " << data.getFirstName() << ", " << "LastName = " << data.getLastName() << ", " << "City = "<< data.getCity() << ", " 
        << "State = " << data.getState() << ", " << "Zip =" << data.getZip() << ", " << "PhoneNumber = " << data.getPhoneNumber() << endl; 
    }

     return 0;
}
