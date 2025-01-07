#include "gtest/gtest.h"
#include "GiornoDelCalendario.h"

TEST(ComparaData, Data){
    GiornoDelCalendario dataTest(1 , 11, 1900);
    GiornoDelCalendario dataTest1(1, 11, 1900);
    EXPECT_EQ(true , dataTest.comparaData(dataTest1) );
}

