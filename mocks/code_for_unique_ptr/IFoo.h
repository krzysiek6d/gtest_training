#pragma once

#include <memory>

class IFoo
{
public:
    virtual void sink(std::unique_ptr<int> ptr) = 0;
    virtual std::unique_ptr<int> getPtr() = 0;
    virtual ~IFoo() = default;
};