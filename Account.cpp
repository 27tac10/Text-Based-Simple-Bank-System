#include <string>

#include "Account.h"

using namespace std;

Account::Account()
{
    account_name = "";
    account_id = "";
    account_password = "";
    account_phone_number = "";
    account_email = "";
}

void Account::set_account_name(const string& name)
{
    account_name = name;
}

string Account::get_account_name() const
{
    return account_name;
}

void Account::set_account_id(const string& id)
{
    account_id = id;
}

string Account::get_account_id() const
{
    return account_id;
}

void Account::set_account_password(const string& password)
{
    account_password = password;
}

string Account::get_account_password() const
{
    return account_password;
}

void Account::set_account_phone_number(const string& phone_number)
{
    account_phone_number = phone_number;
}

string Account::get_account_phone_number() const
{
    return account_phone_number;
}

void Account::set_account_email(const string& email)
{
    account_email = email;
}

string Account::get_account_email() const
{
    return account_email;
}
