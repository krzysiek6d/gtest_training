#include <gtest/gtest.h>
#include "code/Solution.h"

TEST(fizzbuzz_3_5_single_test, should_return_1_when_1_is_given)
{
    Database db;
    Solution s{db};
    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("1", s.fizzbuzz(1));
}

TEST(fizzbuzz_3_5_single_test, should_return_2_when_2_is_given)
{
    Database db;
    Solution s{db};
    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("2", s.fizzbuzz(2));
}

TEST(fizzbuzz_3_5_single_test, should_return_fizz_when_3_is_given)
{
    Database db;
    Solution s{db};
    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("fizz", s.fizzbuzz(3));
}

TEST(fizzbuzz_3_5_single_test, should_return_4_when_4_is_given)
{
    Database db;
    Solution s{db};
    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("4", s.fizzbuzz(4));
}

TEST(fizzbuzz_3_5_single_test, should_return_buzz_when_5_is_given)
{
    Database db;
    Solution s{db};
    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("buzz", s.fizzbuzz(5));
}

TEST(fizzbuzz_3_5_single_test, should_return_fizz_buzz_when_15_is_given)
{
    Database db;
    Solution s{db};
    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("fizz buzz", s.fizzbuzz(15));
}
