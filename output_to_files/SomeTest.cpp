#include <gtest/gtest.h>

#include <iostream>

TEST(stdout_to_file, test_01)
{
    std::cout << "some output" << std::endl;
}