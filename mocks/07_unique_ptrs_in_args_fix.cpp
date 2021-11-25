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
        MOCK_METHOD0(getPtr, std::unique_ptr<int>()); // this will be discussed in 08, 09
    };
}

TEST(unique_ptrs_in_args_fix, unique_with_value)
{
    FooMock mock;
    FooUser user{mock};

    EXPECT_CALL(mock, sinkProxy(3+3));
    user.saveSumOf3AndValInFoo(3);
}

