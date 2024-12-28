#include "Registro.h"
void Registro::searchDate(int dataCercata, wxListCtrl* listaDiQualcosa){
    for(int iter = 0; iter < contatoreAssoluto; iter++) {
        if (vettoreAttivita[iter].MostraData() == dataCercata){
            listaDiQualcosa->InsertItem(iter , vettoreAttivita[iter].MostraNome());
        }
    }
}

int Registro::GetAbsCounter() {
    return contatoreAssoluto;
}

void Registro::AddAttivita(wxString nomeAttivita) {
    vettoreAttivita.push_back(Attivita(nomeAttivita));
    contatoreAssoluto++;
}