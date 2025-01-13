#include "gtest/gtest.h"
#include "Orario.h"


TEST(Orario, operatore){
   Orario ora(11,11);
   Orario oraDopo(12,11);

    EXPECT_EQ(true, oraDopo>ora);
}