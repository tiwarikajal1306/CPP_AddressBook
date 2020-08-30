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
    string getFirstName() {
        return firstName;
    }

    void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    string getLastName() {
        return lastName;
    }

    void setLastName(String lastName) {
        this.lastName = lastName;
    }

    string getState() {
        return state;
    }

    void setState(String state) {
        this.state = state;
    }

    string getCity() {
        return city;
    }

    void setCity(String city) {
        this.city = city;
    }

    string getZip() {
        return zip;
    }
