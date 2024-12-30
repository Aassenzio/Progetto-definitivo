#include "Orario.h"

int Orario::GetOre() {
    return ore;
}
int Orario::GetMinuti() {
    return minuti;
}

wxString Orario::GetOrarioStringa() {
    wxString stringaOre = wxString::Format(wxT("%i"),ore);
    wxString stringaMinuti = wxString::Format(wxT("%i"),minuti);
    wxString stringaFinale = stringaOre + ":" + stringaMinuti;
    return stringaFinale;
}