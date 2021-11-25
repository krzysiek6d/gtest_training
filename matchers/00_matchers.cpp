#include <gtest/gtest.h>
#include <gmock/gmock.h>


// see https://github.com/google/googletest/blob/main/docs/reference/matchers.md

MATCHER(IsEven, "")
{
    return (arg % 2) == 0;
}

TEST(matcher00, iseven)
{
    EXPECT_THAT(0, IsEven());
}

MATCHER_P2(IsBetween, low, high ,
           std::string("is between [") + std::to_string(low) + ", " + std::to_string(high) + "]")
{
    return low < arg && high > arg;
}

TEST(matcher00, between)  // try to fail it to see fail msg
{
    EXPECT_THAT(7, IsBetween(4, 9));
}

TEST(matcher00, vect)
{
    std::vector<int> v{1, 2, 4};
    EXPECT_THAT(v, ::testing::SizeIs(3));
}

TEST(matcher00, str)
{
    std::string text = "hello my beautiful world";
    EXPECT_THAT(text, ::testing::HasSubstr("beautiful"));
}