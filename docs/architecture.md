class Account
{
private:
    int accountId;
    double balance;
    std::string currency;

public:
    Account(int id,
            double bal,
            const std::string& curr);

    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};
examples of transactions:
class TransferService
{
public:
    bool transfer(int fromAccount,
                  int toAccount,
                  double amount);
};

commits:
Initial project structure

Implemented Customer entity

Added PostgreSQL connection layer

Implemented account operations

Implemented money transfer transaction

Added audit logging

Added unit tests

Dockerized PostgreSQL environment
