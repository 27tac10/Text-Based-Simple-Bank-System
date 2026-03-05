#ifndef BANK_H
#define BANK_H

#include "MasterAccount.h"
#include "UserAccount.h"

using namespace std;

class Bank
{
    public:
        Bank();
        ~Bank();
        void run();
        void user_login();
        void master_login();
        void create_user_account();

    private:
        MasterAccount master;
        vector<UserAccount> users;
        //TransactionManager*
        //AuthenticationManager*
        //NotificationSystem*
};

#endif