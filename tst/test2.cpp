#include "gtest/gtest.h"
#include "GiornoDelCalendario.h"

TEST(ComparaData2, Data){
    GiornoDelCalendario dataTest(1 , 11, 1901);
    GiornoDelCalendario dataTest1(11 , 1, 1901);
    EXPECT_EQ(false, dataTest==dataTest1);
}



