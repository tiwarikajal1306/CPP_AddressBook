#include <iostream>
#include <string>
#include <list>
#include "Person.h"

using namespace std;

class addressBook
{
    Person person;
    public:
        void addPerson(Person &person);
        void viewPersonDetail();
        void setPersonDetail(Person &person);
        Person getPersonDetail();
        void editPersonDetails(string firstName, string lastName, int option, string updatedDetail);
};

void addressBook :: setPersonDetail(Person &person)
{
    this -> person = person;
}

Person addressBook :: getPersonDetail()
{
    return person;
}

void addressBook :: addPerson(Person &person)
{
    addressBook :: setPersonDetail(person);
}

void addressBook :: viewPersonDetail()
{
    cout << "\n**********Person Details************\n" << endl;
    cout<< "FirstName = " << person.getFirstName() << ", " << "LastName = " << person.getLastName() << ", " << "City = "<< person.getCity() << ", " 
    << "State = " << person.getState() << ", " << "Zip =" << person.getZip() << ", " << "PhoneNumber = " << person.getPhoneNumber() << endl; 

}

void addressBook :: editPersonDetails(string firstName, string lastName, int option, string updatedDetail)
{
    enum editDetail
    {
        EDIT_CITY,
        EDIT_STATE,
        EDIT_ZIP,
        EDIT_PHONE_NUMBER
    };

    if(person.getFirstName() == firstName && person.getLastName() == lastName)
    {
        switch(option - 1)
        {
            case editDetail :: EDIT_CITY:
                person.setCity(updatedDetail);
                break;
            case editDetail :: EDIT_STATE:
                person.setState(updatedDetail);
                break;
            case editDetail :: EDIT_ZIP:
                person.setZip(updatedDetail);
                break;
            case editDetail :: EDIT_PHONE_NUMBER:
                person.setPhoneNumber(updatedDetail);
                break;
            default:
                cout << "Invalid Choice!...Please Enter Valid Choice" << endl;
        }
    }
}
