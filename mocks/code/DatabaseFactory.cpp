#include "DatabaseFactory.h"
#include "Database.h"

std::unique_ptr<IDatabase> createDb()
{
    return std::make_unique<Database>();
}