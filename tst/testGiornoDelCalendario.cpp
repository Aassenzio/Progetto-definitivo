#include "gtest/gtest.h"
#include "GiornoDelCalendario.h"

TEST(GiornoDelCalendario , Bisestile){

    EXPECT_EQ(true, GiornoDelCalendario::isBisestile(2000) );
}

TEST(GiornoDelCalendario , NonBisestile){

    EXPECT_EQ(false, GiornoDelCalendario::isBisestile(1900) );
}

TEST(GiornoDelCalendario , ComparaDateDiverse){
    GiornoDelCalendario dataTest(1 , 11, 1901);
    GiornoDelCalendario dataTest1(11 , 1, 1901);
    EXPECT_EQ(false, dataTest==dataTest1);
}

TEST(GiornoDelCalendario , ComparaDateUguali){
    GiornoDelCalendario dataTest(11 , 11, 1901);
    GiornoDelCalendario dataTest1(11 , 11, 1901);
    EXPECT_EQ(true, dataTest==dataTest1);
}

TEST(GiornoDelCalendario , EccezioneFebbraio31giorni){
    EXPECT_THROW(GiornoDelCalendario(31, 2, 2000), std::invalid_argument);
}

TEST(GiornoDelCalendario , EccezioneMese32Giorni){
    EXPECT_THROW(GiornoDelCalendario(32,1, 2000), std::invalid_argument);
}

TEST(GiornoDelCalendario , EccezioneFebbraioNonBisestile){
    EXPECT_THROW(GiornoDelCalendario(29,2, 2003), std::invalid_argument);
}