set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES}
        testComparaDataTrue.cpp
        ../include/Orario.h
        ../include/FinestraPrincipale.h
        ../include/App.h
        ../include/Attivita.h
        ../include/Registro.h
        ../include/FinestraVisualizzaGriglia.h
        ../include/FinestraDiAggiunta.h
        ../include/GiornoDelCalendario.h
        testComparaData.cpp
        testBisestile.cpp
        testBisestile.cpp
        testCercaNome.cpp
        testCercaNome2.cpp
        testOrario.cpp
        testCercaData.cpp

)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
