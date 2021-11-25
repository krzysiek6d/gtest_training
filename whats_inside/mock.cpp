// go into build directory of this target (check available sub-targets [make help] and preprocess it)
// [gtest_training/cmake-build-debug/whats_inside]$ make mock.i
// see whats inside
// explore created FunctionMocker in gmock sources
//     mutable ::testing::FunctionMocker<::testing::internal::identity_t<
//            void()
//    >> gmock10_foo_13;

#include <gmock/gmock.h>

struct MyMock
{
    MOCK_CONST_METHOD0(foo, void());
};
