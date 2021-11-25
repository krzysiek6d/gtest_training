add_executable(go_to_parametrized
        00_version_with_multiple_single_tests.cpp
        01_version_with_fixture.cpp
        02_version_with_3_5_and_2_3_in_one_fixture.cpp
        03_version_with_3_5_and_2_3_in_two_fixtures.cpp
        04_parametrized.cpp
        05_parametrized_derived.cpp
        code/Solution.cpp
        code/Database.cpp)
target_link_libraries(go_to_parametrized gtest_main gmock)
add_test(go_to_parametrized go_to_parametrized)