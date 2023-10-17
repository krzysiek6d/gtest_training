add_executable(output_to_files
        gmain.cpp
        RedirectOutput.cpp
        SomeTest.cpp)
target_include_directories(output_to_files PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(output_to_files gtest)
add_test(output_to_files output_to_files)