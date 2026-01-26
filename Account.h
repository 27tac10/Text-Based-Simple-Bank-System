#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
    public:
        Account(string name = "Unknown", string number = "-999", double initial_balance = 0.0, string pwd = "password");
        void deposit(double amount);
        void withdraw(double amount);
        double get_balance() const;
        string get_account_name() const;
        string get_account_number() const;
        string get_password() const;
    private:
        string account_name;
        string account_number;
        double balance;
        string password;
};

#endif // ACCOUNT_H