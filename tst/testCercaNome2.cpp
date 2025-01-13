#include "gtest/gtest.h"
#include "Registro.h"


TEST(CercaConNome, piu){
    Registro registro;
    registro.addAttivita("Calcio",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Calcio",GiornoDelCalendario(1,10,2000),"No",Orario(12,11),Orario(13,10));
    std::vector<Attivita*> listaTrovati;

    EXPECT_EQ(2, registro.searchName("Calcio", &listaTrovati ));
}