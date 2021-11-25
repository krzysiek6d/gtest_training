#include <gtest/gtest.h>
#include "code/Solution.h"

class FizzBuzzTest : public ::testing::TestWithParam<std::tuple<int, int, int, std::string>>
{
public:
    FizzBuzzTest() : db{}, s{db}
    {
    }
    Database db;
    Solution s;
};

TEST_P(FizzBuzzTest, checkString)
{
    auto [fizz, buzz, value, expectedStr] = GetParam();
    db.setFizzBuzzEntry(fizz, buzz);
    EXPECT_EQ(expectedStr, s.fizzbuzz(value));
}

INSTANTIATE_TEST_CASE_P(
        fizbuzzTests,
        FizzBuzzTest,
        ::testing::Values(
                std::make_tuple(3, 5, 1, "1"),
                std::make_tuple(3, 5, 2, "2"),
                std::make_tuple(3, 5, 3, "fizz"),
                std::make_tuple(3, 5, 4, "4"),
                std::make_tuple(3, 5, 5, "buzz"),
                std::make_tuple(3, 5, 15, "fizz buzz")
                ));