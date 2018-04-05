// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "external/zynaddsubfx/UI/SUBnoteUI.h"
//Copyright (c) 2002-2005 Nasca Octavian Paul
//License: GNU GPL version 2 or later

SUBSlider::SUBSlider(int x,int y, int w, int h, const char *label)
  :Fl_Osc_TSlider(x,y,w,h,label) {
}

void SUBSlider::OSC_value(char c) {
  value(127-c);
         selection_color(value() == reset_value ? 0 : 222);
}

void SUBSlider::cb(void) {
  selection_color(value() == reset_value ? 0 : 222);	
  	oscWrite(ext, "c", (int)(127-Fl_Slider::value()));
  	if(cb_data.first)
  	    cb_data.first(this, cb_data.second);
}

Fl_Osc_Group* SUBnoteharmonic::make_window() {
  { harmonic = new Fl_Osc_Group(0, 0, 90, 305);
    harmonic->box(FL_FLAT_BOX);
    harmonic->color(FL_BACKGROUND_COLOR);
    harmonic->selection_color(FL_BACKGROUND_COLOR);
    harmonic->labeltype(FL_NO_LABEL);
    harmonic->labelfont(0);
    harmonic->labelsize(14);
    harmonic->labelcolor(FL_FOREGROUND_COLOR);
    harmonic->user_data((void*)(this));
    harmonic->align(Fl_Align(FL_ALIGN_TOP));
    harmonic->when(FL_WHEN_RELEASE);
    { mag = new SUBSlider(0, 15, 10, 135);
      mag->tooltip("harmonic\'s magnitude");
      mag->type(4);
      mag->box(FL_FLAT_BOX);
      mag->color(FL_BACKGROUND_COLOR);
      mag->selection_color(FL_FOREGROUND_COLOR);
      mag->labeltype(FL_NORMAL_LABEL);
      mag->labelfont(0);
      mag->labelsize(14);
      mag->labelcolor(FL_FOREGROUND_COLOR);
      mag->maximum(127);
      mag->step(1);
      mag->value(127);
      mag->align(Fl_Align(FL_ALIGN_BOTTOM));
      mag->when(FL_WHEN_CHANGED);
    } // SUBSlider* mag
    { bw = new SUBSlider(0, 157, 10, 130);
      bw->tooltip("harmonic\'s bandwidth");
      bw->type(4);
      bw->box(FL_FLAT_BOX);
      bw->color(FL_BACKGROUND_COLOR);
      bw->selection_color((Fl_Color)222);
      bw->labeltype(FL_NORMAL_LABEL);
      bw->labelfont(0);
      bw->labelsize(14);
      bw->labelcolor(FL_FOREGROUND_COLOR);
      bw->maximum(127);
      bw->step(1);
      bw->value(64);
      bw->align(Fl_Align(FL_ALIGN_BOTTOM));
      bw->when(FL_WHEN_CHANGED);
    } // SUBSlider* bw
    { Fl_Box* o = new Fl_Box(10, 219, 5, 5);
      o->box(FL_FLAT_BOX);
      o->color(FL_DARK2);
      if (n+1==MAX_SUB_HARMONICS) o->hide();
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(0, 288, 10, 15, "01");
      o->labelfont(1);
      o->labelsize(9);
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
      char tmp[10];snprintf(tmp,10,"%d",n+1);o->label(strdup(tmp));
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(0, 0, 10, 15, "01");
      o->labelfont(1);
      o->labelsize(9);
      o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
      char tmp[10];snprintf(tmp,10,"%d",n+1);o->label(strdup(tmp));
    } // Fl_Box* o
    harmonic->end();
  } // Fl_Osc_Group* harmonic
  return harmonic;
}

SUBnoteharmonic::SUBnoteharmonic(int x,int y, int w, int h, const char *label):Fl_Osc_Group(x,y,w,h,label) {
  n=0;
}

void SUBnoteharmonic::init(int n_) {
  n=n_;
  make_window();
  harmonic->show();
  mag->reset_value=127;
  mag->ext = "Phmag" + to_s(n);
  mag->oscRegister(mag->ext.c_str());
  mag->set_transform([](float x){return 127.0f - x;});
  bw->reset_value=63;
  bw->ext = "Phrelbw" + to_s(n);
  bw->oscRegister(bw->ext.c_str());
  bw->set_transform([](float x){return 63.0f - x;});
  osc->requestValue(base+"Phrelbw"+to_s(n));
  
  end();
}

void SUBnoteharmonic::refresh() {
  // request values for the widgets
  mag->oscWrite(mag->ext);
  bw->oscWrite(bw->ext);
}

SUBnoteharmonic::~SUBnoteharmonic() {
  harmonic->hide();
  hide();
  //delete(harmonic);
}

void SUBnoteUI::cb_Close_i(Fl_Button*, void*) {
  SUBparameters->hide();
}
void SUBnoteUI::cb_Close(Fl_Button* o, void* v) {
  ((SUBnoteUI*)(o->parent()->user_data()))->cb_Close_i(o,v);
}

Fl_Menu_Item SUBnoteUI::menu_magtype[] = {
 {"Linear", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"-40dB", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"-60dB", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"-80dB", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"-100dB", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Menu_Item SUBnoteUI::menu_start[] = {
 {"Zero", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"RND", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"Max.", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

void SUBnoteUI::cb_freqee_i(Fl_Osc_Check* o, void*) {
  if (o->value()==0) freqenvelopegroup->deactivate();
              else freqenvelopegroup->activate();
o->show();
freqsettingsui->redraw();
}
void SUBnoteUI::cb_freqee(Fl_Osc_Check* o, void* v) {
  ((SUBnoteUI*)(o->parent()->parent()->user_data()))->cb_freqee_i(o,v);
}

void SUBnoteUI::cb_detune_i(Fl_Osc_Slider* o, void*) {
  o->oscWrite("detunevalue");
}
void SUBnoteUI::cb_detune(Fl_Osc_Slider* o, void* v) {
  ((SUBnoteUI*)(o->parent()->parent()->user_data()))->cb_detune_i(o,v);
}

void SUBnoteUI::cb_hz440_i(Fl_Osc_Check* o, void*) {
  if (o->value()==0) fixedfreqetdial->deactivate();
   else fixedfreqetdial->activate();
}
void SUBnoteUI::cb_hz440(Fl_Osc_Check* o, void* v) {
  ((SUBnoteUI*)(o->parent()->parent()->user_data()))->cb_hz440_i(o,v);
}

void SUBnoteUI::cb_detunetype_i(Fl_Osc_Choice* o, void*) {
  o->oscWrite("detunevalue");
}
void SUBnoteUI::cb_detunetype(Fl_Osc_Choice* o, void* v) {
  ((SUBnoteUI*)(o->parent()->parent()->user_data()))->cb_detunetype_i(o,v);
}

void SUBnoteUI::cb_Clear_i(Fl_Osc_Button* o, void*) {
  o->oscWrite("clear");
        for (int i=1;i<MAX_SUB_HARMONICS;i++){
    h[i]->mag->oscWrite(h[i]->mag->ext, "c", 0);
    h[i]->bw->oscWrite(h[i]->bw->ext, "c", 64);
};
h[0]->mag->oscWrite(h[0]->mag->ext, "c", 127);
h[0]->bw->oscWrite(h[0]->bw->ext, "c", 64);
SUBparameters->redraw();
}
void SUBnoteUI::cb_Clear(Fl_Osc_Button* o, void* v) {
  ((SUBnoteUI*)(o->parent()->user_data()))->cb_Clear_i(o,v);
}

void SUBnoteUI::cb_bwee_i(Fl_Osc_Check* o, void*) {
  if (o->value()==0) bandwidthenvelopegroup->deactivate();
    else bandwidthenvelopegroup->activate();
o->show();
bandwidthsettingsui->redraw();
}
void SUBnoteUI::cb_bwee(Fl_Osc_Check* o, void* v) {
  ((SUBnoteUI*)(o->parent()->parent()->user_data()))->cb_bwee_i(o,v);
}

void SUBnoteUI::cb_filtere_i(Fl_Osc_Check* o, void*) {
  if (o->value()==0) globalfiltergroup->deactivate();
    else globalfiltergroup->activate();
o->show();
globalfiltergroup->redraw();
}
void SUBnoteUI::cb_filtere(Fl_Osc_Check* o, void* v) {
  ((SUBnoteUI*)(o->parent()->user_data()))->cb_filtere_i(o,v);
}

void SUBnoteUI::cb_C_i(Fl_Button*, void*) {
  presetsui->copy(loc);
}
void SUBnoteUI::cb_C(Fl_Button* o, void* v) {
  ((SUBnoteUI*)(o->parent()->user_data()))->cb_C_i(o,v);
}

void SUBnoteUI::cb_P_i(Fl_Button*, void*) {
  presetsui->paste(loc,this);
}
void SUBnoteUI::cb_P(Fl_Button* o, void* v) {
  ((SUBnoteUI*)(o->parent()->user_data()))->cb_P_i(o,v);
}

Fl_Menu_Item SUBnoteUI::menu_spreadtype[] = {
 {"Harmonic", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"ShiftU", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"ShiftL", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"PowerU", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"PowerL", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"Sine", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"Power", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {"Shift", 0,  0, 0, 0, FL_NORMAL_LABEL, 1, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Osc_Window* SUBnoteUI::make_window() {
  { SUBparameters = new Fl_Osc_Window(735, 475, "SUBsynth Parameters");
    SUBparameters->box(FL_FLAT_BOX);
    SUBparameters->color(FL_BACKGROUND_COLOR);
    SUBparameters->selection_color(FL_BACKGROUND_COLOR);
    SUBparameters->labeltype(FL_NO_LABEL);
    SUBparameters->labelfont(0);
    SUBparameters->labelsize(14);
    SUBparameters->labelcolor(FL_FOREGROUND_COLOR);
    SUBparameters->user_data((void*)(this));
    SUBparameters->align(Fl_Align(FL_ALIGN_TOP));
    SUBparameters->when(FL_WHEN_RELEASE);
    { Fl_Box* o = new Fl_Box(0, 0, 0, 0);
      o->box(FL_FLAT_BOX);
      o->color(FL_DARK2);
      SUBparameters->init(osc, loc);
    } // Fl_Box* o
    { Fl_Scroll* o = new Fl_Scroll(5, 140, 434, 330, "scroll");
      o->type(1);
      o->box(FL_FLAT_BOX);
      o->labeltype(FL_NO_LABEL);
      { Fl_Pack* o = harmonics = new Fl_Pack(5, 145, 425, 325);
        harmonics->type(1);
        for (int i=0;i<MAX_SUB_HARMONICS;i++){h[i]=new SUBnoteharmonic(0,0,15,o->h(),"");h[i]->init(i);}
        harmonics->end();
      } // Fl_Pack* harmonics
      o->end();
    } // Fl_Scroll* o
    { Fl_Button* o = new Fl_Button(670, 446, 60, 25, "Close");
      o->box(FL_THIN_UP_BOX);
      o->callback((Fl_Callback*)cb_Close);
    } // Fl_Button* o
    { Fl_Group* o = new Fl_Group(5, 5, 215, 135, "AMPLITUDE");
      o->box(FL_UP_FRAME);
      o->labeltype(FL_EMBOSSED_LABEL);
      o->labelfont(1);
      o->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
      { Fl_Osc_VSlider* o = vol = new Fl_Osc_VSlider(10, 25, 140, 15, "Vol");
        vol->tooltip("Volume");
        vol->type(5);
        vol->box(FL_NO_BOX);
        vol->color(FL_BACKGROUND_COLOR);
        vol->selection_color(FL_BACKGROUND_COLOR);
        vol->labeltype(FL_NORMAL_LABEL);
        vol->labelfont(0);
        vol->labelsize(11);
        vol->labelcolor(FL_FOREGROUND_COLOR);
        vol->maximum(127);
        vol->step(1);
        vol->align(Fl_Align(FL_ALIGN_RIGHT));
        vol->when(FL_WHEN_CHANGED);
        o->init("PVolume");o->reset_value=96;
      } // Fl_Osc_VSlider* vol
      { Fl_Osc_VSlider* o = vsns = new Fl_Osc_VSlider(10, 45, 140, 15, "V.Sns");
        vsns->tooltip("Velocity Sensing Function (rightmost to disable)");
        vsns->type(5);
        vsns->box(FL_NO_BOX);
        vsns->color(FL_BACKGROUND_COLOR);
        vsns->selection_color(FL_BACKGROUND_COLOR);
        vsns->labeltype(FL_NORMAL_LABEL);
        vsns->labelfont(0);
        vsns->labelsize(11);
        vsns->labelcolor(FL_FOREGROUND_COLOR);
        vsns->maximum(127);
        vsns->step(1);
        vsns->align(Fl_Align(FL_ALIGN_RIGHT));
        vsns->when(FL_WHEN_CHANGED);
        o->init("PAmpVelocityScaleFunction");o->reset_value=90;
      } // Fl_Osc_VSlider* vsns
      { Fl_Osc_Dial* o = pan = new Fl_Osc_Dial(185, 20, 30, 30, "Pan");
        pan->tooltip("Panning (leftmost is Random)");
        pan->box(FL_ROUND_UP_BOX);
        pan->color(FL_BACKGROUND_COLOR);
        pan->selection_color(FL_INACTIVE_COLOR);
        pan->labeltype(FL_NORMAL_LABEL);
        pan->labelfont(0);
        pan->labelsize(10);
        pan->labelcolor(FL_FOREGROUND_COLOR);
        pan->maximum(127);
        pan->step(1);
        pan->align(Fl_Align(FL_ALIGN_BOTTOM));
        pan->when(FL_WHEN_CHANGED);
        o->init("PPanning");o->reset_value=64;
      } // Fl_Osc_Dial* pan
      { EnvelopeUI* o = ampenv = new EnvelopeUI(10, 65, 205, 70, "SUBsynth - Amplitude Envelope");
        ampenv->box(FL_FLAT_BOX);
        ampenv->color((Fl_Color)51);
        ampenv->selection_color(FL_BACKGROUND_COLOR);
        ampenv->labeltype(FL_NORMAL_LABEL);
        ampenv->labelfont(0);
        ampenv->labelsize(14);
        ampenv->labelcolor(FL_FOREGROUND_COLOR);
        ampenv->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
        ampenv->when(FL_WHEN_RELEASE);
        o->init(ENV_ADSR, osc, loc, "AmpEnvelope/");
        ampenv->end();
      } // EnvelopeUI* ampenv
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(495, 406, 235, 35);
      o->box(FL_UP_FRAME);
      { Fl_Osc_Counter* o = filterstages = new Fl_Osc_Counter(515, 421, 45, 15, "Filter Stages");
        filterstages->tooltip("How many times the noise is filtered");
        filterstages->type(1);
        filterstages->box(FL_UP_BOX);
        filterstages->color(FL_BACKGROUND_COLOR);
        filterstages->selection_color(FL_INACTIVE_COLOR);
        filterstages->labeltype(FL_NORMAL_LABEL);
        filterstages->labelfont(1);
        filterstages->labelsize(10);
        filterstages->labelcolor(FL_FOREGROUND_COLOR);
        filterstages->minimum(1);
        filterstages->maximum(5);
        filterstages->step(1);
        filterstages->textsize(10);
        filterstages->align(Fl_Align(FL_ALIGN_TOP));
        filterstages->when(FL_WHEN_CHANGED);
        o->init("Pnumstages");
      } // Fl_Osc_Counter* filterstages
      { Fl_Osc_Choice* o = magtype = new Fl_Osc_Choice(585, 421, 65, 15, "Mag.Type");
        magtype->box(FL_UP_BOX);
        magtype->down_box(FL_BORDER_BOX);
        magtype->color(FL_BACKGROUND_COLOR);
        magtype->selection_color(FL_SELECTION_COLOR);
        magtype->labeltype(FL_NORMAL_LABEL);
        magtype->labelfont(1);
        magtype->labelsize(10);
        magtype->labelcolor(FL_FOREGROUND_COLOR);
        magtype->textsize(11);
        magtype->align(Fl_Align(FL_ALIGN_TOP));
        magtype->when(FL_WHEN_RELEASE);
        magtype->menu(menu_magtype);
        o->init("Phmagtype");
      } // Fl_Osc_Choice* magtype
      { Fl_Osc_Choice* o = start = new Fl_Osc_Choice(670, 420, 50, 15, "Start");
        start->box(FL_UP_BOX);
        start->down_box(FL_BORDER_BOX);
        start->color(FL_BACKGROUND_COLOR);
        start->selection_color(FL_SELECTION_COLOR);
        start->labeltype(FL_NORMAL_LABEL);
        start->labelfont(1);
        start->labelsize(10);
        start->labelcolor(FL_FOREGROUND_COLOR);
        start->textsize(11);
        start->align(Fl_Align(FL_ALIGN_TOP));
        start->when(FL_WHEN_RELEASE);
        start->menu(menu_start);
        o->init("Pstart");
      } // Fl_Osc_Choice* start
      o->end();
    } // Fl_Group* o
    { freqsettingsui = new Fl_Group(440, 5, 295, 146, "FREQUENCY");
      freqsettingsui->box(FL_UP_FRAME);
      freqsettingsui->labeltype(FL_EMBOSSED_LABEL);
      freqsettingsui->labelfont(1);
      freqsettingsui->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
      { EnvelopeUI* o = freqenvelopegroup = new EnvelopeUI(445, 75, 205, 70, "SUBsynth - Frequency Envelope");
        freqenvelopegroup->box(FL_FLAT_BOX);
        freqenvelopegroup->color((Fl_Color)51);
        freqenvelopegroup->selection_color(FL_BACKGROUND_COLOR);
        freqenvelopegroup->labeltype(FL_NORMAL_LABEL);
        freqenvelopegroup->labelfont(0);
        freqenvelopegroup->labelsize(14);
        freqenvelopegroup->labelcolor(FL_FOREGROUND_COLOR);
        freqenvelopegroup->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
        freqenvelopegroup->when(FL_WHEN_RELEASE);
        o->init(ENV_ASR, osc, loc, "FreqEnvelope/");
        freqenvelopegroup->end();
      } // EnvelopeUI* freqenvelopegroup
      { Fl_Osc_Check* o = freqee = new Fl_Osc_Check(445, 77, 55, 15, "Enabled");
        freqee->box(FL_NO_BOX);
        freqee->down_box(FL_DOWN_BOX);
        freqee->color(FL_BACKGROUND_COLOR);
        freqee->selection_color(FL_FOREGROUND_COLOR);
        freqee->labeltype(FL_NORMAL_LABEL);
        freqee->labelfont(1);
        freqee->labelsize(10);
        freqee->labelcolor(FL_FOREGROUND_COLOR);
        freqee->callback((Fl_Callback*)cb_freqee);
        freqee->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
        freqee->when(FL_WHEN_RELEASE);
        o->init("PFreqEnvelopeEnabled");
      } // Fl_Osc_Check* freqee
      { Fl_Osc_Counter* o = octave = new Fl_Osc_Counter(670, 58, 45, 15, "Octave");
        octave->tooltip("Octave");
        octave->type(1);
        octave->box(FL_UP_BOX);
        octave->color(FL_BACKGROUND_COLOR);
        octave->selection_color(FL_INACTIVE_COLOR);
        octave->labeltype(FL_NORMAL_LABEL);
        octave->labelfont(0);
        octave->labelsize(10);
        octave->labelcolor(FL_FOREGROUND_COLOR);
        octave->minimum(-8);
        octave->maximum(7);
        octave->step(1);
        octave->textfont(1);
        octave->textsize(11);
        octave->align(Fl_Align(FL_ALIGN_TOP));
        octave->when(FL_WHEN_CHANGED);
        o->init("octave");
      } // Fl_Osc_Counter* octave
      { Fl_Osc_Counter* o = coarsedet = new Fl_Osc_Counter(655, 125, 60, 20, "Coarse Det.");
        coarsedet->tooltip("Coarse Detune");
        coarsedet->box(FL_UP_BOX);
        coarsedet->color(FL_BACKGROUND_COLOR);
        coarsedet->selection_color(FL_INACTIVE_COLOR);
        coarsedet->labeltype(FL_NORMAL_LABEL);
        coarsedet->labelfont(0);
        coarsedet->labelsize(10);
        coarsedet->labelcolor(FL_FOREGROUND_COLOR);
        coarsedet->minimum(-64);
        coarsedet->maximum(63);
        coarsedet->step(1);
        coarsedet->textfont(1);
        coarsedet->textsize(11);
        coarsedet->align(Fl_Align(FL_ALIGN_TOP));
        coarsedet->when(FL_WHEN_CHANGED);
        o->init("coarsedetune");
        o->lstep(10);
      } // Fl_Osc_Counter* coarsedet
      { Fl_Osc_Slider* o = detune = new Fl_Osc_Slider(495, 27, 230, 15);
        detune->tooltip("Fine Detune (cents)");
        detune->type(5);
        detune->box(FL_NO_BOX);
        detune->color(FL_BACKGROUND_COLOR);
        detune->selection_color(FL_BACKGROUND_COLOR);
        detune->labeltype(FL_NORMAL_LABEL);
        detune->labelfont(0);
        detune->labelsize(14);
        detune->labelcolor(FL_FOREGROUND_COLOR);
        detune->minimum(-8192);
        detune->maximum(8191);
        detune->step(1);
        detune->callback((Fl_Callback*)cb_detune);
        detune->align(Fl_Align(FL_ALIGN_BOTTOM));
        detune->when(FL_WHEN_CHANGED);
        o->init("PDetune",'i');
      } // Fl_Osc_Slider* detune
      { Fl_Osc_Output* o = detunevalueoutput = new Fl_Osc_Output(448, 27, 45, 15, "Detune");
        detunevalueoutput->box(FL_NO_BOX);
        detunevalueoutput->color(FL_BACKGROUND_COLOR);
        detunevalueoutput->selection_color(FL_BACKGROUND_COLOR);
        detunevalueoutput->labeltype(FL_NORMAL_LABEL);
        detunevalueoutput->labelfont(0);
        detunevalueoutput->labelsize(10);
        detunevalueoutput->labelcolor(FL_FOREGROUND_COLOR);
        detunevalueoutput->minimum(-5000);
        detunevalueoutput->maximum(5000);
        detunevalueoutput->step(0.01);
        detunevalueoutput->textfont(1);
        detunevalueoutput->textsize(10);
        detunevalueoutput->align(Fl_Align(FL_ALIGN_TOP_LEFT));
        detunevalueoutput->when(FL_WHEN_CHANGED);
        o->init("detunevalue");
      } // Fl_Osc_Output* detunevalueoutput
      { Fl_Osc_Dial* o = bendadjdial = new Fl_Osc_Dial(448, 53, 15, 15, "Bend");
        bendadjdial->tooltip("How the frequency varies according to the pitch wheel");
        bendadjdial->box(FL_ROUND_UP_BOX);
        bendadjdial->color(FL_BACKGROUND_COLOR);
        bendadjdial->selection_color(FL_INACTIVE_COLOR);
        bendadjdial->labeltype(FL_NORMAL_LABEL);
        bendadjdial->labelfont(0);
        bendadjdial->labelsize(10);
        bendadjdial->labelcolor(FL_FOREGROUND_COLOR);
        bendadjdial->minimum(-64);
        bendadjdial->maximum(63);
        bendadjdial->step(1);
        bendadjdial->align(Fl_Align(FL_ALIGN_RIGHT));
        bendadjdial->when(FL_WHEN_CHANGED);
        o->init("PBendAdjust"); o->reset_value=24;o->set_transform([](float x){return x/24.0f;});o->set_rounding(2);
      } // Fl_Osc_Dial* bendadjdial
      { Fl_Osc_Dial* o = offsethzdial = new Fl_Osc_Dial(500, 53, 15, 15, "Offset");
        offsethzdial->tooltip("Offset of frequency in Hz");
        offsethzdial->box(FL_ROUND_UP_BOX);
        offsethzdial->color(FL_BACKGROUND_COLOR);
        offsethzdial->selection_color(FL_INACTIVE_COLOR);
        offsethzdial->labeltype(FL_NORMAL_LABEL);
        offsethzdial->labelfont(0);
        offsethzdial->labelsize(10);
        offsethzdial->labelcolor(FL_FOREGROUND_COLOR);
        offsethzdial->minimum(-64);
        offsethzdial->maximum(63);
        offsethzdial->step(1);
        offsethzdial->align(Fl_Align(FL_ALIGN_RIGHT));
        offsethzdial->when(FL_WHEN_CHANGED);
        o->init("POffsetHz"); o->set_rounding(2); o->set_transform([](float x){x/=64; return 15*(x*sqrtf(fabsf(x)));});
      } // Fl_Osc_Dial* offsethzdial
      { Fl_Osc_Check* o = hz440 = new Fl_Osc_Check(555, 53, 50, 15, "440Hz");
        hz440->tooltip("set the base frequency to 440Hz");
        hz440->box(FL_NO_BOX);
        hz440->down_box(FL_DOWN_BOX);
        hz440->color(FL_BACKGROUND_COLOR);
        hz440->selection_color(FL_FOREGROUND_COLOR);
        hz440->labeltype(FL_NORMAL_LABEL);
        hz440->labelfont(1);
        hz440->labelsize(10);
        hz440->labelcolor(FL_FOREGROUND_COLOR);
        hz440->callback((Fl_Callback*)cb_hz440);
        hz440->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
        hz440->when(FL_WHEN_RELEASE);
        o->init("Pfixedfreq");
      } // Fl_Osc_Check* hz440
      { Fl_Osc_Dial* o = fixedfreqetdial = new Fl_Osc_Dial(610, 53, 15, 15, "Eq.T.");
        fixedfreqetdial->tooltip("How the frequency varies according to the keyboard (leftmost for fixed freque\
ncy)");
        fixedfreqetdial->box(FL_ROUND_UP_BOX);
        fixedfreqetdial->color(FL_BACKGROUND_COLOR);
        fixedfreqetdial->selection_color(FL_INACTIVE_COLOR);
        fixedfreqetdial->labeltype(FL_NORMAL_LABEL);
        fixedfreqetdial->labelfont(0);
        fixedfreqetdial->labelsize(10);
        fixedfreqetdial->labelcolor(FL_FOREGROUND_COLOR);
        fixedfreqetdial->maximum(127);
        fixedfreqetdial->step(1);
        fixedfreqetdial->align(Fl_Align(FL_ALIGN_RIGHT));
        fixedfreqetdial->when(FL_WHEN_CHANGED);
        o->init("PfixedfreqET");
      } // Fl_Osc_Dial* fixedfreqetdial
      { Fl_Osc_Choice* o = detunetype = new Fl_Osc_Choice(655, 94, 70, 15, "Detune Type");
        detunetype->box(FL_UP_BOX);
        detunetype->down_box(FL_BORDER_BOX);
        detunetype->color(FL_BACKGROUND_COLOR);
        detunetype->selection_color(FL_SELECTION_COLOR);
        detunetype->labeltype(FL_NORMAL_LABEL);
        detunetype->labelfont(0);
        detunetype->labelsize(10);
        detunetype->labelcolor(FL_FOREGROUND_COLOR);
        detunetype->textfont(1);
        detunetype->textsize(10);
        detunetype->callback((Fl_Callback*)cb_detunetype);
        detunetype->align(Fl_Align(FL_ALIGN_TOP_LEFT));
        detunetype->when(FL_WHEN_RELEASE);
        o->add("L35cents");o->add("L10cents");o->add("E100cents");o->add("E1200cents");
        o->init("PDetuneType",1);
      } // Fl_Osc_Choice* detunetype
      freqsettingsui->end();
    } // Fl_Group* freqsettingsui
    { Fl_Osc_Check* o = stereo = new Fl_Osc_Check(440, 406, 55, 35, "Stereo");
      stereo->box(FL_THIN_UP_BOX);
      stereo->down_box(FL_DOWN_BOX);
      stereo->color(FL_BACKGROUND_COLOR);
      stereo->selection_color(FL_FOREGROUND_COLOR);
      stereo->labeltype(FL_NORMAL_LABEL);
      stereo->labelfont(0);
      stereo->labelsize(10);
      stereo->labelcolor(FL_FOREGROUND_COLOR);
      stereo->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
      stereo->when(FL_WHEN_RELEASE);
      o->init("Pstereo");
    } // Fl_Osc_Check* stereo
    { Fl_Osc_Button* o = new Fl_Osc_Button(445, 446, 70, 25, "Clear");
      o->tooltip("Clear the harmonics");
      o->box(FL_THIN_UP_BOX);
      o->color(FL_BACKGROUND_COLOR);
      o->selection_color(FL_BACKGROUND_COLOR);
      o->labeltype(FL_NORMAL_LABEL);
      o->labelfont(0);
      o->labelsize(14);
      o->labelcolor(FL_FOREGROUND_COLOR);
      o->callback((Fl_Callback*)cb_Clear);
      o->align(Fl_Align(FL_ALIGN_CENTER));
      o->when(FL_WHEN_RELEASE);
    } // Fl_Osc_Button* o
    { bandwidthsettingsui = new Fl_Group(220, 5, 220, 135, "BANDWIDTH");
      bandwidthsettingsui->box(FL_UP_FRAME);
      bandwidthsettingsui->labeltype(FL_EMBOSSED_LABEL);
      bandwidthsettingsui->labelfont(1);
      bandwidthsettingsui->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
      { EnvelopeUI* o = bandwidthenvelopegroup = new EnvelopeUI(225, 65, 205, 70, "SUBsynth - BandWidth Envelope");
        bandwidthenvelopegroup->box(FL_FLAT_BOX);
        bandwidthenvelopegroup->color((Fl_Color)51);
        bandwidthenvelopegroup->selection_color(FL_BACKGROUND_COLOR);
        bandwidthenvelopegroup->labeltype(FL_NORMAL_LABEL);
        bandwidthenvelopegroup->labelfont(0);
        bandwidthenvelopegroup->labelsize(14);
        bandwidthenvelopegroup->labelcolor(FL_FOREGROUND_COLOR);
        bandwidthenvelopegroup->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
        bandwidthenvelopegroup->when(FL_WHEN_RELEASE);
        o->init(ENV_ADSR_BW, osc, loc, "BandWidthEnvelope/");
        bandwidthenvelopegroup->end();
      } // EnvelopeUI* bandwidthenvelopegroup
      { Fl_Osc_Check* o = bwee = new Fl_Osc_Check(225, 67, 55, 15, "Enabled");
        bwee->box(FL_NO_BOX);
        bwee->down_box(FL_DOWN_BOX);
        bwee->color(FL_BACKGROUND_COLOR);
        bwee->selection_color(FL_FOREGROUND_COLOR);
        bwee->labeltype(FL_NORMAL_LABEL);
        bwee->labelfont(1);
        bwee->labelsize(10);
        bwee->labelcolor(FL_FOREGROUND_COLOR);
        bwee->callback((Fl_Callback*)cb_bwee);
        bwee->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
        bwee->when(FL_WHEN_RELEASE);
        o->init("PBandWidthEnvelopeEnabled");
      } // Fl_Osc_Check* bwee
      { Fl_Osc_VSlider* o = bandwidth = new Fl_Osc_VSlider(225, 40, 115, 15, "Band Width");
        bandwidth->type(5);
        bandwidth->box(FL_NO_BOX);
        bandwidth->color(FL_BACKGROUND_COLOR);
        bandwidth->selection_color(FL_BACKGROUND_COLOR);
        bandwidth->labeltype(FL_NORMAL_LABEL);
        bandwidth->labelfont(0);
        bandwidth->labelsize(10);
        bandwidth->labelcolor(FL_FOREGROUND_COLOR);
        bandwidth->maximum(127);
        bandwidth->step(1);
        bandwidth->align(Fl_Align(FL_ALIGN_TOP));
        bandwidth->when(FL_WHEN_CHANGED);
        o->init("Pbandwidth");o->reset_value=40;
      } // Fl_Osc_VSlider* bandwidth
      { Fl_Osc_TSlider* o = bwidthscale = new Fl_Osc_TSlider(345, 40, 90, 15, "B.Width Scale");
        bwidthscale->tooltip("How much I increase the BandWidth according to lower/higher harmonics");
        bwidthscale->type(5);
        bwidthscale->box(FL_NO_BOX);
        bwidthscale->color(FL_BACKGROUND_COLOR);
        bwidthscale->selection_color(FL_BACKGROUND_COLOR);
        bwidthscale->labeltype(FL_NORMAL_LABEL);
        bwidthscale->labelfont(0);
        bwidthscale->labelsize(10);
        bwidthscale->labelcolor(FL_FOREGROUND_COLOR);
        bwidthscale->minimum(-64);
        bwidthscale->maximum(63);
        bwidthscale->step(1);
        bwidthscale->align(Fl_Align(FL_ALIGN_TOP));
        bwidthscale->when(FL_WHEN_CHANGED);
        o->init("Pbwscale",'i');
      } // Fl_Osc_TSlider* bwidthscale
      bandwidthsettingsui->end();
    } // Fl_Group* bandwidthsettingsui
    { globalfiltergroup = new Fl_Group(440, 221, 290, 185, "FILTER");
      globalfiltergroup->box(FL_UP_FRAME);
      globalfiltergroup->labeltype(FL_EMBOSSED_LABEL);
      globalfiltergroup->labelfont(1);
      globalfiltergroup->labelsize(13);
      globalfiltergroup->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
      { EnvelopeUI* o = filterenv = new EnvelopeUI(445, 331, 275, 70, "SUBsynth - Filter Envelope");
        filterenv->box(FL_FLAT_BOX);
        filterenv->color((Fl_Color)51);
        filterenv->selection_color(FL_BACKGROUND_COLOR);
        filterenv->labeltype(FL_NORMAL_LABEL);
        filterenv->labelfont(0);
        filterenv->labelsize(14);
        filterenv->labelcolor(FL_FOREGROUND_COLOR);
        filterenv->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
        filterenv->when(FL_WHEN_RELEASE);
        o->init(ENV_ADSR_FILTER, osc, loc, "GlobalFilterEnvelope/");
        filterenv->end();
      } // EnvelopeUI* filterenv
      { FilterUI* o = filterui = new FilterUI(445, 246, 275, 75, "SUBsynthl - Filter");
        filterui->box(FL_FLAT_BOX);
        filterui->color(FL_LIGHT1);
        filterui->selection_color(FL_BACKGROUND_COLOR);
        filterui->labeltype(FL_NORMAL_LABEL);
        filterui->labelfont(0);
        filterui->labelsize(14);
        filterui->labelcolor(FL_FOREGROUND_COLOR);
        filterui->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
        filterui->when(FL_WHEN_RELEASE);
        o->init(loc + "PGlobalFilter" , osc, loc, "GlobalFilter/");
        filterui->end();
      } // FilterUI* filterui
      globalfiltergroup->end();
    } // Fl_Group* globalfiltergroup
    { Fl_Osc_Check* o = filtere = new Fl_Osc_Check(445, 226, 85, 20, "Enabled");
      filtere->box(FL_NO_BOX);
      filtere->down_box(FL_DOWN_BOX);
      filtere->color(FL_BACKGROUND_COLOR);
      filtere->selection_color(FL_FOREGROUND_COLOR);
      filtere->labeltype(FL_NORMAL_LABEL);
      filtere->labelfont(1);
      filtere->labelsize(11);
      filtere->labelcolor(FL_FOREGROUND_COLOR);
      filtere->callback((Fl_Callback*)cb_filtere);
      filtere->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
      filtere->when(FL_WHEN_RELEASE);
      o->init("PGlobalFilterEnabled");
    } // Fl_Osc_Check* filtere
    { Fl_Button* o = new Fl_Button(600, 451, 25, 15, "C");
      o->box(FL_THIN_UP_BOX);
      o->color((Fl_Color)179);
      o->labelfont(1);
      o->labelsize(11);
      o->labelcolor((Fl_Color)55);
      o->callback((Fl_Callback*)cb_C);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(630, 451, 25, 15, "P");
      o->box(FL_THIN_UP_BOX);
      o->color((Fl_Color)179);
      o->labelfont(1);
      o->labelsize(11);
      o->labelcolor((Fl_Color)55);
      o->callback((Fl_Callback*)cb_P);
    } // Fl_Button* o
    { Fl_Group* o = new Fl_Group(440, 151, 220, 70, "OVERTONES");
      o->box(FL_UP_FRAME);
      o->labeltype(FL_EMBOSSED_LABEL);
      o->labelfont(1);
      o->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
      { Fl_Osc_Choice* o = spreadtype = new Fl_Osc_Choice(450, 190, 80, 20, "OvertonesPosition");
        spreadtype->box(FL_UP_BOX);
        spreadtype->down_box(FL_BORDER_BOX);
        spreadtype->color(FL_BACKGROUND_COLOR);
        spreadtype->selection_color(FL_SELECTION_COLOR);
        spreadtype->labeltype(FL_NORMAL_LABEL);
        spreadtype->labelfont(0);
        spreadtype->labelsize(10);
        spreadtype->labelcolor(FL_FOREGROUND_COLOR);
        spreadtype->textsize(10);
        spreadtype->align(Fl_Align(FL_ALIGN_TOP_LEFT));
        spreadtype->when(FL_WHEN_RELEASE);
        spreadtype->menu(menu_spreadtype);
        o->init("POvertoneSpread.type");
      } // Fl_Osc_Choice* spreadtype
      { Fl_Osc_Dial* o = spreadpar1 = new Fl_Osc_Dial(548, 173, 30, 30, "Par1");
        spreadpar1->box(FL_ROUND_UP_BOX);
        spreadpar1->color(FL_BACKGROUND_COLOR);
        spreadpar1->selection_color(FL_INACTIVE_COLOR);
        spreadpar1->labeltype(FL_NORMAL_LABEL);
        spreadpar1->labelfont(0);
        spreadpar1->labelsize(10);
        spreadpar1->labelcolor(FL_FOREGROUND_COLOR);
        spreadpar1->maximum(255);
        spreadpar1->step(1);
        spreadpar1->align(Fl_Align(FL_ALIGN_BOTTOM));
        spreadpar1->when(FL_WHEN_CHANGED);
        o->init("POvertoneSpread.par1");
      } // Fl_Osc_Dial* spreadpar1
      { Fl_Osc_Dial* o = spreadpar2 = new Fl_Osc_Dial(583, 173, 30, 30, "Par2");
        spreadpar2->box(FL_ROUND_UP_BOX);
        spreadpar2->color(FL_BACKGROUND_COLOR);
        spreadpar2->selection_color(FL_INACTIVE_COLOR);
        spreadpar2->labeltype(FL_NORMAL_LABEL);
        spreadpar2->labelfont(0);
        spreadpar2->labelsize(10);
        spreadpar2->labelcolor(FL_FOREGROUND_COLOR);
        spreadpar2->maximum(255);
        spreadpar2->step(1);
        spreadpar2->align(Fl_Align(FL_ALIGN_BOTTOM));
        spreadpar2->when(FL_WHEN_CHANGED);
        o->init("POvertoneSpread.par2");
      } // Fl_Osc_Dial* spreadpar2
      { Fl_Osc_Dial* o = spreadpar3 = new Fl_Osc_Dial(618, 173, 30, 30, "ForceH");
        spreadpar3->box(FL_ROUND_UP_BOX);
        spreadpar3->color(FL_BACKGROUND_COLOR);
        spreadpar3->selection_color(FL_INACTIVE_COLOR);
        spreadpar3->labeltype(FL_NORMAL_LABEL);
        spreadpar3->labelfont(0);
        spreadpar3->labelsize(10);
        spreadpar3->labelcolor(FL_FOREGROUND_COLOR);
        spreadpar3->maximum(255);
        spreadpar3->step(1);
        spreadpar3->align(Fl_Align(FL_ALIGN_BOTTOM));
        spreadpar3->when(FL_WHEN_CHANGED);
        o->init("POvertoneSpread.par3");
      } // Fl_Osc_Dial* spreadpar3
      o->end();
    } // Fl_Group* o
    SUBparameters->end();
  } // Fl_Osc_Window* SUBparameters
  return SUBparameters;
}

void SUBnoteUI::refresh() {
  SUBparameters->update();
  for (int i=0;i<MAX_SUB_HARMONICS;i++) h[i]->refresh();
  //globalfiltergroup->redraw();
  //ampenv->refresh();
  //bandwidthenvelopegroup->refresh();
  //freqenvelopegroup->refresh();
  //filterui->refresh();
  //filterenv->refresh();
}

SUBnoteUI::SUBnoteUI(Fl_Osc_Interface *osc_, std::string loc_) {
  osc = osc_;
      loc = loc_;
  make_window();
}

SUBnoteUI::~SUBnoteUI() {
  //for (int i=0;i<MAX_SUB_HARMONICS;i++) delete (h[i]);
  SUBparameters->hide();
  delete(SUBparameters);
}