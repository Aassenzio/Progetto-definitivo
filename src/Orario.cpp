#include "Orario.h"

Orario::Orario(int oraInserita, int minutoInserito) {
    ore = (oraInserita < 10 ? "0" : "") + std::to_string(oraInserita);
    minuti = (minutoInserito < 10 ? "0" : "") + std::to_string(minutoInserito);
};


std::string Orario::toString() {
    std::string stringaFinale = ore + ":" + minuti;
    return stringaFinale;
}