/*
  ==============================================================================

    Linkwitz-Riley.h
    Created: 4 Feb 2018 3:40:50pm
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
#include "iostream"
#include "stdio.h"
#include "assert.h"
#define PI 3.14159265
//==============================================================================
/*
*/
class L_Riley_LP    : public Component
{

public:
    L_Riley_LP():
    fc(750.0),
    sampleRate(44100.0)
    {
        wc=2*PI*fc;
        wc2=wc*wc;
        wc3=wc2*wc;
        wc4=wc2*wc2;
        k=wc/tan(PI*fc/sampleRate);
        k2=k*k;
        k3=k2*k;
        k4=k2*k2;
        sqrt2=sqrt(2);
        sq_tmp1=sqrt2*wc3*k;
        sq_tmp2=sqrt2*wc*k3;
        a_tmp=4*wc2*k2+2*sq_tmp1+k4+2*sq_tmp2+wc4;
        b1=(4*(wc4+sq_tmp1-k4-sq_tmp2))/a_tmp;
        b2=(6*wc4-8*wc2*k2+6*k4)/a_tmp;
        b3=(4*(wc4-sq_tmp1+sq_tmp2-k4))/a_tmp;
        b4=(k4-2*sq_tmp1+wc4-2*sq_tmp2+4*wc2*k2)/a_tmp;
    }
    void setSampleRate(float sr){
        sampleRate=sr;
    }
    float process(float inputValue){
        a0=wc4/a_tmp;
        a1=4*wc4/a_tmp;
        a2=6*wc4/a_tmp;
        a3=a1;
        a4=a0;
        tempx=inputValue;
        tempy=a0*tempx+a1*xm1+a2*xm2+a3*xm3+a4*xm4-b1*ym1-b2*ym2-b3*ym3-b4*ym4;
        xm4=xm3;
        xm3=xm2;
        xm2=xm1;
        xm1=tempx;
        ym4=ym3;
        ym3=ym2;
        ym2=ym1;
        ym1=tempy;

        return tempy;
    };

    void set(float newCutoff){
        fc = newCutoff;
    };
private:
    float sampleRate;
    float fc = 0.0f;
    float sqrt2;
    float wc = 0.0f, wc2 = 0.0f, wc3 = 0.0f, wc4 = 0.0f;
    float k = 0.0f, k2 = 0.0f, k3 = 0.0f, k4 = 0.0f;
    float sq_tmp1 = 0.0f, sq_tmp2 = 0.0f;
    float a_tmp = 0.0f;
    float a0 = 0.0f, a1 = 0.0f, a2 = 0.0f, a3 = 0.0f, a4 = 0.0f;
    float b1 = 0.0f, b2 = 0.0f, b3 = 0.0f, b4 = 0.0f;
    float tempx = 0.0f;
    float tempy = 0.0f;
    float xm1 = 0.0f;
    float xm2 = 0.0f;
    float xm3 = 0.0f;
    float xm4 = 0.0f;
    float ym1 = 0.0f, ym2 = 0.0f, ym3 = 0.0f, ym4 = 0.0f;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (L_Riley_LP)
};
class L_Riley_HP    : public Component
{

public:
    L_Riley_HP():
    fc(750.0),
    sampleRate(44100.0)
    {
        wc=2*PI*fc;
        wc2=wc*wc;
        wc3=wc2*wc;
        wc4=wc2*wc2;
        k=wc/tan(PI*fc/sampleRate);
        k2=k*k;
        k3=k2*k;
        k4=k2*k2;
        sqrt2=sqrt(2);
        sq_tmp1=sqrt2*wc3*k;
        sq_tmp2=sqrt2*wc*k3;
        a_tmp=4*wc2*k2+2*sq_tmp1+k4+2*sq_tmp2+wc4;
        b1=(4*(wc4+sq_tmp1-k4-sq_tmp2))/a_tmp;
        b2=(6*wc4-8*wc2*k2+6*k4)/a_tmp;
        b3=(4*(wc4-sq_tmp1+sq_tmp2-k4))/a_tmp;
        b4=(k4-2*sq_tmp1+wc4-2*sq_tmp2+4*wc2*k2)/a_tmp;
    }
    void setSampleRate(float sr){
        sampleRate=sr;
    }

    float process(float inputValue){
        a0=k4/a_tmp;
        a1=-4*k4/a_tmp;
        a2=6*k4/a_tmp;
        a3=a1;
        a4=a0;
        tempx=inputValue;

        tempy=a0*tempx+a1*xm1+a2*xm2+a3*xm3+a4*xm4-b1*ym1-b2*ym2-b3*ym3-b4*ym4;
        xm4=xm3;
        xm3=xm2;
        xm2=xm1;
        xm1=tempx;
        ym4=ym3;
        ym3=ym2;
        ym2=ym1;
        ym1=tempy;

        return tempy;
    }
    void set(float newCutoff){
        fc = newCutoff;
    };
private:
    float sampleRate;
    float fc = 0.0f;
    float sqrt2;
    float wc = 0.0f, wc2 = 0.0f, wc3 = 0.0f, wc4 = 0.0f;
    float k = 0.0f, k2 = 0.0f, k3 = 0.0f, k4 = 0.0f;
    float sq_tmp1 = 0.0f, sq_tmp2 = 0.0f;
    float a_tmp = 0.0f;
    float a0 = 0.0f, a1 = 0.0f, a2 = 0.0f, a3 = 0.0f, a4 = 0.0f;
    float b1 = 0.0f, b2 = 0.0f, b3 = 0.0f, b4 = 0.0f;
    float tempx = 0.0f;
    float tempy = 0.0f;
    float xm1 = 0.0f;
    float xm2 = 0.0f;
    float xm3 = 0.0f;
    float xm4 = 0.0f;
    float ym1 = 0.0f, ym2 = 0.0f, ym3 = 0.0f, ym4 = 0.0f;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (L_Riley_HP)
};
