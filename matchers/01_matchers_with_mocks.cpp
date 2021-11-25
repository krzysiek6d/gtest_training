#include <gmock/gmock.h>

using namespace ::testing;
struct MyMock
{
    MOCK_METHOD1(foo, void(int));
};


TEST(matchers_with_mocks, t1)
{
    MyMock mock;

    EXPECT_CALL(mock, foo(AllOf(Ge(3), Le(10))));

    // normally this would be called by SUT
    mock.foo(7);
}