#include <gmock/gmock.h>

struct A
{
    MOCK_METHOD1(foo, void(int));
    // void foo(int)
};

TEST(what_is_mock, example)
{
    A a;
    EXPECT_CALL(a, foo(2));
    a.foo(2);
}