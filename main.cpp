#include <iostream>
#include "Bank_System.h"

using namespace std;

int main() 
{
    cout << endl;

    //Bank_System bank_system;
    Bank_System new_bank_system("Account_Data.txt");
    
    cout << endl;
    cout << "Welcome to The Bank of C++!" << endl;
    cout << "1. Login to Your Account" << endl;
    cout << "2. Create New Account" << endl;
    cout << "-999. Exit" << endl;
    cout << "Please select an option: ";
    int choice;
    cin >> choice;

    while(choice != -999)
    {
        switch(choice) 
        {
            case 1:
            {
                new_bank_system.login();
                break;
            }
            case 2:
            {
                new_bank_system.create_account();
                break;
            }
            case -999:
            {
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid option selected." << endl;
        }
        cout << endl;
        cout << "1. Login to Your Account" << endl;
        cout << "2. Create New Account" << endl;
        cout << "-999. Exit" << endl;
        cout << "Please select an option: ";
        cin >> choice;
    }
    
    return 0;
}