#include "gtest/gtest.h"
#include "Registro.h"


TEST(CercaConNome, nome){
    Registro registro;
    registro.addAttivita("Calcio",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    std::vector<Attivita*> listaTrovati;

    EXPECT_EQ(1, registro.searchName("Calcio", &listaTrovati ));
}
