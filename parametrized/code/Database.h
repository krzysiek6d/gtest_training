#pragma once

#include <optional>
#include <utility>

class Database
{
public:
    void connect();
    void setFizzBuzzEntry(int fizz, int buzz);
    [[nodiscard]] std::pair<int, int> getFizzBuzzEntry() const;

private:
    std::optional<std::pair<int, int>> fizzBuzzEntry;
};
