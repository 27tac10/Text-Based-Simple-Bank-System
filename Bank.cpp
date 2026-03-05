#include <iostream>
#include <string>
#include <vector>

#include "Bank.h"

using namespace std;

Bank::Bank()
{
    master = MasterAccount();
    users = vector<UserAccount>();
}

Bank::~Bank()
{
    // Clean up resources if necessary
}

void Bank::run()
{
    int choice = 0;
    while (choice != 3)
    {
        cout << "Welcome to the Lion Bank!" << endl;
        cout << "1. User Login" << endl;
        cout << "2. Create User Account" << endl;
        cout << "3. Master Login" << endl;
        cout << "4. Exit" << endl;
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (!users.empty())
                {
                    user_login();
                }
                else
                {
                    cout << "No user accounts available. Please create an account first." << endl;
                }
                break;
            case 2:
                create_user_account();
                break;
            case 3:
                master_login();
                break;
            case 4:
                cout << "Thank you for using the Bank System. Goodbye!" << endl;
                break;
                    default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

// Define user and master operation methods to satisfy linker

void Bank::user_login()
{
    // Implementation for user login
    string account_id;
    string account_password;
    cout << "   Enter your account ID: ";
    cin >> account_id;
    cout << "   Enter your account password: ";
    cin >> account_password;


}

void Bank::master_login()
{
    // Implementation for master login
}

void Bank::create_user_account()
{
    // Implementation for creating a new user account
    UserAccount new_user;
    string name, id, password, confirm_password, phone_number, email, address;
    double initial_balance = 0.0;

    cout << "   Enter your name: ";
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, name);

    cout << "   Enter your desired account ID: "; // This will be generated automatically later.
    cin >> id;

    cout << "   Enter your account password: ";
    cin >> password;
    cout << "   Confirm your account password: ";
    cin >> confirm_password;

    while(password != confirm_password)
    {
        cout << "   Passwords do not match. Please try again." << endl;
        cout << "   Enter your account password: ";
        cin >> password;
        cout << "   Confirm your account password: ";
        cin >> confirm_password;
    }

    cout << "   Enter your phone number: ";
    cin >> phone_number;

    cout << "   Enter your email: ";
    cin >> email;

    cout << "   Enter your address: ";
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, address);

    if(name != "" && id != "" && password != "" && phone_number != "" && email != "" && address != "")
    {
        new_user.set_account_name(name);
        new_user.set_account_id(id);
        new_user.set_account_password(password);
        new_user.set_account_phone_number(phone_number);
        new_user.set_account_email(email);
        new_user.set_account_address(address);
        new_user.set_account_balance(initial_balance);
        new_user.set_account_status(PENDING_APPROVAL);
        master.add_account_request(new_user);
    }
    else
    {
        cout << "   All fields are required. Account creation failed." << endl;
        return;
    }
}

