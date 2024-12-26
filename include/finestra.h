
#ifndef PROGETTODEFINITIVO_FINESTRA_H
#define PROGETTODEFINITIVO_FINESTRA_H
#include <wx/wx.h>
class MyFrame:public wxFrame {
public:
    MyFrame(const wxString &title);
private:
    void OnButtonClick(wxCommandEvent& evt);
};
#endif //PROGETTODEFINITIVO_FINESTRA_H
