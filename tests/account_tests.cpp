#include <gtest/gtest.h>

#include "../include/Account.h"

TEST(AccountTest, DepositMoney)
{
    Account account(1, 1, 1000.0, "EUR");

    account.deposit(500);

    EXPECT_DOUBLE_EQ(
            account.getBalance(),
            1500.0);
}

TEST(AccountTest, WithdrawMoney)
{
    Account account(1, 1, 1000.0, "EUR");

    bool result = account.withdraw(200);

    EXPECT_TRUE(result);

    EXPECT_DOUBLE_EQ(
            account.getBalance(),
            800.0);
}

TEST(AccountTest, WithdrawTooMuch)
{
    Account account(1, 1, 1000.0, "EUR");

    bool result = account.withdraw(5000);

    EXPECT_FALSE(result);

    EXPECT_DOUBLE_EQ(
            account.getBalance(),
            1000.0);
}

TEST(AccountTest, NegativeDeposit)
{
    Account account(1, 1, 1000.0, "EUR");

    account.deposit(-100);

    EXPECT_DOUBLE_EQ(
            account.getBalance(),
            1000.0);
}
