#include "../include/Customer.h"

Customer::Customer(int id,
                   const std::string& first,
                   const std::string& last)
{
    customerId = id;
    firstName = first;
    lastName = last;
}

int Customer::getId() const
{
    return customerId;
}

std::string Customer::getFullName() const
{
    return firstName + " " + lastName;
}
