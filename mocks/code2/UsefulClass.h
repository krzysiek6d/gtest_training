#pragma once

#include <code/IDatabase.h>

class UsefulClass
{
public:
    UsefulClass(IDatabase& db) : db{db}
    {
    }
    void saveInDb()
    {
        db.setFizzBuzzEntry(3, 5);
    }
    IDatabase& db;
};
