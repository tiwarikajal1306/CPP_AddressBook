#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Person.h"

using namespace std;

class addressBook
{
    vector<Person> person_Record;
    public:
        void addPerson(Person &person);
        void viewPersonDetail();
        void deletePerson(string firstName, string lastName);
        void editPersonDetails(string firstName, string lastName, int option, string updatedDetail);
        bool checkDuplicatePerson(string firstName, string lastName);
};

void addressBook :: addPerson(Person &person)
{
    person_Record.push_back(person);
}

void addressBook :: viewPersonDetail()
{
    cout << "\n**********Person Details************\n" << endl;

    for(Person showDetail : person_Record)
    {
    cout<< "FirstName = " << showDetail.getFirstName() << ", " << "LastName = " << showDetail.getLastName() << ", " << "City = "<< showDetail.getCity() << ", " 
    << "State = " << showDetail.getState() << ", " << "Zip =" << showDetail.getZip() << ", " << "PhoneNumber = " << showDetail.getPhoneNumber() << endl; 
    }
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

    int index = 0;
    for(Person person_Detail : person_Record)
    {
        if(person_Detail.getFirstName() == firstName && person_Detail.getLastName() == lastName)
        {
            switch(option - 1)
            {
                case editDetail :: EDIT_CITY:
                    person_Record[index].setCity(updatedDetail);
                    break;
                case editDetail :: EDIT_STATE:
                    person_Record[index].setState(updatedDetail);
                    break;
                case editDetail :: EDIT_ZIP:
                    person_Record[index].setZip(updatedDetail);
                    break;
                case editDetail :: EDIT_PHONE_NUMBER:
                    person_Record[index].setPhoneNumber(updatedDetail);
                    break;
                default:
                    cout << "Invalid Choice!...Please Enter Valid Choice" << endl;
            }
        }
        index++;
    }
}

void addressBook :: deletePerson(string firstName, string lastName)
{
    int index = 0;
    for(Person person_Detail : person_Record)
    {
        if(person_Detail.getFirstName() == firstName && person_Detail.getLastName() == lastName)
        {
            person_Record.erase(person_Record.begin() + index);
        }
        index++;
    }   
}

bool addressBook :: checkDuplicatePerson(string firstName, string lastName)
{
    int index = 0;
    for(Person person_Detail : person_Record)
    {
        if(person_Record[index].getFirstName() == firstName && person_Record[index].getLastName() == lastName)
        {
            cout << "Duplicate Person Not Allowed..." << endl;
            return false;
        }
    }
    return true;
}
