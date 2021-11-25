#include <gmock/gmock.h>
#include <code_for_unique_ptr/IFoo.h>
#include <code_for_unique_ptr/FooUser.h>

namespace {
    struct FooMock : public IFoo {
        MOCK_METHOD1(sink, void(std::unique_ptr<int>));
        MOCK_METHOD0(getPtr, std::unique_ptr<int>());
    };
}
TEST(unique_ptrs_in_args, unique)
{
    FooMock mock;
    FooUser user{mock};
    EXPECT_CALL(mock, sink(::testing::_));
    user.saveSumOf3AndValInFoo(3);
}

//TEST(unique_ptrs_in_args, unique_with_value_BAD)
//{
//    FooMock mock;
//    FooUser user{mock};
//    EXPECT_CALL(mock, sink(std::make_unique<int>(3 + 3)));
//    user.saveSumOf3AndValInFoo(3);
//}

//TEST(unique_ptrs_in_args, unique_with_value_save_arg_BAD)
//{
//    FooMock mock;
//    FooUser user{mock};
//    std::unique_ptr<int> storeValueHere;
//    EXPECT_CALL(mock, sink(::testing::_)).WillOnce(::testing::SaveArg<0>(&storeValueHere));
//    user.saveSumOf3AndValInFoo(3);
//}