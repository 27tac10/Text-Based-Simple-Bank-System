#include <iostream>
#include "MasterAccount.h"

using namespace std;

MasterAccount::MasterAccount()
{
    // initialize anything specific to master account
}

void MasterAccount::account_request()
{
    cout << "MasterAccount::account_request() called" << endl;
}

void MasterAccount::approve_request(const string& account_id)
{
    cout << "Approving request for account " << account_id << endl;
}

void MasterAccount::reject_request(const string& account_id)
{
    cout << "Rejecting request for account " << account_id << endl;
}

void MasterAccount::view_all_accounts() const
{
    cout << "Viewing all user accounts" << endl;
}

void MasterAccount::suspend_account(const string& account_id)
{
    cout << "Suspending account " << account_id << endl;
}

void MasterAccount::add_account_request(const UserAccount& user_account)
{
    request_account.push_back(user_account);
    cout << "   Account creation request submitted successfully. Please wait for approval." << endl;
}
