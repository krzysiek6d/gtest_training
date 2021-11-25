#include <gtest/gtest.h>
#include "code/Solution.h"

class FizzBuzzTesting : public ::testing::Test
{
public:
    FizzBuzzTesting() : db{}, s{db}
    {
    }
    Database db;
    Solution s;
};

class FizzBuzzTestParam : public FizzBuzzTesting, public ::testing::WithParamInterface<std::tuple<int, int, int, std::string>>
{
};

TEST_P(FizzBuzzTestParam, checkString)
{
    auto [fizz, buzz, value, expectedStr] = GetParam();
    db.setFizzBuzzEntry(fizz, buzz);
    EXPECT_EQ(expectedStr, s.fizzbuzz(value));
}

INSTANTIATE_TEST_CASE_P(
        fizbuzzTests,
        FizzBuzzTestParam,
        ::testing::Values(
                std::make_tuple(3, 5, 1, "1"),
                std::make_tuple(3, 5, 2, "2"),
                std::make_tuple(3, 5, 3, "fizz"),
                std::make_tuple(3, 5, 4, "4"),
                std::make_tuple(3, 5, 5, "buzz"),
                std::make_tuple(3, 5, 15, "fizz buzz")
        ));