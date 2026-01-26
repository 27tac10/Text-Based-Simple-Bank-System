#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

Account::Account(string name, string number, double initial_balance, string pwd)
{
    account_name = name;
    account_number = number;
    balance = initial_balance;
    password = pwd;
} 

void Account::deposit(double amount) 
{
    balance += amount;
    cout << "Deposited: " << amount << endl;
    cout << "New Balance: " << balance << endl;
    cout << endl;
}

void Account::withdraw(double amount) 
{
    if (balance >= amount) 
    {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "New Balance: " << balance << endl;
        cout << endl;
    }
    else
    {
        cout << "Insufficient funds for withdrawal." << endl;
        cout << "Current Balance: " << balance << endl;
        cout << endl;
    }
    
}

double Account::get_balance() const 
{
    return balance;
}

string Account::get_account_name() const
{
    return account_name;
}

string Account::get_account_number() const
{
    return account_number;
}

string Account::get_password() const
{
    return password;
}