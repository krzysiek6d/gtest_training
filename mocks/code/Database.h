#pragma once

#include <optional>
#include "IDatabase.h"

class Database : public IDatabase
{
public:
    void connect() override;
    void setFizzBuzzEntry(int fizz, int buzz) override;
    [[nodiscard]] std::pair<int, int> getFizzBuzzEntry() const override;

private:
    std::optional<std::pair<int, int>> fizzBuzzEntry;
};
