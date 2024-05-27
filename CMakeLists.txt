cmake_minimum_required(VERSION 3.27)
project(ProgettoDefinitivo)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories(include)


set(CMAKE_PREFIX_PATH "D:/librerie/wxWid/wxWidgets")
find_package(wxWidgets REQUIRED COMPONENTS gl net core base)
include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})

add_subdirectory(lib/GoogleTests)
add_subdirectory(tst)
add_subdirectory(src)




