#include "../include/Database.h"

int main()
{
    Database db(
        "dbname=bankdb "
        "user=postgres "
        "password=postgres "
        "host=localhost "
        "port=5432");

    if(!db.isConnected())
        return 1;

    db.createCustomer(
        "Kamil",
        "Aliev",
        "AB123456",
        "+79991234567",
        "kamil@mail.com");

    db.showCustomers();

    db.createAccount(
        1,
        "DE1000000003",
        10000.0);

    db.showAccounts();

    db.transferMoney(1, 2, 500);

    return 0;
}
