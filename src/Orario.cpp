#include "Orario.h"

Orario::Orario(int oraInserita, int minutoInserito){
    ore = wxString::Format(wxT("%i"),oraInserita);
    minuti = wxString::Format(wxT("%i"),minutoInserito);
    if (oraInserita < 10){
        ore = "0" + ore;
    }
    if(minutoInserito< 10){
        minuti = "0"+ minuti;
    }
};


wxString Orario::GetOrarioStringa() {
    wxString stringaFinale = ore + ":" + minuti;
    return stringaFinale;
}