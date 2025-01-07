#include "gtest/gtest.h"
//#include "Utility.h"
#include "GiornoDelCalendario.h"
/*TEST(CompattaTreNumeri, utility) {
    EXPECT_EQ(191718, CompattaData(19, 17, 18));
}*/
TEST(ComparaData, Data){
    GiornoDelCalendario dataTest(1 , 11, 1900);
    GiornoDelCalendario dataTest1(1, 11, 1900);
    EXPECT_EQ(true , dataTest.ComparaData(dataTest1) );
}

