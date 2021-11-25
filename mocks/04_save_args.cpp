#include <gtest/gtest.h>
#include "DatabaseMock.h"
#include <code2/UsefulClass.h>


TEST(save_args, expect_function_args_good)
{
    DatabaseMock mock;
    UsefulClass sut{mock};

    EXPECT_CALL(mock, setFizzBuzzEntry(3, 5));
    sut.saveInDb();
}

TEST(save_args, save)
{
    DatabaseMock mock;
    UsefulClass sut{mock};

    int arg1;
    int arg2;

    EXPECT_CALL(mock, setFizzBuzzEntry(::testing::_, ::testing::_))
        .WillOnce(
                ::testing::DoAll(
                        ::testing::SaveArg<0>(&arg1),
                        ::testing::SaveArg<1>(&arg2)));
    sut.saveInDb();

    EXPECT_EQ(3, arg1);
    EXPECT_EQ(5, arg2);
}