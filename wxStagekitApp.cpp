/***************************************************************
 * Name:      wxStagekitApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Wayne M. Galen (jummama@gmail.com)
 * Created:   2010-11-23
 * Copyright: Wayne M. Galen ()
 * License:
 **************************************************************/

#include "wxStagekitApp.h"

//(*AppHeaders
#include "wxStagekitMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxStagekitApp);

bool wxStagekitApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxStagekitFrame* Frame = new wxStagekitFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
