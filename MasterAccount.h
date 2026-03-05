#ifndef MASTERACCOUNT_H
#define MASTERACCOUNT_H

#include <string>
#include <vector>

#include "Account.h"
#include "UserAccount.h"

using namespace std;

class MasterAccount : public Account
{
    public:
        MasterAccount();
        void account_request();
        void approve_request(const string& account_id);
        void reject_request(const string& account_id);
        void view_all_accounts() const;
        void suspend_account(const string& account_id);
        void add_account_request(const UserAccount& user_account);
        // void send_notification(const string& message) const;
        
    private:
        vector<UserAccount> request_account;
};

#endif // MASTERACCOUNT_H