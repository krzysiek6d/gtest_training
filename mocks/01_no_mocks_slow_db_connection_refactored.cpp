#include <gtest/gtest.h>
#include "code/Solution.h"
#include "code/DatabaseFactory.h"

TEST(mocks, no_mock_db_interface)
{
    auto db = createDb();
    Solution s{*db};

    db->setFizzBuzzEntry(3, 5);

    EXPECT_EQ("fizz", s.fizzbuzz(3));
}
