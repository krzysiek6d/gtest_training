#include "FooUser.h"

FooUser::FooUser(IFoo& foo) : foo{foo}
{}

void FooUser::saveSumOf3AndValInFoo(int val)
{
    foo.sink(std::make_unique<int>(val + 3));
}

int FooUser::sum5AndValueFromFoo()
{
    return 5 + *foo.getPtr();
}