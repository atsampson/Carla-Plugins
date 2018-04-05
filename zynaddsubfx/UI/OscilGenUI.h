// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef OscilGenUI_h
#define OscilGenUI_h
#include <FL/Fl.H>
#include "../Synth/OscilGen.h"
#include "../Misc/Util.h"
#include "ResonanceUI.h"
#include "Fl_Oscilloscope.h"
#include "Fl_OscilSpectrum.h"
#include "Fl_Osc_Interface.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Slider.H>
#include "Fl_Osc_Pane.H"
#include "Fl_Osc_Dial.H"
#include "Fl_Osc_Choice.H"
#include "Fl_Osc_Counter.H"
#include "Fl_Osc_TSlider.H"
#include "Fl_Osc_VSlider.H"
#include "PresetsUI.h"
#include <FL/fl_draw.H>
using namespace zyncarla;

class OGSlider : public Fl_Osc_TSlider {
public:
  OGSlider(int x,int y, int w, int h, const char *label=0)
  ;
  void OSC_value(char c);
  void cb(void);
  void update(void);
  bool phase; 
};

class OGWaveChoice : public Fl_Osc_Choice {
public:
  OGWaveChoice(int x,int y, int w, int h, const char *label=0)
   ;
  void OSC_value(int i);
  void cb(void);
  class OscilEditor *ogui;
};
#include <FL/Fl_Box.H>

class Oscilharmonic : public Fl_Group {
  Fl_Osc_Group* make_window();
  Fl_Osc_Group *harmonic;
public:
  OGSlider *mag;
private:
  void cb_mag_i(OGSlider*, void*);
  static void cb_mag(OGSlider*, void*);
public:
  OGSlider *phase;
private:
  void cb_phase_i(OGSlider*, void*);
  static void cb_phase(OGSlider*, void*);
public:
  Oscilharmonic(int x,int y, int w, int h, const char *label=0);
  void init(int n_,Fl_Group *display_, std::string loc_, Fl_Osc_Interface *osc_);
  void refresh();
  ~Oscilharmonic();
private:
  Fl_Group *display; 
  int n; 
  Fl_Osc_Interface *osc; 
  std::string loc; 
};
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Pack.H>

class OscilEditor : public PresetsUI_ {
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *osceditUI;
  Fl_Osc_Group *dummy;
  Fl_Button *applybutton;
private:
  void cb_applybutton_i(Fl_Button*, void*);
  static void cb_applybutton(Fl_Button*, void*);
public:
  Fl_Group *oscildisplaygroup;
  Fl_Osc_VSlider *rndslider;
  Fl_Osc_Choice *hrndtype;
  static Fl_Menu_Item menu_hrndtype[];
  Fl_Osc_Dial *hrnddial;
  Fl_Osc_Choice *magtype;
private:
  void cb_magtype_i(Fl_Osc_Choice*, void*);
  static void cb_magtype(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_magtype[];
public:
  Fl_Osc_Group *basefuncdisplaygroup;
  Fl_Osc_Dial *bfpar;
private:
  void cb_bfpar_i(Fl_Osc_Dial*, void*);
  static void cb_bfpar(Fl_Osc_Dial*, void*);
public:
  OGWaveChoice *bftype;
private:
  void cb_bftype_i(OGWaveChoice*, void*);
  static void cb_bftype(OGWaveChoice*, void*);
  static Fl_Menu_Item menu_bftype[];
public:
  Fl_Value_Output *bfparval;
  Fl_Group *basefuncmodulation;
  Fl_Osc_Choice *bfmodtype;
private:
  void cb_bfmodtype_i(Fl_Osc_Choice*, void*);
  static void cb_bfmodtype(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_bfmodtype[];
public:
  Fl_Osc_Dial *bfmodpar1;
private:
  void cb_bfmodpar1_i(Fl_Osc_Dial*, void*);
  static void cb_bfmodpar1(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Dial *bfmodpar2;
private:
  void cb_bfmodpar2_i(Fl_Osc_Dial*, void*);
  static void cb_bfmodpar2(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Dial *bfmodpar3;
private:
  void cb_bfmodpar3_i(Fl_Osc_Dial*, void*);
  static void cb_bfmodpar3(Fl_Osc_Dial*, void*);
  void cb_Use_i(Fl_Button*, void*);
  static void cb_Use(Fl_Button*, void*);
  void cb_Close_i(Fl_Button*, void*);
  static void cb_Close(Fl_Button*, void*);
  void cb_Clear_i(Fl_Button*, void*);
  static void cb_Clear(Fl_Button*, void*);
public:
  Fl_Osc_Choice *wshbutton;
private:
  void cb_wshbutton_i(Fl_Osc_Choice*, void*);
  static void cb_wshbutton(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_wshbutton[];
public:
  Fl_Osc_Dial *wshpar;
private:
  void cb_wshpar_i(Fl_Osc_Dial*, void*);
  static void cb_wshpar(Fl_Osc_Dial*, void*);
public:
  Fl_Value_Output *wsparval;
  Fl_Check_Button *autoclearbutton;
  Fl_Osc_Choice *fltbutton;
private:
  void cb_fltbutton_i(Fl_Osc_Choice*, void*);
  static void cb_fltbutton(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_fltbutton[];
public:
  Fl_Osc_Dial *filtervalue1;
private:
  void cb_filtervalue1_i(Fl_Osc_Dial*, void*);
  static void cb_filtervalue1(Fl_Osc_Dial*, void*);
public:
  Fl_Check_Button *filterpref;
private:
  void cb_filterpref_i(Fl_Check_Button*, void*);
  static void cb_filterpref(Fl_Check_Button*, void*);
public:
  Fl_Osc_Dial *filtervalue2;
private:
  void cb_filtervalue2_i(Fl_Osc_Dial*, void*);
  static void cb_filtervalue2(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Choice *sabutton;
private:
  void cb_sabutton_i(Fl_Osc_Choice*, void*);
  static void cb_sabutton(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_sabutton[];
public:
  Fl_Osc_Dial *sadjpar;
private:
  void cb_sadjpar_i(Fl_Osc_Dial*, void*);
  static void cb_sadjpar(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Counter *harmonicshiftcounter;
private:
  void cb_harmonicshiftcounter_i(Fl_Osc_Counter*, void*);
  static void cb_harmonicshiftcounter(Fl_Osc_Counter*, void*);
public:
  Fl_Osc_Check *harmonicshiftpre;
private:
  void cb_harmonicshiftpre_i(Fl_Osc_Check*, void*);
  static void cb_harmonicshiftpre(Fl_Osc_Check*, void*);
  void cb_R_i(Fl_Button*, void*);
  static void cb_R(Fl_Button*, void*);
public:
  Fl_Osc_Choice *adhrtype;
private:
  void cb_adhrtype_i(Fl_Osc_Choice*, void*);
  static void cb_adhrtype(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_adhrtype[];
public:
  Fl_Osc_Dial *adhrpow;
private:
  void cb_adhrpow_i(Fl_Osc_Dial*, void*);
  static void cb_adhrpow(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Dial *adhrbf;
private:
  void cb_adhrbf_i(Fl_Osc_Dial*, void*);
  static void cb_adhrbf(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_TSlider *adhrpar;
private:
  void cb_adhrpar_i(Fl_Osc_TSlider*, void*);
  static void cb_adhrpar(Fl_Osc_TSlider*, void*);
public:
  Fl_Osc_Choice *modtype;
private:
  void cb_modtype_i(Fl_Osc_Choice*, void*);
  static void cb_modtype(Fl_Osc_Choice*, void*);
  static Fl_Menu_Item menu_modtype[];
public:
  Fl_Osc_Dial *modpar1;
private:
  void cb_modpar1_i(Fl_Osc_Dial*, void*);
  static void cb_modpar1(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Dial *modpar2;
private:
  void cb_modpar2_i(Fl_Osc_Dial*, void*);
  static void cb_modpar2(Fl_Osc_Dial*, void*);
public:
  Fl_Osc_Dial *modpar3;
private:
  void cb_modpar3_i(Fl_Osc_Dial*, void*);
  static void cb_modpar3(Fl_Osc_Dial*, void*);
  void cb_Sine_i(Fl_Button*, void*);
  static void cb_Sine(Fl_Button*, void*);
  void cb_C_i(Fl_Button*, void*);
  static void cb_C(Fl_Button*, void*);
  void cb_P_i(Fl_Button*, void*);
  static void cb_P(Fl_Button*, void*);
public:
  Fl_Scroll *_this_has_to_be_the_last;
  Fl_Pack *harmonics;
  OscilEditor(bool adnotep_, std::string loc_, Fl_Osc_Interface *osc_);
  ~OscilEditor();
  void refresh();
  void redrawoscil();
  void setbfmodstatus(int menuentry);
private:
  Oscilharmonic *h[(MAX_AD_HARMONICS - 1)]; 
  std::string loc; 
  Fl_Osc_Interface *osc; 
  Fl_Oscilloscope *oscilo, *oscilo_base; 
  Fl_OscilSpectrum *oscils, *oscils_base; 
  bool adnotep; 
  bool initialized; 
};
#endif