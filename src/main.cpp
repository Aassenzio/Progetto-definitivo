#include <iostream>
#include <wx/wx.h>
#include "app.h"
#include "FinestraPrincipale.h"

wxIMPLEMENT_APP(App);
bool::App::OnInit(){
    MyFrame* myFrame =new MyFrame("Registro Attivita");
    myFrame->SetClientSize(390, 190);
    myFrame->Center();
    myFrame->Show();
    return true;
}
