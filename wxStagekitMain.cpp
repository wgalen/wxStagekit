/***************************************************************
 * Name:      wxStagekitMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Wayne M. Galen (jummama@gmail.com)
 * Created:   2010-11-23
 * Copyright: Wayne M. Galen ()
 * License:
 **************************************************************/

#include "wxStagekitMain.h"
#include <wx/msgdlg.h>
#include "stagekit.h"
#include "stagekit.c"

//(*InternalHeaders(wxStagekitFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)
bool bFogStatus=false;
unsigned char c_red,c_yellow,c_green,c_blue=0;
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxStagekitFrame)
const long wxStagekitFrame::ID_R0 = wxNewId();
const long wxStagekitFrame::ID_R1 = wxNewId();
const long wxStagekitFrame::ID_R2 = wxNewId();
const long wxStagekitFrame::ID_R3 = wxNewId();
const long wxStagekitFrame::ID_R4 = wxNewId();
const long wxStagekitFrame::ID_R5 = wxNewId();
const long wxStagekitFrame::ID_R6 = wxNewId();
const long wxStagekitFrame::ID_R7 = wxNewId();
const long wxStagekitFrame::ID_STATICTEXT1 = wxNewId();
const long wxStagekitFrame::ID_Y0 = wxNewId();
const long wxStagekitFrame::ID_Y1 = wxNewId();
const long wxStagekitFrame::ID_Y2 = wxNewId();
const long wxStagekitFrame::ID_Y3 = wxNewId();
const long wxStagekitFrame::ID_Y4 = wxNewId();
const long wxStagekitFrame::ID_Y5 = wxNewId();
const long wxStagekitFrame::ID_Y6 = wxNewId();
const long wxStagekitFrame::ID_Y7 = wxNewId();
const long wxStagekitFrame::ID_STATICTEXT2 = wxNewId();
const long wxStagekitFrame::ID_CHECKBOX17 = wxNewId();
const long wxStagekitFrame::ID_G1 = wxNewId();
const long wxStagekitFrame::ID_G2 = wxNewId();
const long wxStagekitFrame::ID_G3 = wxNewId();
const long wxStagekitFrame::ID_G4 = wxNewId();
const long wxStagekitFrame::ID_CHECKBOX22 = wxNewId();
const long wxStagekitFrame::ID_G6 = wxNewId();
const long wxStagekitFrame::ID_G7 = wxNewId();
const long wxStagekitFrame::ID_STATICTEXT3 = wxNewId();
const long wxStagekitFrame::ID_B0 = wxNewId();
const long wxStagekitFrame::ID_B1 = wxNewId();
const long wxStagekitFrame::ID_B2 = wxNewId();
const long wxStagekitFrame::ID_B3 = wxNewId();
const long wxStagekitFrame::ID_B4 = wxNewId();
const long wxStagekitFrame::ID_B5 = wxNewId();
const long wxStagekitFrame::ID_B6 = wxNewId();
const long wxStagekitFrame::ID_B7 = wxNewId();
const long wxStagekitFrame::ID_STATICTEXT4 = wxNewId();
const long wxStagekitFrame::ID_STROBEOFF = wxNewId();
const long wxStagekitFrame::ID_STROBESLOW = wxNewId();
const long wxStagekitFrame::ID_STROBEMED = wxNewId();
const long wxStagekitFrame::ID_STROBEFAST = wxNewId();
const long wxStagekitFrame::ID_STROBEFASTEST = wxNewId();
const long wxStagekitFrame::ID_STATICTEXT5 = wxNewId();
const long wxStagekitFrame::ID_PANIC = wxNewId();
const long wxStagekitFrame::ID_FOG = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxStagekitFrame,wxFrame)
    //(*EventTable(wxStagekitFrame)
    //*)
END_EVENT_TABLE()

wxStagekitFrame::wxStagekitFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxStagekitFrame)
    wxGridSizer* GridSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxGridSizer* GridSizer4;
    wxGridSizer* GridSizer3;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer6;
    wxGridSizer* GridSizer5;

    Create(parent, wxID_ANY, _("wxStagekit"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(551,269));
    SetMinSize(wxSize(551,269));
    SetMaxSize(wxSize(551,269));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    GridSizer2 = new wxGridSizer(1, 1, 0, 0);
    GridSizer1 = new wxGridSizer(0, 9, 0, 0);
    r0 = new wxCheckBox(this, ID_R0, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R0"));
    r0->SetValue(false);
    GridSizer1->Add(r0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r1 = new wxCheckBox(this, ID_R1, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R1"));
    r1->SetValue(false);
    GridSizer1->Add(r1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r2 = new wxCheckBox(this, ID_R2, _("2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R2"));
    r2->SetValue(false);
    GridSizer1->Add(r2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r3 = new wxCheckBox(this, ID_R3, _("3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R3"));
    r3->SetValue(false);
    GridSizer1->Add(r3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r4 = new wxCheckBox(this, ID_R4, _("4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R4"));
    r4->SetValue(false);
    GridSizer1->Add(r4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r5 = new wxCheckBox(this, ID_R5, _("5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R5"));
    r5->SetValue(false);
    GridSizer1->Add(r5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r6 = new wxCheckBox(this, ID_R6, _("6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R6"));
    r6->SetValue(false);
    GridSizer1->Add(r6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    r7 = new wxCheckBox(this, ID_R7, _("7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_R7"));
    r7->SetValue(false);
    GridSizer1->Add(r7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Red"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(GridSizer1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer3 = new wxGridSizer(0, 9, 0, 0);
    y0 = new wxCheckBox(this, ID_Y0, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y0"));
    y0->SetValue(false);
    GridSizer3->Add(y0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y1 = new wxCheckBox(this, ID_Y1, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y1"));
    y1->SetValue(false);
    GridSizer3->Add(y1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y2 = new wxCheckBox(this, ID_Y2, _("2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y2"));
    y2->SetValue(false);
    GridSizer3->Add(y2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y3 = new wxCheckBox(this, ID_Y3, _("3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y3"));
    y3->SetValue(false);
    GridSizer3->Add(y3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y4 = new wxCheckBox(this, ID_Y4, _("4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y4"));
    y4->SetValue(false);
    GridSizer3->Add(y4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y5 = new wxCheckBox(this, ID_Y5, _("5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y5"));
    y5->SetValue(false);
    GridSizer3->Add(y5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y6 = new wxCheckBox(this, ID_Y6, _("6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y6"));
    y6->SetValue(false);
    GridSizer3->Add(y6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    y7 = new wxCheckBox(this, ID_Y7, _("7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_Y7"));
    y7->SetValue(false);
    GridSizer3->Add(y7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Yellow"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(GridSizer3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer4 = new wxGridSizer(0, 9, 0, 0);
    g0 = new wxCheckBox(this, ID_CHECKBOX17, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX17"));
    g0->SetValue(false);
    GridSizer4->Add(g0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g1 = new wxCheckBox(this, ID_G1, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_G1"));
    g1->SetValue(false);
    GridSizer4->Add(g1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g2 = new wxCheckBox(this, ID_G2, _("2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_G2"));
    g2->SetValue(false);
    GridSizer4->Add(g2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g3 = new wxCheckBox(this, ID_G3, _("3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_G3"));
    g3->SetValue(false);
    GridSizer4->Add(g3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g4 = new wxCheckBox(this, ID_G4, _("4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_G4"));
    g4->SetValue(false);
    GridSizer4->Add(g4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g5 = new wxCheckBox(this, ID_CHECKBOX22, _("5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX22"));
    g5->SetValue(false);
    GridSizer4->Add(g5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g6 = new wxCheckBox(this, ID_G6, _("6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_G6"));
    g6->SetValue(false);
    GridSizer4->Add(g6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    g7 = new wxCheckBox(this, ID_G7, _("7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_G7"));
    g7->SetValue(false);
    GridSizer4->Add(g7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Green"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(GridSizer4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer5 = new wxGridSizer(0, 9, 0, 0);
    b0 = new wxCheckBox(this, ID_B0, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B0"));
    b0->SetValue(false);
    GridSizer5->Add(b0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b1 = new wxCheckBox(this, ID_B1, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B1"));
    b1->SetValue(false);
    GridSizer5->Add(b1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b2 = new wxCheckBox(this, ID_B2, _("2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B2"));
    b2->SetValue(false);
    GridSizer5->Add(b2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b3 = new wxCheckBox(this, ID_B3, _("3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B3"));
    b3->SetValue(false);
    GridSizer5->Add(b3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b4 = new wxCheckBox(this, ID_B4, _("4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B4"));
    b4->SetValue(false);
    GridSizer5->Add(b4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b5 = new wxCheckBox(this, ID_B5, _("5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B5"));
    b5->SetValue(false);
    GridSizer5->Add(b5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b6 = new wxCheckBox(this, ID_B6, _("6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B6"));
    b6->SetValue(false);
    GridSizer5->Add(b6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b7 = new wxCheckBox(this, ID_B7, _("7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_B7"));
    b7->SetValue(false);
    GridSizer5->Add(b7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Blue"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridSizer5->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(GridSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer6 = new wxGridSizer(1, 6, 0, 0);
    StrobeOff = new wxRadioButton(this, ID_STROBEOFF, _("Off"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STROBEOFF"));
    GridSizer6->Add(StrobeOff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StrobeSlow = new wxRadioButton(this, ID_STROBESLOW, _("Slow"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STROBESLOW"));
    GridSizer6->Add(StrobeSlow, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StrobeMed = new wxRadioButton(this, ID_STROBEMED, _("Medium"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STROBEMED"));
    GridSizer6->Add(StrobeMed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StrobeFast = new wxRadioButton(this, ID_STROBEFAST, _("Fast"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STROBEFAST"));
    GridSizer6->Add(StrobeFast, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StrobeFastest = new wxRadioButton(this, ID_STROBEFASTEST, _("Fastest"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STROBEFASTEST"));
    GridSizer6->Add(StrobeFastest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Strobe"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridSizer6->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(GridSizer6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    btnPanic = new wxButton(this, ID_PANIC, _("Panic"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PANIC"));
    FlexGridSizer2->Add(btnPanic, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    chkFog = new wxCheckBox(this, ID_FOG, _("Fog"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_FOG"));
    chkFog->SetValue(false);
    FlexGridSizer2->Add(chkFog, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_R0,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr0Click);
    Connect(ID_R1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr1Click);
    Connect(ID_R2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr2Click);
    Connect(ID_R3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr3Click);
    Connect(ID_R4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr4Click);
    Connect(ID_R5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr5Click);
    Connect(ID_R6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr6Click);
    Connect(ID_R7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onr7Click);
    Connect(ID_Y0,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony0Click);
    Connect(ID_Y1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony1Click);
    Connect(ID_Y2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony2Click);
    Connect(ID_Y3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony3Click);
    Connect(ID_Y4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony4Click);
    Connect(ID_Y5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony5Click);
    Connect(ID_Y6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony6Click);
    Connect(ID_Y7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ony7Click);
    Connect(ID_CHECKBOX17,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong0Click);
    Connect(ID_G1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong1Click);
    Connect(ID_G2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong2Click);
    Connect(ID_G3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong3Click);
    Connect(ID_G4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong4Click);
    Connect(ID_CHECKBOX22,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong5Click);
    Connect(ID_G6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong6Click);
    Connect(ID_G7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Ong7Click);
    Connect(ID_B0,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb0Click);
    Connect(ID_B1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb1Click);
    Connect(ID_B2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb2Click);
    Connect(ID_B3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb3Click);
    Connect(ID_B4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb4Click);
    Connect(ID_B5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb5Click);
    Connect(ID_B6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb6Click);
    Connect(ID_B7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::Onb7Click);
    Connect(ID_STROBEOFF,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&wxStagekitFrame::OnStrobeOffSelect);
    Connect(ID_STROBESLOW,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&wxStagekitFrame::OnStrobeSlowSelect);
    Connect(ID_STROBEMED,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&wxStagekitFrame::OnStrobeMedSelect);
    Connect(ID_STROBEFAST,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&wxStagekitFrame::OnStrobeFastSelect);
    Connect(ID_STROBEFASTEST,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&wxStagekitFrame::OnStrobeFastestSelect);
    Connect(ID_PANIC,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::OnbtnPanicClick);
    Connect(ID_FOG,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wxStagekitFrame::OnchkFogClick);
    //*)
    sk_init(NULL);
    sk_alloff();
}

wxStagekitFrame::~wxStagekitFrame()
{
    //(*Destroy(wxStagekitFrame)
    //*)
}

void wxStagekitFrame::OnQuit(wxCommandEvent& event)
{
    sk_close();
    Close();
}

void wxStagekitFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxStagekitFrame::OnStrobeOffSelect(wxCommandEvent& event)
{
    sk_nostrobe();
}

void wxStagekitFrame::OnStrobeSlowSelect(wxCommandEvent& event)
{
    sk_slowstrobe();
}

void wxStagekitFrame::OnStrobeMedSelect(wxCommandEvent& event)
{
    sk_medstrobe();
}

void wxStagekitFrame::OnStrobeFastSelect(wxCommandEvent& event)
{
    sk_faststrobe();
}

void wxStagekitFrame::OnStrobeFastestSelect(wxCommandEvent& event)
{
    sk_fasteststrobe();
}

void wxStagekitFrame::OnbtnPanicClick(wxCommandEvent& event)
{
    sk_alloff();
    c_red=0;
    c_yellow=0;
    c_green=0;
    c_blue=0;
    StrobeOff->SetValue(true);
    r0->SetValue(false);
    r1->SetValue(false);
    r2->SetValue(false);
    r3->SetValue(false);
    r4->SetValue(false);
    r5->SetValue(false);
    r6->SetValue(false);
    r7->SetValue(false);
    y0->SetValue(false);
    y1->SetValue(false);
    y2->SetValue(false);
    y3->SetValue(false);
    y4->SetValue(false);
    y5->SetValue(false);
    y6->SetValue(false);
    y7->SetValue(false);
    g0->SetValue(false);
    g1->SetValue(false);
    g2->SetValue(false);
    g3->SetValue(false);
    g4->SetValue(false);
    g5->SetValue(false);
    g6->SetValue(false);
    g7->SetValue(false);
    b0->SetValue(false);
    b1->SetValue(false);
    b2->SetValue(false);
    b3->SetValue(false);
    b4->SetValue(false);
    b5->SetValue(false);
    b6->SetValue(false);
    b7->SetValue(false);
    chkFog->SetValue(false);
}

void wxStagekitFrame::OnchkFogClick(wxCommandEvent& event)
{
    if (chkFog->GetValue())
        {sk_fogon();}
    else
        {sk_fogoff();}
}

void wxStagekitFrame::Onr0Click(wxCommandEvent& event)
{
    if (r0->GetValue())
        c_red+=0x1;
    else
        c_red-=0x1;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr1Click(wxCommandEvent& event)
{
    if (r1->GetValue())
        c_red+=0x2;
    else
        c_red-=0x2;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr2Click(wxCommandEvent& event)
{
    if (r2->GetValue())
        c_red+=0x4;
    else
        c_red-=0x4;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr3Click(wxCommandEvent& event)
{
    if (r3->GetValue())
        c_red+=0x8;
    else
        c_red-=0x8;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr4Click(wxCommandEvent& event)
{
    if (r4->GetValue())
        c_red+=0x10;
    else
        c_red-=0x10;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr5Click(wxCommandEvent& event)
{
    if (r5->GetValue())
        c_red+=0x20;
    else
        c_red-=0x20;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr6Click(wxCommandEvent& event)
{
    if (r6->GetValue())
        c_red+=0x40;
    else
        c_red-=0x40;

    sk_setred(c_red);
}

void wxStagekitFrame::Onr7Click(wxCommandEvent& event)
{
    if (r7->GetValue())
        c_red+=0x80;
    else
        c_red-=0x80;

    sk_setred(c_red);
}

void wxStagekitFrame::Ony0Click(wxCommandEvent& event)
{
    if (y0->GetValue())
        c_yellow+=0x1;
    else
        c_yellow-=0x1;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony1Click(wxCommandEvent& event)
{
    if (y1->GetValue())
        c_yellow+=0x2;
    else
        c_yellow-=0x2;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony2Click(wxCommandEvent& event)
{
    if (y2->GetValue())
        c_yellow+=0x4;
    else
        c_yellow-=0x4;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony3Click(wxCommandEvent& event)
{
    if (y3->GetValue())
        c_yellow+=0x8;
    else
        c_yellow-=0x8;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony4Click(wxCommandEvent& event)
{
    if (y4->GetValue())
        c_yellow+=0x10;
    else
        c_yellow-=0x10;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony5Click(wxCommandEvent& event)
{
    if (y5->GetValue())
        c_yellow+=0x20;
    else
        c_yellow-=0x20;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony6Click(wxCommandEvent& event)
{
    if (y6->GetValue())
        c_yellow+=0x40;
    else
        c_yellow-=0x40;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ony7Click(wxCommandEvent& event)
{
    if (y7->GetValue())
        c_yellow+=0x80;
    else
        c_yellow-=0x80;

    sk_setyellow(c_yellow);
}

void wxStagekitFrame::Ong0Click(wxCommandEvent& event)
{
    if (g0->GetValue())
        c_green+=0x1;
    else
        c_green-=0x1;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong1Click(wxCommandEvent& event)
{
    if (g1->GetValue())
        c_green+=0x2;
    else
        c_green-=0x2;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong2Click(wxCommandEvent& event)
{
    if (g2->GetValue())
        c_green+=0x4;
    else
        c_green-=0x4;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong3Click(wxCommandEvent& event)
{
    if (g3->GetValue())
        c_green+=0x8;
    else
        c_green-=0x8;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong4Click(wxCommandEvent& event)
{
    if (g4->GetValue())
        c_green+=0x10;
    else
        c_green-=0x10;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong5Click(wxCommandEvent& event)
{
    if (g5->GetValue())
        c_green+=0x20;
    else
        c_green-=0x20;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong6Click(wxCommandEvent& event)
{
    if (g6->GetValue())
        c_green+=0x40;
    else
        c_green-=0x40;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Ong7Click(wxCommandEvent& event)
{
    if (g7->GetValue())
        c_green+=0x80;
    else
        c_green-=0x80;

    sk_setgreen(c_green);
}

void wxStagekitFrame::Onb0Click(wxCommandEvent& event)
{
    if (b0->GetValue())
        c_blue+=0x1;
    else
        c_blue-=0x1;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb1Click(wxCommandEvent& event)
{
    if (b1->GetValue())
        c_blue+=0x2;
    else
        c_blue-=0x2;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb2Click(wxCommandEvent& event)
{
    if (b2->GetValue())
        c_blue+=0x4;
    else
        c_blue-=0x4;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb3Click(wxCommandEvent& event)
{
    if (b3->GetValue())
        c_blue+=0x8;
    else
        c_blue-=0x8;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb4Click(wxCommandEvent& event)
{
    if (b4->GetValue())
        c_blue+=0x10;
    else
        c_blue-=0x10;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb5Click(wxCommandEvent& event)
{
    if (b5->GetValue())
        c_blue+=0x20;
    else
        c_blue-=0x20;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb6Click(wxCommandEvent& event)
{
    if (b6->GetValue())
        c_blue+=0x40;
    else
        c_blue-=0x40;

    sk_setblue(c_blue);
}

void wxStagekitFrame::Onb7Click(wxCommandEvent& event)
{
    if (b7->GetValue())
        c_blue+=0x80;
    else
        c_blue-=0x80;

    sk_setblue(c_blue);
}

