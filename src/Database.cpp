#include "../include/Database.h"

#include <iostream>
#include <stdexcept>

Database::Database(const std::string& connectionString)
{
    try
    {
        connection =
            std::make_unique<pqxx::connection>(connectionString);

        if(connection->is_open())
        {
            std::cout << "Connected to PostgreSQL\n";
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

bool Database::isConnected() const
{
    return connection && connection->is_open();
}

void Database::createCustomer(const std::string& firstName,
                              const std::string& lastName,
                              const std::string& passport,
                              const std::string& phone,
                              const std::string& email)
{
    try
    {
        pqxx::work txn(*connection);

        txn.exec_params(
            "INSERT INTO customers "
            "(first_name,last_name,passport_number,phone,email) "
            "VALUES($1,$2,$3,$4,$5)",

            firstName,
            lastName,
            passport,
            phone,
            email);

        txn.commit();

        std::cout << "Customer created\n";
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Database::showCustomers()
{
    try
    {
        pqxx::work txn(*connection);

        pqxx::result result =
            txn.exec(
                "SELECT customer_id,"
                "first_name,"
                "last_name "
                "FROM customers");

        for(const auto& row : result)
        {
            std::cout
                << "ID: "
                << row["customer_id"].as<int>()
                << " Name: "
                << row["first_name"].c_str()
                << " "
                << row["last_name"].c_str()
                << '\n';
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Database::createAccount(int customerId,
                             const std::string& accountNumber,
                             double balance)
{
    try
    {
        pqxx::work txn(*connection);

        txn.exec_params(
            "INSERT INTO accounts "
            "(customer_id,account_number,balance) "
            "VALUES($1,$2,$3)",

            customerId,
            accountNumber,
            balance);

        txn.commit();

        std::cout << "Account created\n";
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Database::showAccounts()
{
    try
    {
        pqxx::work txn(*connection);

        pqxx::result result =
            txn.exec(
                "SELECT account_id,"
                "account_number,"
                "balance "
                "FROM accounts");

        for(const auto& row : result)
        {
            std::cout
                << "ID: "
                << row["account_id"].as<int>()
                << " Account: "
                << row["account_number"].c_str()
                << " Balance: "
                << row["balance"].as<double>()
                << '\n';
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

bool Database::transferMoney(int fromAccount,
                             int toAccount,
                             double amount)
{
    try
    {
        pqxx::work txn(*connection);

        double senderBalance =
            txn.query_value<double>(
                "SELECT balance "
                "FROM accounts "
                "WHERE account_id = "
                + txn.quote(fromAccount));

        if(senderBalance < amount)
        {
            std::cout << "Insufficient funds\n";
            return false;
        }

        txn.exec(
            "UPDATE accounts "
            "SET balance = balance - "
            + txn.quote(amount)
            + " WHERE account_id = "
            + txn.quote(fromAccount));

        txn.exec(
            "UPDATE accounts "
            "SET balance = balance + "
            + txn.quote(amount)
            + " WHERE account_id = "
            + txn.quote(toAccount));

        txn.exec_params(
            "INSERT INTO transactions "
            "(from_account,to_account,amount,operation_type)"
            "VALUES($1,$2,$3,'TRANSFER')",

            fromAccount,
            toAccount,
            amount);

        txn.commit();

        std::cout << "Transfer completed\n";

        return true;
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return false;
    }
}
