//
// Created by Mon_Pc on 22/07/2023.
//

#ifndef PROJECT_BANK_CPP_PROTOTYPE_H
#define PROJECT_BANK_CPP_PROTOTYPE_H

#include "USER.h"

void Home_Choose();

void Create_New_account();
    int exist_account(string First_nam, string last_name, int Phone_Number,int Age);
    bool exist_username(string username);
    bool Set_Data(USER U);
    int for_set_IP();
    int get_last_ip();

void Login_account();

void Forgot_password();

void ADMIN();

#endif //PROJECT_BANK_CPP_PROTOTYPE_H
