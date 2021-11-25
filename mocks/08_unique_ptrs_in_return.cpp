#include <gmock/gmock.h>
#include <code_for_unique_ptr/IFoo.h>
#include <code_for_unique_ptr/FooUser.h>

namespace {
    struct FooMock : public IFoo {
        void sink(std::unique_ptr<int> ptr)
        {
            sinkProxy(*ptr);
        }
        MOCK_METHOD1(sinkProxy, void(int));
        MOCK_METHOD0(getPtr, std::unique_ptr<int>()); // this will be changed in 09
    };
}

//TEST(unique_ptrs_in_return, unique)
//{
//    FooMock mock;
//    FooUser user{mock};
//    EXPECT_CALL(mock, getPtr()).WillOnce(::testing::Return(std::make_unique<int>(5)));
//    user.sum5AndValueFromFoo();
//}

TEST(unique_ptrs_in_return, unique_solution_by_move)
{
    FooMock mock;
    FooUser user{mock};
    EXPECT_CALL(mock, getPtr()).WillOnce(::testing::Return(::testing::ByMove(std::make_unique<int>(5))));
    EXPECT_EQ(5+5, user.sum5AndValueFromFoo());
}