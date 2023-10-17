cmake_minimum_required(VERSION 3.16)
project(gtest_training)

set(CMAKE_CXX_STANDARD 20)


# message(WARNING
#         "If your compiler cpp20, skip this warning :) \n"
#         "If your default compiler does not support cpp20, then set it: \n"
#         "CXX=\"path_to_gcc/g++\" cmake <PATH_TO_THIS_CMakeLists.txt> \n"
#         "CC=\"path_to_gcc/gcc\" cmake <PATH_TO_THIS_CMakeLists.txt>\n"
# )
# to avoid using LD_LIBRARY_PATH when building with external CC/CXX
# set(BUILD_SHARED_LIBS OFF)
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(parametrized)
add_subdirectory(whats_inside)
add_subdirectory(mocks)
add_subdirectory(matchers)
add_subdirectory(output_to_files)

