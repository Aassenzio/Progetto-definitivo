#include "Registro.h"

Registro::Registro(): contatoreAssoluto(0){}//il contatore assoluto inizalizzato a 0 va solo avanti anche in caso di eliminazione
//se vuoi non perdere la posizione puoi levare il vettore e implementare una map

void Registro::searchDate(GiornoDelCalendario dataCercata, wxGrid *griglia) {
    int contatoreRighe = 0;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if(vettoreAttivita[iter]) { // in caso non ci sia nulla in questa posizione salta l'iterazione
        if ((vettoreAttivita[iter]->mostraData()).comparaData(dataCercata)) {
            griglia->AppendRows(1);
            griglia->SetCellValue(contatoreRighe, 0,
                                  wxString::Format(wxT("%i"), vettoreAttivita[iter]->mostraId()));
            griglia->SetCellValue(contatoreRighe, 1, vettoreAttivita[iter]->mostraNome());
            griglia->SetCellValue(contatoreRighe, 2, vettoreAttivita[iter]->stampaData());
            griglia->SetCellValue(contatoreRighe, 3, vettoreAttivita[iter]->mostraOrarioStringaCompleto());
            griglia->SetCellValue(contatoreRighe, 4, vettoreAttivita[iter]->mostraDescrizione());
            griglia->SetRowSize(contatoreRighe, 17 * vettoreAttivita[iter]->getNumeroRigheDescrizione());
            contatoreRighe++;
            }
        }
    }
}


void Registro::addAttivita(wxString nome, GiornoDelCalendario data, wxString descrizione, Orario inizio,
                           Orario fine) {
    vettoreAttivita.push_back(new Attivita(nome, data, contatoreAssoluto, descrizione, inizio,
                                           fine));
    contatoreAssoluto++;
}

void Registro::eliminaAttivita(int ID) {
    delete vettoreAttivita[ID];
    vettoreAttivita[ID] = nullptr;
}