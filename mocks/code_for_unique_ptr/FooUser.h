#pragma once

#include "IFoo.h"

class FooUser {
public:
    FooUser(IFoo& foo);

    void saveSumOf3AndValInFoo(int val);
    int sum5AndValueFromFoo();

    IFoo& foo;
};
