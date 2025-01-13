

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/file.h>
#include "FinestraPrincipale.h"

MyFrame::MyFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) , registroAttivita(nullptr), sceltaGiorno(nullptr),
                                          sceltaMese(nullptr), sceltaAnno(nullptr), bottoneDiRicercaData(nullptr), pannello(nullptr),
                                          testoSopraAnno(nullptr), testoSopraGiorno(nullptr), testoSopraMese(nullptr),
                                          bottoneDiRicercaNome(nullptr), casellaRicercaNome(nullptr){

    pannello = new wxPanel(this);

    registroAttivita = new Registro;

    testoDiBenvenuto = new wxStaticText(pannello, wxID_ANY,
                                                      "Seleziona il giorno di cui vuoi visualizzare le attivita",
                                                      wxPoint(50, 20), wxSize(-1, -1));
    //leggo la data odierna per impostare il default
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int todayGiorno = now->tm_mday;
    int todayMese = now->tm_mon + 1;
    int todayAnno = now->tm_year + 1900;


    //selezione data con spinCtrl, controllo di correttezza in basso su evento
    sceltaMese = new wxSpinCtrl(pannello, wxID_ANY, "", wxPoint(100, 75), wxSize(-1, -1));
    sceltaMese->SetRange(1, 12);
    sceltaMese->SetValue(todayMese);


    sceltaGiorno = new wxSpinCtrl(pannello, wxID_ANY, "", wxPoint(50, 75), wxSize(-1, -1));
    sceltaGiorno->SetRange(1, 31);
    sceltaGiorno->SetValue(todayGiorno);


    sceltaAnno = new wxSpinCtrl(pannello, wxID_ANY, " ", wxPoint(150, 75), wxSize(80, -1));
    sceltaAnno->SetRange(1900, 2100);
    sceltaAnno->SetValue(todayAnno);


    bottoneDiRicercaData = new wxButton(pannello, wxID_ANY, "Cerca Data", wxPoint(250, 75), wxSize(-1, -1));


    bottoneDiRicercaData->Bind(wxEVT_BUTTON, &MyFrame::onButtonSearchDateClick, this);


    bottoneDiRicercaNome = new wxButton(pannello, wxID_ANY, "Cerca Nome", wxPoint(250, 125), wxSize(-1, -1));
    casellaRicercaNome = new wxTextCtrl(pannello, wxID_ANY, "Nome", wxPoint(50,125),wxSize(150, 25));

    bottoneDiRicercaNome->Bind(wxEVT_BUTTON, &MyFrame::onButtonSearchNameClick,this);

    testoSopraMese = new wxStaticText(pannello, wxID_ANY, "Mese",
                                                    wxPoint(100, 50), wxSize(-1, -1));
    testoSopraGiorno = new wxStaticText(pannello, wxID_ANY, "Giorno",
                                                      wxPoint(50, 50), wxSize(-1, -1));
    testoSopraAnno = new wxStaticText(pannello, wxID_ANY, "Anno",
                                                    wxPoint(150, 50), wxSize(-1, -1));

    //evento di controllo data collegato
    sceltaAnno->Bind(wxEVT_SPINCTRL, &MyFrame::onModificaData, this);
    sceltaMese->Bind(wxEVT_SPINCTRL, &MyFrame::onModificaData, this);
    sceltaGiorno->Bind(wxEVT_SPINCTRL, &MyFrame::onModificaData, this);

};


//funzione del bottone che cerca il giorno e apre la prossima finestra
void MyFrame::onButtonSearchDateClick(wxCommandEvent &evt) {
    try {
        GiornoDelCalendario dataDiRicerca(sceltaGiorno->GetValue(), sceltaMese->GetValue(), sceltaAnno->GetValue());
        FrameSecondario *secondaFinestra = new FrameSecondario("Elenco attivita", registroAttivita, dataDiRicerca);
        secondaFinestra->SetClientSize(800, 600);
        secondaFinestra->Center();
        secondaFinestra->Show();
    }
    catch (const std::invalid_argument& e){
        wxMessageBox(wxString(e.what()), "Errore", wxOK | wxICON_ERROR, this);
    };
}

void MyFrame::onButtonSearchNameClick(wxCommandEvent &evt){
    std::string nomeDiRicerca;
    try {
        nomeDiRicerca = casellaRicercaNome->GetLineText(0).ToStdString();
        if(nomeDiRicerca == ""){
            throw std::invalid_argument ("Inserisci il nome che vuoi cercare");
        }
        FrameSecondario *secondaFinestra = new FrameSecondario("Elenco attivita", registroAttivita, nomeDiRicerca);
        secondaFinestra->SetClientSize(800, 600);
        secondaFinestra->Center();
        secondaFinestra->Show();
    }
    catch (const std::invalid_argument& e){
        wxMessageBox(wxString(e.what()), "Errore", wxOK | wxICON_ERROR, this);
    }

}
//evento di controllo data
void MyFrame::onModificaData(wxCommandEvent &evt) {
    int meseSelezionato = sceltaMese->GetValue();
    int annoSelezionato = sceltaAnno->GetValue();
    switch (meseSelezionato) {
        case 2:
            if (GiornoDelCalendario::isBisestile(annoSelezionato))
                sceltaGiorno->SetRange(1, 29);
            else
                sceltaGiorno->SetRange(1, 28);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sceltaGiorno->SetRange(1, 30);
            break;
        default:
            sceltaGiorno->SetRange(1, 31);
            break;
    }
}

