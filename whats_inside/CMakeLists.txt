add_executable(whats_inside simple_test.cpp mock.cpp)
target_link_libraries(whats_inside gtest_main gmock)
add_test(whats_inside whats_inside)