add_executable(matchers
        00_matchers.cpp
        01_matchers_with_mocks.cpp
        02_matcher_obects.cpp)
target_include_directories(matchers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(matchers gtest_main gmock)
add_test(matchers matchers)