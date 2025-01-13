set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES}
        test1.cpp
        ../include/Orario.h
        ../include/FinestraPrincipale.h
        ../include/app.h
        ../include/Attivita.h
        ../include/Registro.h
        ../include/FinestraVisualizzaGriglia.h
        ../include/FinestraDiAggiunta.h
        ../include/GiornoDelCalendario.h
        test2.cpp
        test3.cpp
        test3.cpp
        test4.cpp

)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
