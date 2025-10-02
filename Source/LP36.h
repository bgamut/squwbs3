/*
  ==============================================================================

    LP36.h
    Created: 4 Feb 2018 3:36:39pm
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
#define PI 3.14159265
//==============================================================================
/*
*/
class LP36    : public Component
{
public:
    LP36():
    cutoff(750.0),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0),
    buf2(0.0),
    buf3(0.0),
    buf4(0.0),
    buf5(0.0),
    sampleRate(44100.0)
    {
       calculateFeedbackAmount();
    }

    ~LP36()
    {
    }


    float process(float inputValue) {
        buf0 += cutoff * (inputValue - buf0);
        buf1 += cutoff * (buf0 - buf1);
        buf2 += cutoff * (buf1 - buf2);
        buf3 += cutoff * (buf2 - buf3);
        buf4 += cutoff * (buf3 - buf4);
        buf5 += cutoff * (buf4 - buf5);
        return buf5;
    };
    void set(float newCutoff) {
        
        cutoff = 2*sin((PI)*newCutoff/sampleRate);
        calculateFeedbackAmount();
    };
    void setResonance(float newResonance){
        resonance = newResonance;
        calculateFeedbackAmount();
    };
    void setSampleRate(float sr){
        sampleRate=sr;
    };

private:
	float buf0;
	float buf1;
	float buf2;
	float buf3;
	float buf4;
	float buf5;
	float cutoff;
	float resonance;
	float feedbackAmount;
	float sampleRate;
	void calculateFeedbackAmount() {
		feedbackAmount = resonance + resonance / (1.0 - cutoff);
	};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LP36)
};
