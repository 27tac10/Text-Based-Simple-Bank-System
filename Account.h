#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;


class Account
{
    public:
        Account();
        void set_account_name(const string& name);
        string get_account_name() const;
        void set_account_id(const string& id);
        string get_account_id() const;
        void set_account_password(const string& password);
        string get_account_password() const;
        void set_account_phone_number(const string& phone_number);
        string get_account_phone_number() const;
        void set_account_email(const string& email);
        string get_account_email() const;
    protected:
        string account_name;
        string account_id;
        string account_password;
        string account_phone_number;
        string account_email;
};

#endif // ACCOUNT_H