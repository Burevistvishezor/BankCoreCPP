#pragma once

#include <string>

class Customer
{
private:
    int customerId;
    std::string firstName;
    std::string lastName;

public:
    Customer(int id,
             const std::string& first,
             const std::string& last);

    int getId() const;
    std::string getFullName() const;
};
