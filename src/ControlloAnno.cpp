#include "ControlloAnno.h"

//implementazione controllo bisestile
bool isBisestile(int annoSelezionato) {
    if (annoSelezionato % 4 == 0 && (annoSelezionato % 100 != 0 || annoSelezionato % 400 == 0) )
        return true;
    else return false;
}
