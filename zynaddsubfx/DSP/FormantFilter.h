/*
  ZynAddSubFX - a software synthesizer

  FormantFilter.h - formant filter
  Copyright (C) 2002-2005 Nasca Octavian Paul
  Author: Nasca Octavian Paul

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
*/

#ifndef FORMANT_FILTER_H
#define FORMANT_FILTER_H

#include "../globals.h"
#include "Filter.h"

namespace zyncarla {

class FormantFilter:public Filter
{
    public:
        FormantFilter(const FilterParams *pars, Allocator *alloc, unsigned int srate, int bufsize);
        ~FormantFilter();
        void filterout(float *smp);
        void setfreq(float frequency);
        void setfreq_and_q(float frequency, float q_);
        void setq(float q_);
        void setgain(float dBgain);

        void cleanup(void);

    private:
        void setpos(float input);


        class AnalogFilter * formant[FF_MAX_FORMANTS];

        struct {
            float freq, amp, q; //frequency,amplitude,Q
        } formantpar[FF_MAX_VOWELS][FF_MAX_FORMANTS],
          currentformants[FF_MAX_FORMANTS];

        struct {
            unsigned char nvowel;
        } sequence [FF_MAX_SEQUENCE];

        float oldformantamp[FF_MAX_FORMANTS];

        int   sequencesize, numformants, firsttime;
        float oldinput, slowinput;
        float Qfactor, formantslowness, oldQfactor;
        float vowelclearness, sequencestretch;
        Allocator &memory;
};

}

#endif
