#include "gtest/gtest.h"
#include "Orario.h"


TEST(Orario, operatore) {
    Orario ora(11, 11);
    Orario oraDopo(12, 11);

    EXPECT_EQ(true, oraDopo > ora);
}

TEST(Orario, operatoreFalso) {
    Orario ora(11, 11);
    Orario oraDopo(12, 11);

    EXPECT_EQ(false, ora > oraDopo);
}

TEST(Orario, EccezioneOra25) {

    EXPECT_THROW(Orario(25, 11), std::invalid_argument);
}

TEST(Orario, EccezioneMinuto61) {

    EXPECT_THROW(Orario(12, 61), std::invalid_argument);
}

TEST(Orario, operatoreUguale) {
    Orario ora(11, 11);
    Orario oraDue(11, 11);

    EXPECT_EQ(true, ora == oraDue);
}

TEST(Orario, operatoreUgualeOreDiverse) {
    Orario ora(11, 1);
    Orario oradue(1, 11);

    EXPECT_EQ(false, ora == oradue);
}