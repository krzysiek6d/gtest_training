#include <gtest/gtest.h>
#include "code/Solution.h"
#include "code/Database.h"

TEST(mocks, no_mock)
{
    auto db = Database{};
    Solution s{db};

    db.setFizzBuzzEntry(3, 5);

    EXPECT_EQ("fizz", s.fizzbuzz(3));
}
