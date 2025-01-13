#include "Registro.h"

Registro::Registro(): contatoreAssoluto(0){}//il contatore assoluto inizalizzato a 0 va solo avanti anche in caso di eliminazione


void Registro::searchDate(GiornoDelCalendario dataCercata, wxGrid *griglia) {
    int contatoreRighe = 0;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if(vettoreAttivita[iter]) { // in caso non ci sia nulla in questa posizione salta l'iterazione
        if ((vettoreAttivita[iter]->getData()).comparaData(dataCercata)) {
            griglia->AppendRows(1);
            griglia->SetCellValue(contatoreRighe, 0,
                                  wxString::Format(wxT("%i"), vettoreAttivita[iter]->getId()));
            griglia->SetCellValue(contatoreRighe, 1, vettoreAttivita[iter]->getNome());
            griglia->SetCellValue(contatoreRighe, 2, vettoreAttivita[iter]->getStringaData());
            griglia->SetCellValue(contatoreRighe, 3, vettoreAttivita[iter]->getOrarioStringaCompleto());
            griglia->SetCellValue(contatoreRighe, 4, vettoreAttivita[iter]->getDescrizione());
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