#pragma once

#include <utility>

class IDatabase {
public:
    virtual void connect() = 0;
    virtual void setFizzBuzzEntry(int fizz, int buzz) = 0;
    [[nodiscard]] virtual std::pair<int, int> getFizzBuzzEntry() const = 0;
    virtual ~IDatabase() = default;
};