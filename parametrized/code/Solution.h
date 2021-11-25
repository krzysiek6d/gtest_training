#pragma once

#include <string>
#include "Database.h"

class Solution {
public:
    explicit Solution(Database& db);
    std::string fizzbuzz(int num);
private:
    Database& db;
};