//
// Created by Mon_Pc on 22/07/2023.
//

#ifndef PROJECT_BANK_CPP_USER_H
#define PROJECT_BANK_CPP_USER_H

#include <iostream>
#include "stdbool.h"
#include <string>
#include <fstream>


using namespace std;

class USER {
private :
    string username;
    string password;
    string get_username() { return this->username; }
    string get_password() { return this->password; }
    void set_password(string password) { this->password = password; }
    void set_username(string username) { this->username = username; }
    friend void Create_New_account();
    friend void Set_Data(USER U);

public :
    string first_name;
    string Last_name;
    int phone_Number;
    int age;

    void get_info() const {
        cout << "\n First Name : "<<this->first_name << endl;
        cout << " Last Name  :"<<this->Last_name << endl;
        cout << " Phone : "<<this->phone_Number << endl;
        cout << " Age : "<<this->age<<endl;
    };
};


#endif //PROJECT_BANK_CPP_USER_H
