
#ifndef PROGETTODEFINITIVO_FINESTRA_H
#define PROGETTODEFINITIVO_FINESTRA_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Utility.h"
#include "Registro.h"
#include "FinestraDiModifica.h"
class MyFrame:public wxFrame {
public:
    MyFrame(const wxString &title);
private:
    Registro* registroAttivita;
    void OnButtonSearchClick(wxCommandEvent& evt);
    void OnModificaData(wxCommandEvent& evt);
    void OnButtonSaveClick(wxCommandEvent& evt);
    wxSpinCtrl* sceltaGiorno = nullptr;
    wxSpinCtrl* sceltaMese= nullptr;
    wxSpinCtrl* sceltaAnno= nullptr;
    wxListBox* listBoxDiProva= nullptr;
    wxTextCtrl* nomeAttivita= nullptr;
    wxButton* bottoneModifica= nullptr;
    wxPanel* pannello= nullptr;
};
#endif //PROGETTODEFINITIVO_FINESTRA_H
