#include "FinestraVisualizzaGriglia.h"


FrameSecondario::FrameSecondario(const wxString &title, Registro *registro, GiornoDelCalendario data) : wxFrame(nullptr, wxID_ANY,
                                                                                                title),
                                                                                        registroAttivita(registro),
                                                                                        dataDiRicerca(data),
                                                                                        selezioneCorrente(0),
                                                                                        grigliaAttivita(nullptr),
                                                                                        bottoneAddAttivita(nullptr),
                                                                                        bottoneEliminaAttivita(nullptr),
                                                                                        pannelloSecondario(nullptr){
    pannelloSecondario = new wxPanel(this);
    //griglia con i vari campi delle attivita
    grigliaAttivita = new wxGrid(pannelloSecondario, wxID_ANY, wxPoint(25, 25), wxSize(700, 400));
    grigliaAttivita->CreateGrid(0, 5);
    grigliaAttivita->HideCol(0); //colonna per conservare il numero ID dell attivita
    grigliaAttivita->SetColLabelValue(1, "Nome");
    grigliaAttivita->SetColLabelValue(2, "Data");
    grigliaAttivita->SetColLabelValue(3, "Orario inizio/fine");
    grigliaAttivita->SetColLabelValue(4, "Descrizione");
    grigliaAttivita->SetSelectionMode(wxGrid::wxGridSelectRows);
    grigliaAttivita->EnableEditing(false);
    grigliaAttivita->SetColSize(1, 90);
    grigliaAttivita->SetColSize(2, 70);
    grigliaAttivita->SetColSize(3, 150);
    grigliaAttivita->SetColSize(4, 300);

    std::vector<Attivita*> contenutoRicerca;
    int numeroAttivitaTrovate = registroAttivita->searchDate(dataDiRicerca, &contenutoRicerca);
    int contatoreRighe = 0;
    for(int iter = 0; iter < numeroAttivitaTrovate; iter ++){

        grigliaAttivita->AppendRows(1);
        grigliaAttivita->SetCellValue(contatoreRighe, 0,
                              wxString::Format(wxT("%i"), contenutoRicerca[iter]->getId()));
        grigliaAttivita->SetCellValue(contatoreRighe, 1, wxString(contenutoRicerca[iter]->getNome()));
        grigliaAttivita->SetCellValue(contatoreRighe, 2, wxString(contenutoRicerca[iter]->getStringaData()));
        grigliaAttivita->SetCellValue(contatoreRighe, 3, wxString(contenutoRicerca[iter]->getOrarioStringaCompleto()));
        grigliaAttivita->SetCellValue(contatoreRighe, 4, wxString(contenutoRicerca[iter]->getDescrizione()));
        grigliaAttivita->SetRowSize(contatoreRighe, 17 * contenutoRicerca[iter]->getNumeroRigheDescrizione());
        contatoreRighe++;
    }



    bottoneAddAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Aggiungi Attivita", wxPoint(650, 475),wxSize(100, 25));
    bottoneEliminaAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Elimina Attivita", wxPoint(650, 525));
    bottoneEliminaAttivita->Disable(); //bottone elimina disattiviato finche non avviene selezione


    bottoneAddAttivita->Bind(wxEVT_BUTTON, &FrameSecondario::onBottoneAdd, this);
    grigliaAttivita->Bind(wxEVT_GRID_SELECT_CELL, &FrameSecondario::onSelezioneRiga, this);
    bottoneEliminaAttivita->Bind(wxEVT_BUTTON, &FrameSecondario::onBottoneElimina, this);
}


// funzione collegata al pulsante aggiungi attivita
void FrameSecondario::onBottoneAdd(wxCommandEvent &evt) {
    FinestraDiAggiunta *finestraDiAggiunta = new FinestraDiAggiunta("Aggiungi Attivita", registroAttivita,
                                                                    dataDiRicerca);
    finestraDiAggiunta->SetClientSize(475, 375);
    finestraDiAggiunta->Center();
    finestraDiAggiunta->Show();
    this->Close();
}
//funzione che elimina l'attivita selezionata
void FrameSecondario::onBottoneElimina(wxCommandEvent &evt) {
    registroAttivita->eliminaAttivita(selezioneCorrente);
    wxMessageBox("Attivita eliminata correttamente", "Conferma Eliminazione", wxOK | wxICON_INFORMATION, this);
    this->Close();
}
 //funzione che controlla la selezione e attiva il tasto elimina
void FrameSecondario::onSelezioneRiga(wxGridEvent &evt) {
    wxString ID = grigliaAttivita->GetCellValue(evt.GetRow(),0);
    if(wxAtoi(ID)>= 0){
    selezioneCorrente = wxAtoi(ID);
    bottoneEliminaAttivita->Enable();
    }
}