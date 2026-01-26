#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include "Account.h"
#include "Bank_Manager.h"

class Bank_System
{
    public:
        Bank_System();
        Bank_System(string file);
        bool Add_Account(const string name, string number, double initial_balance, string pwd);
        void run(const string name, string number, string pwd);
        void login();
        void create_account();
        bool verify_account(const string name, string number, const string pwd);
    private:
        //Bank_Manager manager;
        //Account* current_account;
        Account accounts[100];
        int account_count;
        int current_account_index;
        string last_account_number;
};

#endif // BANK_SYSTEM_H