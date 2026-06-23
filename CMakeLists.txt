cmake_minimum_required(VERSION 3.20)

project(BankCoreCPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(
        include
        ${PQXX_INCLUDE_DIRS}
)

add_executable(
        BankCoreCPP

        src/main.cpp
        src/Account.cpp
        src/Customer.cpp
        src/Database.cpp
)

target_link_libraries(
        BankCoreCPP
        ${PQXX_LIBRARIES}
)

enable_testing()

find_package(GTest REQUIRED)

add_executable(
        BankTests

        tests/account_tests.cpp
        src/Account.cpp
)

target_link_libraries(
        BankTests
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(BankTests)
