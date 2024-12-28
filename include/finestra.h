
#ifndef PROGETTODEFINITIVO_FINESTRA_H
#define PROGETTODEFINITIVO_FINESTRA_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Utility.h"
#include "Registro.h"
class MyFrame:public wxFrame {
public:
    MyFrame(const wxString &title);
private:
    Registro* registroAttivita;
    void OnButtonSearchClick(wxCommandEvent& evt);
    void OnModificaData(wxCommandEvent& evt);
    void OnButtonSaveClick(wxCommandEvent& evt);
    wxSpinCtrl* sceltaGiorno;
    wxSpinCtrl* sceltaMese;
    wxSpinCtrl* sceltaAnno;
    wxListBox* listBoxDiProva;
    wxPanel* pannello;
};
#endif //PROGETTODEFINITIVO_FINESTRA_H
