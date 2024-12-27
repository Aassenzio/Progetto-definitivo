
#ifndef PROGETTODEFINITIVO_FINESTRA_H
#define PROGETTODEFINITIVO_FINESTRA_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
class MyFrame:public wxFrame {
public:
    MyFrame(const wxString &title);
private:
    void OnButtonClick(wxCommandEvent& evt);
    void OnModificaAnno(wxCommandEvent& evt);
    void OnModificaMese(wxCommandEvent& evt);
    wxSpinCtrl* sceltaGiorno;
    wxSpinCtrl* sceltaMese;
    wxSpinCtrl* sceltaAnno;
    bool IsBisestile();
};
#endif //PROGETTODEFINITIVO_FINESTRA_H
