set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_executable(ProgettoDefinitivo main.cpp
        orario.cpp
        finestra.cpp
        app.cpp
        data.cpp
        Utility.cpp
)

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(ProgettoDefinitivo ${wxWidgets_LIBRARIES})