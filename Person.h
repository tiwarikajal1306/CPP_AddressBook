#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    string state;
    string city;
    string zip;
    string phoneNumber;

public:
    Person()
    {

    }
    
    Person(string firstName, string lastName) {
        this -> firstName = firstName;
        this -> lastName = lastName;
        this -> state = state;
        this -> city = city;
        this -> zip = zip;
        this -> phoneNumber = phoneNumber;
    }
    string getFirstName() {
        return firstName;
    }

    void setFirstName(string firstName) {
        this -> firstName = firstName;
    }

    string getLastName() {
        return lastName;
    }

    void setLastName(string lastName) {
        this -> lastName = lastName;
    }

    string getState() {
        return state;
    }

    void setState(string state) {
        this -> state = state;
    }

    string getCity() {
        return city;
    }

    void setCity(string city) {
        this -> city = city;
    }

    string getZip() {
        return zip;
    }

    void setZip(string zip) {
        this -> zip = zip;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }
    
    void setPhoneNumber(string phoneNumber) {
        this -> phoneNumber = phoneNumber;
    }
};
