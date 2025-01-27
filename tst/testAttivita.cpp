#include "gtest/gtest.h"
#include "Attivita.h"

TEST(Attivita, EccezioneOrarioCreazione) {
    Orario orarioInizio(11, 11);
    Orario orarioFine(11, 10);
    GiornoDelCalendario giorno(1, 1, 2009);
    EXPECT_THROW(Attivita("test", giorno, 1, "test", orarioInizio, orarioFine), std::invalid_argument);
}