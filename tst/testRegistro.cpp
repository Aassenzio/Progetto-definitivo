#include "gtest/gtest.h"
#include "Registro.h"


TEST(Registro, CercaConData){
    Registro registro;
    registro.addAttivita("Calcio",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Basket",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Pattinaggio",GiornoDelCalendario(1,12,2001),"No",Orario(12,11),Orario(13,10));
    GiornoDelCalendario giornoDiRicerca(1, 12, 2000);
    std::vector<Attivita*> risultati = registro.searchDate(giornoDiRicerca);

    ASSERT_EQ(risultati.size(), 2);

    EXPECT_EQ(*risultati[0], Attivita("Calcio", GiornoDelCalendario(1, 12, 2000), 0, "No", Orario(12, 11), Orario(13, 10)));
    EXPECT_EQ(*risultati[1], Attivita("Basket", GiornoDelCalendario(1, 12, 2000), 1, "No", Orario(12, 11), Orario(13, 10)));
}

TEST(Registro, CercaConNome){
    Registro registro;
    registro.addAttivita("Calcio",GiornoDelCalendario(1,12,2000),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Calcio",GiornoDelCalendario(1,12,2020),"No",Orario(12,11),Orario(13,10));
    registro.addAttivita("Pattinaggio",GiornoDelCalendario(1,12,2001),"No",Orario(12,11),Orario(13,10));

    std::vector<Attivita*> risultati = registro.searchName("Calcio");

    ASSERT_EQ(risultati.size(), 2);

    EXPECT_EQ(*risultati[0], Attivita("Calcio", GiornoDelCalendario(1, 12, 2000), 0, "No", Orario(12, 11), Orario(13, 10)));
    EXPECT_EQ(*risultati[1], Attivita("Calcio", GiornoDelCalendario(1, 12, 2020), 1, "No", Orario(12, 11), Orario(13, 10)));
}
