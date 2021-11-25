#include "Database.h"
#include <stdexcept>
#include <thread>
#include <chrono>

void Database::connect()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
}

void Database::setFizzBuzzEntry(int fizz, int buzz)
{
    fizzBuzzEntry = std::make_pair(fizz, buzz);
}

std::pair<int, int> Database::getFizzBuzzEntry() const
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    if (!fizzBuzzEntry.has_value())
        throw std::runtime_error("fizzbuzz entry not found in db");
    return *fizzBuzzEntry;
}
