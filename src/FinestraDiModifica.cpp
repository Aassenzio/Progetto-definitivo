#include "FinestraDiModifica.h"


FrameSecondario::FrameSecondario(const wxString &title, Registro *registro, int data) : wxFrame(nullptr, wxID_ANY,
                                                                                                title),
                                                                                        registroAttivita(registro),
                                                                                        dataDiRicerca(data),
                                                                                        selezioneCorrente(0),
                                                                                        grigliaAttivita(nullptr),
                                                                                        bottoneAddAttivita(nullptr),
                                                                                        bottoneEliminaAttivita(nullptr){
    pannelloSecondario = new wxPanel(this);
    if (!grigliaAttivita) {  //griglia con i vari campi delle attivita
        grigliaAttivita = new wxGrid(pannelloSecondario, wxID_ANY, wxPoint(25, 25), wxSize(700, 400));
        grigliaAttivita->CreateGrid(0, 5);
        grigliaAttivita->HideCol(0);
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
    }
    registroAttivita->searchDate(dataDiRicerca, grigliaAttivita);
    if (!bottoneAddAttivita) {
        bottoneAddAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Aggiungi Attivita", wxPoint(650, 475),
                                          wxSize(100, 25));
    }
    if(!bottoneEliminaAttivita) {
        bottoneEliminaAttivita = new wxButton(pannelloSecondario, wxID_ANY, "Elimina Attivita", wxPoint(650, 525));
    }
    bottoneEliminaAttivita->Disable();
    bottoneAddAttivita->Bind(wxEVT_BUTTON, &FrameSecondario::OnBottoneAdd, this);
    grigliaAttivita->Bind(wxEVT_GRID_SELECT_CELL, &FrameSecondario::OnSelezioneRiga, this);
    bottoneEliminaAttivita->Bind(wxEVT_BUTTON, &FrameSecondario::OnBottoneElimina, this);
}

void FrameSecondario::SetRegister(Registro *registro) {
    registroAttivita = registro;
}

void FrameSecondario::SetDataDiRicerca(int data) {
    dataDiRicerca = data;
}

void FrameSecondario::OnBottoneAdd(wxCommandEvent &evt) {
    FinestraDiAggiunta *finestraDiAggiunta = new FinestraDiAggiunta("Aggiungi Attivita", registroAttivita,
                                                                    dataDiRicerca);
    finestraDiAggiunta->SetClientSize(475, 375);
    finestraDiAggiunta->Center();
    finestraDiAggiunta->Show();
    this->Close();
}

void FrameSecondario::OnBottoneElimina(wxCommandEvent &evt) {
    registroAttivita->EliminaAttivita(selezioneCorrente);
    wxMessageBox("Attivita eliminata correttamente", "Conferma Eliminazione", wxOK | wxICON_INFORMATION, this);
    this->Close();
}

void FrameSecondario::OnSelezioneRiga(wxGridEvent &evt) {
    wxString ID = grigliaAttivita->GetCellValue(evt.GetRow(),0);
    selezioneCorrente = wxAtoi(ID);
    bottoneEliminaAttivita->Enable();

}