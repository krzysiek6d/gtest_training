#pragma once

#include <string>
#include "IDatabase.h"

class Solution {
public:
    Solution(IDatabase& db);
    std::string fizzbuzz(int num);
private:
    IDatabase& db;
};