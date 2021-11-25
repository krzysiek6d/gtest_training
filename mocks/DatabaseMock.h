#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "code/IDatabase.h"

struct DatabaseMock : public IDatabase
{
    MOCK_METHOD0(connect, void());
    MOCK_METHOD2(setFizzBuzzEntry, void(int, int));
    MOCK_CONST_METHOD0(getFizzBuzzEntry, std::pair<int, int>());
};
