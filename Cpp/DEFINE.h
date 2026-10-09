//
// Created by Mon_Pc on 22/07/2023.
//

#ifndef PROJECT_BANK_CPP_DEFINE_H
#define PROJECT_BANK_CPP_DEFINE_H
#include "prototype.h"

void Home_Choose(){
    int Choose;
    cout <<"\n   0 - Create a new account ;";
    cout <<"\n   1 - login in your bank ;";
    cout <<"\n   2 - forgot password ;";
    cout <<"\n   3 - ADMIN ;";
    cout <<"\n Choose one : ";

    cin >> Choose;
    system("cls");
    switch(Choose) {
        case 0:
            cout << "\n\t Create a new account !!"<<endl;
            Create_New_account();
            break;
        case 1:
            cout << "\n\t Login"<<endl;
            Login_account();
            break;
        case 2:
            cout << "\n\t You forgot your password"<<endl;
            // Forgot_password();
            break;
        case 3:
            cout << "\n\t Welcome ADMIN !!"<<endl;
            // ADMIN();
            break;
        default:
            system("cls");
            cout << "\n\t Problem de Choose !!\n ";
            Home_Choose();
            break;
    }
}

void Create_New_account(){
    system("cls");
    USER U = *new USER();

    cout << "\n\t Give voter information's .";

    cout <<"\n=>First Name: ";
    cin >>U.first_name;
    cout <<"\n=>Last Name: ";
    cin >>U.Last_name;
    cout <<"\n=>phone number: " ;
    cin >>U.phone_Number;
    cout <<"\n=>Age: ";
    cin >>U.age;

    int valid = exist_account(U.first_name,U.Last_name,U.phone_Number,U.age);

    if (valid == 1){
        exit(0);
    }

    system("cls");

    cout <<"\n validation your information : " ;
    cout <<"\n your information : ";

    U.get_info();

    int v;
    cout <<"\n validation click 1 si non click 0:";
    cin>>v;
    if(v == 0)
        Create_New_account();
    else if(v == 1){
        string username ,username2;
        do {
            cout << endl << "Enter a username: ";
            cin >> username;
            cout << endl << "Confirm username: ";
            cin >> username2;
        } while (username.compare(username2) != 0 || exist_username(username));

        U.set_username(username);

        string password, password2;
        do {
            cout << endl << "Enter a password: ";
            cin >> password;
            cout << endl << "Confirm password: ";
            cin >> password2;
        } while (password.compare(password2)!= 0);

        U.set_password(password);
        Set_Data(U);

        cout<<"Creating new account..."<<endl;

        system("cls");
        cout<<"\n !! creating is completed !! \n";
        int V;
        cout<<"  pour login clicked 1"<<endl;
        cout<<"  pour la page principal click 2"<<endl;
        cout<<"Choose one : ";
        cin>>V;
        if(V==1)
            Login_account();
        else
            Home_Choose();
    }
}

int exist_account(string First_nam, string last_name, int Phone_Number,int Age){
    int valid = 0;
    ifstream infile("DATA/USER_INFO.txt");
    string First_Nam,Last_Nam;
    int phone,AGE;
    while(infile >> First_Nam >> Last_Nam >> phone >> AGE){
        if(First_nam.compare(First_Nam)==0){
            cout << " change the first Nam" << endl;
            cout << "Waiting for 5 seconds..." << endl;
            sleep(5);
            Create_New_account();
        valid =1;
           break;
            }else if(Last_Nam.compare(last_name) == 0){
                cout << " change the last Nam" << endl;
                cout << "Waiting for 5 seconds..." << endl;
                sleep(5);
                Create_New_account();
            valid =1;
                break;
                }else if(phone == Phone_Number){
                    cout << " change the phone number" << endl;
                    cout << "Waiting for 5 seconds..." << endl;
                    sleep(5);
                    Create_New_account();
                valid =1;
                    break;
                    }else if(AGE == Age){
                        cout << " change the age" << endl;
                        cout << "Waiting for 5 seconds..." << endl;
                        sleep(5);
                        Create_New_account();
                    valid =1;
                        break;
                        }
        infile.close();
        return valid;
    }
}

bool exist_username(string username) {
    bool valid = false;
    ifstream infile("DATA/USER_NAM_PASS.txt");
    string username2;
    while (infile >> username2) {
        if (username.compare(username2)==0){
            valid = true;
            cout << "Change Username !!"<<endl;
            break;
        }
    }
    infile.close();
    return valid;

}

int for_set_IP(){
        
    int IP0=get_last_ip();
    
    return IP0+1;
}

int get_last_ip(){
    ifstream infile("IP/ALL_IP");
    int IP;
    while( infile >> IP) { }
    infile.close();
    return IP;
}

void Login_account(){
    system("cls");
    ifstream infile("DATA/USER_NAM_PASS.txt");
    string stored_username, stored_password;
    string entered_username, entered_password;
    int account_ip;

    cout << "\n  Your username :";
    cin >> entered_username;
    cout << "\n Your password :";
    cin >> entered_password;

    bool authenticated = false;
    while (infile >> stored_username >> stored_password >> account_ip) {
        if (stored_username == entered_username && stored_password == entered_password) {
            authenticated = true;
            break;
        }
    }
    infile.close();

    if (authenticated)
        cout << "\n Welcome to your bank !!";
    else
        cout << "\n Invalid username or password.";
};

void Set_Data(USER U){

    ofstream outfile1("DATA/USER_INFO.txt");
    outfile1 << U.first_name << " " << U.Last_name << " " << U.phone_Number << " " << U.age << endl;
    outfile1.close();

    ofstream outfile("DATA/USER_NAM_PASS.txt");
    int IP=for_set_IP();
    outfile << U.get_username() << " " << U.get_password() << " " << IP <<endl;
    outfile.close();
}

#endif //PROJECT_BANK_CPP_DEFINE_H
