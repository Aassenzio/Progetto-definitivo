#include "Orario.h"

Orario::Orario(int oraInserita, int minutoInserito) {

    if(oraInserita > 23 || minutoInserito > 59){
        throw std::invalid_argument("Orario non valido");
    }


    ore = (oraInserita < 10 ? "0" : "") + std::to_string(oraInserita);
    minuti = (minutoInserito < 10 ? "0" : "") + std::to_string(minutoInserito);
};


std::string Orario::toString() {
    std::string stringaFinale = ore + ":" + minuti;
    return stringaFinale;
}

bool Orario::operator>(const Orario& other) const {
    if (std::stoi(ore) > std::stoi(other.ore)) {
        return true;
    }
    else if (std::stoi(ore) == std::stoi(other.ore)) {
        return std::stoi(minuti) > std::stoi(other.minuti);
    }
    return false;
}