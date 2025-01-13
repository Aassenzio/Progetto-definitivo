#include "gtest/gtest.h"
#include "Registro.h"


TEST(CercaConData, data){
    Registro registro;
    registro.addAttivita("Calcio",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Basket",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Pattinaggio",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    std::vector<Attivita*> listaTrovati;
    GiornoDelCalendario giornoDiRicerca(1,12,2000);
    EXPECT_EQ(3, registro.searchDate(giornoDiRicerca, &listaTrovati ));
}
