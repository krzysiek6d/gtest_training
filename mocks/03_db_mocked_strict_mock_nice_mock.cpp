#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "code/Solution.h"
#include "DatabaseMock.h"

TEST(mock, db_is_mocked_on_call)
{
    DatabaseMock dbMock;
    Solution s{dbMock};

    ON_CALL(dbMock, getFizzBuzzEntry).WillByDefault(::testing::Return(std::make_pair(3, 5)));

    s.fizzbuzz(3);
}

TEST(mock, db_is_mocked_expect_call)
{
    DatabaseMock dbMock;
    Solution s{dbMock};

    EXPECT_CALL(dbMock, getFizzBuzzEntry).WillOnce(::testing::Return(std::make_pair(3, 5))).WillOnce(::testing::Return(std::make_pair(2, 3)));
    EXPECT_EQ("fizz", s.fizzbuzz(3));
    EXPECT_EQ("buzz", s.fizzbuzz(3));
}

TEST(mock, db_is_mocked_expect_call_nice_mock)
{
    ::testing::NiceMock<DatabaseMock> dbMock;
    Solution s{dbMock};

    EXPECT_CALL(dbMock, getFizzBuzzEntry).WillOnce(::testing::Return(std::make_pair(3, 5)));

    s.fizzbuzz(3);
}


// opportunity to have fun with VerifyAndClearExpectations
// https://github.com/google/googletest/blob/main/docs/gmock_cheat_sheet.md#verifying-and-resetting-a-mock
TEST(mock, db_is_mocked_expect_call_strict_mock)
{
    ::testing::StrictMock<DatabaseMock> dbMock;


    EXPECT_CALL(dbMock, connect); // note that it should be there, not after c-tor



    Solution s{dbMock};
    ::testing::Mock::VerifyAndClearExpectations(&dbMock);
    EXPECT_CALL(dbMock, getFizzBuzzEntry).WillOnce(::testing::Return(std::make_pair(3, 5)));

    s.fizzbuzz(3);
}