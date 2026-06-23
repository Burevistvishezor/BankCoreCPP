#pragma once

#include <string>

class Account
{
private:
    int accountId;
    int customerId;
    double balance;
    std::string currency;

public:
    Account(int accId,
            int custId,
            double bal,
            const std::string& curr);

    int getAccountId() const;
    int getCustomerId() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
};
