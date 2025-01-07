#include "Registro.h"

Registro::Registro(): contatoreAssoluto(0){}
void Registro::searchDate(GiornoDelCalendario dataCercata, wxGrid *griglia) {
    int contatoreRighe = 0;
    for (int iter = 0; iter < contatoreAssoluto; iter++) {
        if(!vettoreAttivita[iter]) {}
        else{
            if ((vettoreAttivita[iter]->MostraData()).ComparaData(dataCercata)) {
                griglia->AppendRows(1);
                griglia->SetCellValue(contatoreRighe, 0,
                                      wxString::Format(wxT("%i"), vettoreAttivita[iter]->MostraID()));
                griglia->SetCellValue(contatoreRighe, 1, vettoreAttivita[iter]->MostraNome());
                griglia->SetCellValue(contatoreRighe, 2,vettoreAttivita[iter]->StampaData());
                griglia->SetCellValue(contatoreRighe, 3, vettoreAttivita[iter]->GetOrarioStringaCompleto());
                griglia->SetCellValue(contatoreRighe, 4, vettoreAttivita[iter]->MostraDescrizione());
                contatoreRighe++;
            }
        }
    }
}

int Registro::GetAbsCounter() {
    return contatoreAssoluto;
}

void Registro::AddAttivita(wxString nomeAttivita, GiornoDelCalendario dataAttivita, wxString descrizioneAttivita, Orario inizioAtt,
                           Orario fineAtt) {
    vettoreAttivita.push_back(new Attivita(nomeAttivita, dataAttivita, contatoreAssoluto, descrizioneAttivita, inizioAtt,
                                       fineAtt));
    contatoreAssoluto++;
}

void Registro::EliminaAttivita(int ID) {
    delete vettoreAttivita[ID];
    vettoreAttivita[ID] = nullptr;
}