cmake_minimum_required(VERSION 3.5)

project(gcc_library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libc++")

############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(gcc_library SHARED 
    src/Hello.cpp
)
add_library(hello::library ALIAS gcc_library)

target_include_directories(gcc_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
# add_executable(hello_binary
#     src/main.cpp
# )

# link the new hello_library target with the hello_binary target
# target_link_libraries( hello_binary
#     PRIVATE 
#         hello::library
# )
