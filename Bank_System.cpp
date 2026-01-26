#include "Bank_System.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Bank_System::Bank_System()
{
    account_count = 0;
    current_account_index = -1;
    last_account_number = "10000";
    //current_account = nullptr;
}

Bank_System::Bank_System(string file)
{
    ifstream input;
    input.open(file);
    if(!input)
    {
        cerr << "Error opening file: " << file << endl;
        account_count = 0;
        current_account_index = -1;
        last_account_number = "10000";
        return;
    }
    string line;
    getline(input, line);
    stringstream ss(line);
    string account_count_str;
    getline(ss, account_count_str, ',');
    getline(ss, last_account_number);

    account_count = stoi(account_count_str);
    current_account_index = -1;
    
    //cout << "Account Count: " << account_count << endl;
    //cout << "Last Account Number: " << last_account_number << endl;

    for(int i = 0; i < account_count; i++) 
    {
        getline(input, line);
        stringstream ss(line);
        string name, number, balance_str, pwd;
        getline(ss, name, ',');
        getline(ss, number, ',');
        getline(ss, pwd, ',');
        getline(ss, balance_str);
        double balance = stod(balance_str);
        accounts[i] = Account(name, number, balance, pwd);
        //cout << "Loaded Account: " << name << ", " << number << ", " << balance << ", " << pwd << endl;
    }
}

bool Bank_System::Add_Account(const string name, string number, double initial_balance, string pwd)
{
    if (account_count < 100) 
    {
        for(int i = 0; i < account_count; i++) 
        {
            if (accounts[i].get_account_number() == number) 
            {
                cout << "Account number already exists. Please choose a different number." << endl;
                return false;
            }
        }
        accounts[account_count] = Account(name, number, initial_balance, pwd);
        account_count++;
        return true;
    }
    else
    {
        cout << "Account limit reached. Cannot add more accounts." << endl;
        return false;
    }
}

void Bank_System::run(const string name, string number, string pwd)
{
    //current_account = nullptr;
    bool found = false;
    for (int i = 0; i < account_count; i++) 
    {
        if (accounts[i].get_account_name() == name && accounts[i].get_account_number() == number) 
        {
            //current_account = &accounts[i];
            current_account_index = i;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Account not found. Please check your credentials." << endl;
    }
    else
    {
        cout << "Welcome, " << accounts[current_account_index].get_account_name() << "!" << endl;
        
        int choice;
        do 
        {
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Check Balance" << endl;
            cout << "-999. Logout" << endl;
            cout << "Please select an option: ";
            cin >> choice;

            switch (choice) 
            {
                case 1:
                {
                    double amount;
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    accounts[current_account_index].deposit(amount);
                    break;
                }
                case 2:
                {
                    double amount;
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    accounts[current_account_index].withdraw(amount);
                    break;
                }
                case 3:
                {
                    cout << "Current Balance: " << accounts[current_account_index].get_balance() << endl;
                    break;
                }
                case -999:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid option selected." << endl;
            }
        } while (choice != -999);
    }
}

void Bank_System::login()
{
    string name;
    string number;
    string pwd;

    cout << "Enter Account Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> number;
    cout << "Enter Password: ";
    cin >> pwd;
    if(!verify_account(name, number, pwd))
    {
        cout << "Invalid credentials. Login failed." << endl;
    }
    else
    {
        run(name, number, pwd);
    }
}

void Bank_System::create_account()
{
    string name;
    string number;
    double initial_deposit;
    string pwd;
    cout << "Enter Desired Account Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Desired Password: ";
    cin >> pwd;
    cout << "Enter Initial Deposit Amount: ";
    cin >> initial_deposit;

    number = last_account_number;
    last_account_number = to_string(stoi(last_account_number) + 1);

    if(Add_Account(name, number, initial_deposit, pwd))
    {
        cout << endl;
        cout << "Account successfully created!" << endl;
        cout << "Account Name: " << name << endl;
        cout << "Account Number: " << number << endl;
        cout << "Initial Balance: " << initial_deposit << endl;
    }
    else
    {
        cout << "Failed to create account. Please try again." << endl;
    }
}

bool Bank_System::verify_account(const string name, string number, const string pwd)
{
    for (int i = 0; i < account_count; i++) 
    {
        if (accounts[i].get_account_name() == name && accounts[i].get_account_number() == number) 
        {
            if (accounts[i].get_password() == pwd) 
            {
                return true;
            }
        }
    }
    return false;
}