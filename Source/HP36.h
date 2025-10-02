/*
  ==============================================================================

    HP36.h
    Created: 4 Feb 2018 4:00:40pm
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
//==============================================================================
/*
*/
class HP36    : public Component
{
public:
    HP36():
    cutoff(750.0),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0),
    buf2(0.0),
    buf3(0.0),
    buf4(0.0),
    buf5(0.0),
    sampleRate(44100)
    {

    }

    ~HP36()
    {
    }


    float process(float inputValue) {
        buf0 += cutoff * (inputValue - buf0 + feedbackAmount * (buf0 - buf1));
        //buf0 += cutoff * (inputValue - buf0);
        buf1 += cutoff * (buf0 - buf1);
        buf2 += cutoff * (buf1 - buf2);
        buf3 += cutoff * (buf2 - buf3);
        buf4 += cutoff * (buf3 - buf4);
        buf5 += cutoff * (buf4 - buf5);
        return inputValue - buf5;
    }
    void set(float newCutoff) { 
        cutoff = 2*sin((float_Pi)*newCutoff/sampleRate);
        calculateFeedbackAmount(); 
    }
    void setResonance(float newResonance) { 
        resonance = newResonance; calculateFeedbackAmount(); 
    }
    void setSampleRate(float sr){
        sampleRate=sr;
    }
private:
	float cutoff;
	float buf0;
	float buf1;
	float buf2;
	float buf3;
	float buf4;
	float buf5;
	float resonance;
	float sampleRate;
	float feedbackAmount;
	void calculateFeedbackAmount() {
		feedbackAmount = resonance + resonance / (1.0 - cutoff);
	};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HP36)
};
