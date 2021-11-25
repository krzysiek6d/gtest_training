add_executable(mocks
        00_no_mocks_slow_db_connection.cpp
        01_no_mocks_slow_db_connection_refactored.cpp
        02_what_is_mock.cpp
        03_db_mocked_strict_mock_nice_mock.cpp
        04_save_args.cpp
        05_invoke.cpp
        06_unique_ptrs_in_args.cpp
        07_unique_ptrs_in_args_fix.cpp
        08_unique_ptrs_in_return.cpp
        09_unique_ptrs_final_solution.cpp
        code/Solution.cpp
        code/Database.cpp
        code/DatabaseFactory.cpp
        code_for_unique_ptr/FooUser.cpp)
target_include_directories(mocks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mocks gtest_main gmock)
add_test(mocks mocks)