set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES}
        test1.cpp
        ../include/orario.h
        ../include/finestra.h
        ../include/app.h
        ../include/Data.h
        ../include/Utility.h
        ../include/Attivita.h
        ../include/Registro.h
        ../include/FinestraDiModifica.h

)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
