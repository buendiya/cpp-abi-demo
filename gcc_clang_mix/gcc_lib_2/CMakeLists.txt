cmake_minimum_required(VERSION 3.5)

project(gcc_library_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libc++")

############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(gcc_library_2 SHARED 
    src/Hello.cpp
)

target_include_directories(gcc_library_2
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
