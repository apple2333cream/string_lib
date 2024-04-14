cmake_minimum_required(VERSION 3.10)
project(string_lib)

set(CMAKE_CXX_STANDARD 17)
if(WIN32)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
endif()
file(GLOB STRING_SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
add_executable(string_lib ${STRING_SOURCES})

target_link_libraries(string_lib)
