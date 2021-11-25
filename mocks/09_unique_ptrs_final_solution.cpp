#include <gmock/gmock.h>
#include <code_for_unique_ptr/IFoo.h>
#include <code_for_unique_ptr/FooUser.h>

namespace {
    struct FooMock : public IFoo {
        void sink(std::unique_ptr<int> ptr)
        {
            sinkProxy(*ptr);
        }
        std::unique_ptr<int> getPtr() // see 08 for alternative solution
        {
            return std::make_unique<int>(getPtrProxy());
        }
        MOCK_METHOD1(sinkProxy, void(int));
        MOCK_METHOD0(getPtrProxy, int());
    };
}

TEST(unique_ptrs_in_return_final, solution)
{
    FooMock mock;
    FooUser user{mock};
    EXPECT_CALL(mock, getPtrProxy()).WillOnce(::testing::Return(5));
    EXPECT_EQ(5+5, user.sum5AndValueFromFoo());
}
