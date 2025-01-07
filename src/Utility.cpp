#include "Utility.h"
#include <string>

//implementazione controllo bisestile
bool isBisestile(int annoSelezionato) {
    if (annoSelezionato % 4 == 0 && annoSelezionato % 100 != 0)
        return true;
    else return false;
}
