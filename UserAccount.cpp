#include <iostream>
#include <string>
#include <vector>

#include "UserAccount.h"

using namespace std;

UserAccount::UserAccount()
{
    account_balance = 0.0;
    account_status = PENDING_APPROVAL;
    account_address = "";
    notifications = {};
}

void UserAccount::set_account_balance(double balance)
{
    account_balance = balance;
}

double UserAccount::get_account_balance() const
{
    return account_balance;
}

void UserAccount::set_account_status(status new_status)
{
    account_status = new_status;
}

status UserAccount::get_account_status() const
{
    return account_status;
}

void UserAccount::set_account_address(const string& address)
{
    account_address = address;
}

string UserAccount::get_account_address() const
{
    return account_address;
}

void UserAccount::deposit()
{
    double deposit_amount = 0;
    cout << "   Enter the amount to deposit: ";
    cin >> deposit_amount;
    account_balance += deposit_amount;
    cout << "   Deposit successful. New balance: " << account_balance << endl;
}

void UserAccount::withdraw()
{
    double withdraw_amount = 0;
    cout << "   Enter the amount to withdraw: ";
    cin >> withdraw_amount;
    if (!balance_validation(withdraw_amount))
    {
        cout << "   Insufficient funds. Withdrawal failed." << endl;
    }
    else
    {
        account_balance -= withdraw_amount;
        cout << "   Withdrawal successful. New balance: " << account_balance << endl;
    }
}

void UserAccount::transfer(UserAccount& recipient, double amount)
{
    // Implementation for transferring money to another user account
}

void UserAccount::transaction_history() const
{
    // Implementation for displaying the transaction history of the accounts
}

void UserAccount::notification()
{
    int num_notifications = notifications.size();

    cout << "   You have " << num_notifications << " notifications." << endl;
    for (int i = 0; i < num_notifications; ++i)
    {
        cout << "   " << i << ": " << notifications[i] << endl;
    }
}

bool UserAccount::balance_validation(double amount) const
{
    if (amount > account_balance)
    {
        return false;
    }
    else
    {
        return true;
    }
}
