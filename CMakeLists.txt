cmake_minimum_required(VERSION 3.27)
project(ProgettoDefinitivo)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories(include)

add_subdirectory(lib/GoogleTests)
add_subdirectory(tst)
add_subdirectory(src)