#pragma once

#include <memory>
#include <string>
#include <pqxx/pqxx>

class Database
{
private:
    std::unique_ptr<pqxx::connection> connection;

public:
    Database(const std::string& connectionString);

    bool isConnected() const;

    void createCustomer(const std::string& firstName,
                        const std::string& lastName,
                        const std::string& passport,
                        const std::string& phone,
                        const std::string& email);

    void showCustomers();

    void createAccount(int customerId,
                       const std::string& accountNumber,
                       double balance);

    void showAccounts();

    bool transferMoney(int fromAccount,
                       int toAccount,
                       double amount);
};
