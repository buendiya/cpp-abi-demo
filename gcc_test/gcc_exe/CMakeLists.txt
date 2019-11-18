cmake_minimum_required(VERSION 3.5)

project(gcc_exe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -D_GLIBCXX_USE_CXX11_ABI=0")


add_library(gcc_library SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(gcc_library PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../gcc_lib/build/libgcc_library.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../gcc_lib/include"
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(gcc_exe
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( gcc_exe
    PRIVATE 
    gcc_library
)
