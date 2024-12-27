
#ifndef PROGETTODEFINITIVO_FINESTRA_H
#define PROGETTODEFINITIVO_FINESTRA_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
class MyFrame:public wxFrame {
public:
    MyFrame(const wxString &title);
private:
    void OnButtonSearchClick(wxCommandEvent& evt);
    void OnModificaData(wxCommandEvent& evt);
    void OnButtonSaveClick(wxCommandEvent& evt);
    wxSpinCtrl* sceltaGiorno;
    wxSpinCtrl* sceltaMese;
    wxSpinCtrl* sceltaAnno;
    wxTextCtrl* testoDiProva;
    wxPanel* pannello;
};
#endif //PROGETTODEFINITIVO_FINESTRA_H
