#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <string>
#include <vector>

#include "Account.h"

using namespace std;

enum status { ACTIVE, SUSPENDED, CLOSED, PENDING_APPROVAL };

class UserAccount : public Account
{
    public:
        // constructor
        UserAccount();

        // setters and getters for user account specific attributes
        void set_account_balance(double balance);
        double get_account_balance() const;
        void set_account_status(status new_status);
        status get_account_status() const;
        void set_account_address(const string& address);
        string get_account_address() const;

        // Additional methods for user account operations
        void deposit();
        void withdraw();
        void transfer(UserAccount& recipient, double amount);
        void transaction_history() const;
        void notification();
        bool balance_validation(double amount) const;

    private:
        double account_balance;
        status account_status;
        string account_address;
        vector<string> notifications;
};

#endif // USERACCOUNT_H