#include <gtest/gtest.h>
#include "DatabaseMock.h"
#include <code2/UsefulClass.h>


TEST(invoke, invoke)
{
    DatabaseMock mock;
    UsefulClass sut{mock};


    EXPECT_CALL(mock, setFizzBuzzEntry(::testing::_, ::testing::_))
            .WillOnce(::testing::Invoke([](auto arg1, auto arg2)
                                        {
                                            // do some job there
                                            std::cout << "debug print" << std::endl;
                                        }));
    sut.saveInDb();
}