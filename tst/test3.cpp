#include "gtest/gtest.h"
#include "GiornoDelCalendario.h"

TEST(Bisestile, 2000){

    EXPECT_EQ(true, GiornoDelCalendario::isBisestile(2000) );
}


