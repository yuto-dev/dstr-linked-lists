// poggies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void userSelect(), nurseLogin(), doctorLogin();

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};



int main()
{
    doctorLogin();
}

void userSelect() {
    int userType;
    cout << "What kind of user are you?" << endl;
    cout << "1. Nurse" << endl;
    cout << "2. Doctor" << endl;
    cout << "Enter user type: ";
    cin >> userType;
    //cout << "Your age is: " << userType << endl;

    if (userType == 1) {
        nurseLogin();
    }
    else if (userType == 2) {
        doctorLogin();
    }
    else {
        cout << "Incorrect user type, please try again!" << endl;
        userSelect();
    }
}

void nurseLogin() {
    cout << "Hello nurse!" << endl;
    main();
}

void doctorLogin() {
    cout << "Hello doctor!" << endl;
}