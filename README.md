# BankCoreCPP
# BankCoreCPP

A simplified Core Banking System written in C++20 and PostgreSQL.

## Features

* Customer management
* Account creation and closure
* Deposit and withdrawal operations
* Money transfers between accounts
* Transaction history
* ACID database transactions
* Authentication and authorization
* Audit logging
* Multi-threaded transaction processing

## Technologies

* C++20
* PostgreSQL
* libpqxx
* CMake
* Git
* Linux
* Docker
* GoogleTest

## Project Structure

BankCoreCPP/

├── CMakeLists.txt

├── README.md

├── src/

│   ├── main.cpp

│   ├── BankSystem.cpp

│   ├── AccountService.cpp

│   ├── CustomerService.cpp

│   ├── TransferService.cpp

│   ├── AuthService.cpp

│   └── Database.cpp

├── include/

│   ├── Account.h

│   ├── Customer.h

│   ├── Transaction.h

│   └── Database.h

├── database/

│   └── schema.sql

├── tests/

│   └── account_tests.cpp

├── docs/

│   └── architecture.md

└── docker/

```
└── docker-compose.yml
```

## Database Tables

### customers

* customer_id
* first_name
* last_name
* passport_number
* created_at

### accounts

* account_id
* customer_id
* balance
* currency
* status

### transactions

* transaction_id
* from_account
* to_account
* amount
* operation_type
* created_at

### audit_log

* id
* user_name
* operation
* event_time

## Supported Operations

1. Create customer.
2. Open account.
3. Deposit money.
4. Withdraw money.
5. Transfer money.
6. Print account statement.
7. View transaction history.
8. Close account.

Example:

1 - Create customer

2 - Open account

3 - Deposit

4 - Withdraw

5 - Transfer

6 - Show balance

7 - Transaction history

8 - Exit

## Example Transfer

Source account: 10001

Destination account: 10002

Amount: 500 EUR

Transfer completed successfully.

## Example SQL Transaction

BEGIN;

UPDATE accounts
SET balance = balance - 500
WHERE account_id = 10001;

UPDATE accounts
SET balance = balance + 500
WHERE account_id = 10002;

INSERT INTO transactions(...);

COMMIT;
# BankCoreCPP

Simplified Core Banking System written in C++20.

## Features

- Customer management
- Account management
- Money transfers
- PostgreSQL integration
- Transaction history
- Audit logging
- Docker support
- Unit testing with GoogleTest

## Technology Stack

- C++20
- PostgreSQL
- libpqxx
- Docker
- GoogleTest
- CMake

## Build

```bash
mkdir build
cd build

cmake ..
make
