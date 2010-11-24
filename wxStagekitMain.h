/***************************************************************
 * Name:      wxStagekitMain.h
 * Purpose:   Defines Application Frame
 * Author:    Wayne M. Galen (jummama@gmail.com)
 * Created:   2010-11-23
 * Copyright: Wayne M. Galen ()
 * License:
 **************************************************************/

#ifndef WXSTAGEKITMAIN_H
#define WXSTAGEKITMAIN_H

//(*Headers(wxStagekitFrame)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class wxStagekitFrame: public wxFrame
{
    public:

        wxStagekitFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxStagekitFrame();

    private:

        //(*Handlers(wxStagekitFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanic(wxCommandEvent& event);
        void OnSlider1CmdScroll(wxScrollEvent& event);
        void OnStrobeSliderCmdScroll(wxScrollEvent& event);
        void OnbtnFogClick(wxCommandEvent& event);
        void OnRadioButton5Select(wxCommandEvent& event);
        void OnStrobeOffSelect(wxCommandEvent& event);
        void OnStrobeSlowSelect(wxCommandEvent& event);
        void OnStrobeMedSelect(wxCommandEvent& event);
        void OnStrobeFastSelect(wxCommandEvent& event);
        void OnStrobeFastestSelect(wxCommandEvent& event);
        void OnbtnPanicClick(wxCommandEvent& event);
        void Onr0Click(wxCommandEvent& event);
        void Onr1Click(wxCommandEvent& event);
        void Onr2Click(wxCommandEvent& event);
        void Onr3Click(wxCommandEvent& event);
        void Onr4Click(wxCommandEvent& event);
        void Onr5Click(wxCommandEvent& event);
        void Onr6Click(wxCommandEvent& event);
        void Onr7Click(wxCommandEvent& event);
        void OnchkFogClick(wxCommandEvent& event);
        void Ony0Click(wxCommandEvent& event);
        void Ony1Click(wxCommandEvent& event);
        void Ony2Click(wxCommandEvent& event);
        void Ony3Click(wxCommandEvent& event);
        void Ony4Click(wxCommandEvent& event);
        void Ony5Click(wxCommandEvent& event);
        void Ony6Click(wxCommandEvent& event);
        void Ony7Click(wxCommandEvent& event);
        void Ong0Click(wxCommandEvent& event);
        void Ong1Click(wxCommandEvent& event);
        void Ong2Click(wxCommandEvent& event);
        void Ong3Click(wxCommandEvent& event);
        void Ong4Click(wxCommandEvent& event);
        void Ong5Click(wxCommandEvent& event);
        void Ong6Click(wxCommandEvent& event);
        void Ong7Click(wxCommandEvent& event);
        void Onb0Click(wxCommandEvent& event);
        void Onb1Click(wxCommandEvent& event);
        void Onb2Click(wxCommandEvent& event);
        void Onb3Click(wxCommandEvent& event);
        void Onb4Click(wxCommandEvent& event);
        void Onb5Click(wxCommandEvent& event);
        void Onb6Click(wxCommandEvent& event);
        void Onb7Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxStagekitFrame)
        static const long ID_R0;
        static const long ID_R1;
        static const long ID_R2;
        static const long ID_R3;
        static const long ID_R4;
        static const long ID_R5;
        static const long ID_R6;
        static const long ID_R7;
        static const long ID_STATICTEXT1;
        static const long ID_Y0;
        static const long ID_Y1;
        static const long ID_Y2;
        static const long ID_Y3;
        static const long ID_Y4;
        static const long ID_Y5;
        static const long ID_Y6;
        static const long ID_Y7;
        static const long ID_STATICTEXT2;
        static const long ID_CHECKBOX17;
        static const long ID_G1;
        static const long ID_G2;
        static const long ID_G3;
        static const long ID_G4;
        static const long ID_CHECKBOX22;
        static const long ID_G6;
        static const long ID_G7;
        static const long ID_STATICTEXT3;
        static const long ID_B0;
        static const long ID_B1;
        static const long ID_B2;
        static const long ID_B3;
        static const long ID_B4;
        static const long ID_B5;
        static const long ID_B6;
        static const long ID_B7;
        static const long ID_STATICTEXT4;
        static const long ID_STROBEOFF;
        static const long ID_STROBESLOW;
        static const long ID_STROBEMED;
        static const long ID_STROBEFAST;
        static const long ID_STROBEFASTEST;
        static const long ID_STATICTEXT5;
        static const long ID_PANIC;
        static const long ID_FOG;
        //*)

        //(*Declarations(wxStagekitFrame)
        wxCheckBox* b3;
        wxCheckBox* y7;
        wxCheckBox* y3;
        wxCheckBox* g3;
        wxCheckBox* b5;
        wxCheckBox* r0;
        wxCheckBox* r3;
        wxCheckBox* y4;
        wxCheckBox* b1;
        wxCheckBox* r1;
        wxButton* btnPanic;
        wxCheckBox* y0;
        wxCheckBox* b2;
        wxRadioButton* StrobeFastest;
        wxCheckBox* b0;
        wxCheckBox* g4;
        wxCheckBox* r4;
        wxCheckBox* g2;
        wxStaticText* StaticText1;
        wxCheckBox* r7;
        wxCheckBox* y6;
        wxStaticText* StaticText3;
        wxCheckBox* g5;
        wxCheckBox* g6;
        wxCheckBox* r2;
        wxCheckBox* y1;
        wxCheckBox* b7;
        wxCheckBox* g0;
        wxCheckBox* chkFog;
        wxRadioButton* StrobeSlow;
        wxCheckBox* g7;
        wxRadioButton* StrobeFast;
        wxStaticText* StaticText4;
        wxRadioButton* StrobeMed;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxCheckBox* y5;
        wxCheckBox* y2;
        wxCheckBox* r5;
        wxCheckBox* b6;
        wxCheckBox* b4;
        wxRadioButton* StrobeOff;
        wxCheckBox* g1;
        wxCheckBox* r6;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSTAGEKITMAIN_H
