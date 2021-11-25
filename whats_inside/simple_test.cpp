// go into build directory of this target (check available sub-targets [make help] and preprocess it)
// [gtest_training/cmake-build-debug/whats_inside]$ make simple_test.i
// see whats inside

#include <gtest/gtest.h>

bool myfunction()
{
    return true;
}

TEST(SuperTest, a)
{
    EXPECT_TRUE(myfunction());
}
