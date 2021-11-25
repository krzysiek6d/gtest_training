#include "Database.h"
#include <stdexcept>

void Database::connect()
{

}

void Database::setFizzBuzzEntry(int fizz, int buzz)
{
    fizzBuzzEntry = std::make_pair(fizz, buzz);
}

std::pair<int, int> Database::getFizzBuzzEntry() const
{
    if (!fizzBuzzEntry.has_value())
        throw std::runtime_error("fizzbuzz entry not found in db");
    return *fizzBuzzEntry;
}
