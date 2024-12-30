#include <iostream>
#include "Orario.h"
#include <wx/wx.h>
#include "app.h"
#include "finestra.h"
#include "Data.h"

wxIMPLEMENT_APP(App);
bool::App::OnInit(){
    MyFrame* myFrame =new MyFrame("Registro Attivita");
    myFrame->SetClientSize(390, 190);
    myFrame->Center();
    myFrame->Show();
    return true;
}
/*int main(){

}*/
// Created by Igor on 4/24/2024.
//
