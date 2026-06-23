#include <iostream>
#include <vector>

#include "../include/Account.h"

using namespace std;

int main()
{
    vector<Account> accounts;

    int choice;

    do
    {
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Create account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show accounts\n";
        cout << "5. Exit\n";

        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int id;
                int customerId;

                cout << "Account ID: ";
                cin >> id;

                cout << "Customer ID: ";
                cin >> customerId;

                accounts.emplace_back(id,
                                      customerId,
                                      0.0,
                                      "EUR");

                break;
            }

            case 2:
            {
                int id;
                double amount;

                cout << "Account ID: ";
                cin >> id;

                cout << "Amount: ";
                cin >> amount;

                for(auto& account : accounts)
                {
                    if(account.getAccountId() == id)
                        account.deposit(amount);
                }

                break;
            }

            case 3:
            {
                int id;
                double amount;

                cout << "Account ID: ";
                cin >> id;

                cout << "Amount: ";
                cin >> amount;

                for(auto& account : accounts)
                {
                    if(account.getAccountId() == id)
                    {
                        if(account.withdraw(amount))
                            cout << "Success\n";
                        else
                            cout << "Insufficient funds\n";
                    }
                }

                break;
            }

            case 4:
            {
                for(const auto& account : accounts)
                {
                    cout << "Account: "
                         << account.getAccountId()
                         << " Balance: "
                         << account.getBalance()
                         << " EUR\n";
                }

                break;
            }

        }

    } while(choice != 5);

    return 0;
}
