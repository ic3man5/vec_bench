cmake_minimum_required(VERSION 3.25)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(vec_bench)
add_executable(vec_bench src/main.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(vec_bench benchmark::benchmark)
