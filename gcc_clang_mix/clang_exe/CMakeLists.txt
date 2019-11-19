cmake_minimum_required(VERSION 3.5)

project(clang_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libc++")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libstdc++")


add_library(gcc_library SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(gcc_library PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../gcc_lib/build/libgcc_library.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../gcc_lib/include"
)


add_library(gcc_library_2 SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(gcc_library_2 PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../gcc_lib_2/build/libgcc_library_2.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../gcc_lib_2/include"
)


add_library(clang_library SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(clang_library PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../clang_lib/build/libclang_library.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../clang_lib/include"
)


add_library(clang_library_2 SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(clang_library_2 PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../clang_lib_2/build/libclang_library_2.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../clang_lib_2/include"
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(clang_exe
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( clang_exe
    PRIVATE 
    gcc_library
    gcc_library_2
    clang_library
    clang_library_2
)
