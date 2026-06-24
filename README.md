# BankCoreCPP

BankCoreCPP is a console banking system written in C++20 with PostgreSQL support.

## Features

* User registration and authentication
* Creating bank accounts
* Depositing and withdrawing money
* Money transfers between accounts
* Transaction history storage
* PostgreSQL database integration

## Technologies

* C++20
* PostgreSQL
* libpqxx
* CMake
* Git

## Project Structure

src/ - source code

include/ - header files

database/ - database layer

services/ - business logic

## Build

```bash
git clone https://github.com/Burevistvishezor/BankCoreCPP.git
cd BankCoreCPP

mkdir build
cd build

cmake ..
cmake --build .
```

## Database

Create the database and execute:

```sql
psql -U postgres -d bankdb -f schema.sql
```

## Future Improvements

* Unit tests (GoogleTest)
* REST API
* Docker support
* CI/CD with GitHub Actions

## Author

Kamil Aliev
C++ / Python Backend Developer
