
#ifndef PROGETTODEFINITIVO_FINESTRA_H
#define PROGETTODEFINITIVO_FINESTRA_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
class MyFrame:public wxFrame {
public:
    MyFrame(const wxString &title);
private:
    void OnButtonClick(wxCommandEvent& evt);
    wxChoice* sceltaGiorno;
    wxChoice* sceltaMese;
    wxSpinCtrl* sceltaAnno;
};
#endif //PROGETTODEFINITIVO_FINESTRA_H
