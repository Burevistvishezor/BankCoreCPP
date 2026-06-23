#include "../include/Account.h"

Account::Account(int accId,
                 int custId,
                 double bal,
                 const std::string& curr)
{
    accountId = accId;
    customerId = custId;
    balance = bal;
    currency = curr;
}

int Account::getAccountId() const
{
    return accountId;
}

int Account::getCustomerId() const
{
    return customerId;
}

double Account::getBalance() const
{
    return balance;
}

void Account::deposit(double amount)
{
    if (amount > 0)
        balance += amount;
}

bool Account::withdraw(double amount)
{
    if (amount > balance || amount <= 0)
        return false;

    balance -= amount;
    return true;
}
