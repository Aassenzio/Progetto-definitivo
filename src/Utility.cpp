#include "Utility.h"
#include <string>

//implementazione controllo bisestile
bool IsBisestile(int annoSelezionato) {
    if (annoSelezionato % 4 == 0 && annoSelezionato % 100 != 0)
        return true;
    else return false;
}

//implementazione compattaData
int CompattaData(int anno, int mese, int giorno) {
    std::string stringaAnno = std::to_string(anno);
    std::string stringaMese = std::to_string(mese);
    std::string stringaGiorno = std::to_string(giorno);
    std::string stringaIdentificativaData = stringaGiorno + stringaMese + stringaAnno;
    int numeroIdentificativoData = std::stoi(stringaIdentificativaData);
    return numeroIdentificativoData;
}