#pragma once

#include <memory>
#include "IDatabase.h"

std::unique_ptr<IDatabase> createDb();