cmake_minimum_required(VERSION 3.5)

project(clang_test)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libstdc++")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(clang_exe
    src/main.cpp
)
