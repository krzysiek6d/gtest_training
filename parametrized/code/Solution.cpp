#include "Solution.h"

Solution::Solution(Database& db) : db{db}
{
    db.connect();
}

std::string Solution::fizzbuzz(int num)
{
    auto [fizz, buzz] = db.getFizzBuzzEntry();
    if (num % fizz == 0 && num % buzz == 0)
        return "fizz buzz";
    if (num % fizz == 0)
        return  "fizz";
    if (num % buzz == 0)
        return "buzz";
    return std::to_string(num);
}