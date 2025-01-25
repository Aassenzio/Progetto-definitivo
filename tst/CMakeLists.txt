set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES}
        ../include/Orario.h
        ../include/FinestraPrincipale.h
        ../include/App.h
        ../include/Attivita.h
        ../include/Registro.h
        ../include/FinestraVisualizzaGriglia.h
        ../include/FinestraDiAggiunta.h
        ../include/GiornoDelCalendario.h
        testGiornoDelCalendario.cpp
        testGiornoDelCalendario.cpp
        testOrario.cpp
        testRegistro.cpp
        testAttivita.cpp

)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
