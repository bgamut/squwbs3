/*
  ==============================================================================

    Notch12.h
    Created: 4 Feb 2018 4:06:51pm
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
//==============================================================================
/*
*/
class Notch12    : public Component
{
public:
    Notch12():
    cutoff(750.0),
    resonance(1.0),
    buf0(0.0),
    buf1(0.0),
    sampleRate(44100)
    {
        calculateFeedbackAmount();
    }

    ~Notch12()
    {
    }
    float process(float inputValue){
        buf0 += cutoff * (inputValue - buf0);
        buf1 += cutoff * (buf0 - buf1);
        return inputValue - (buf0 - buf1);
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
	float resonance;
	float buf0;
	float buf1;
	float sampleRate;
	float feedbackAmount;
	void calculateFeedbackAmount() {
		feedbackAmount = resonance + resonance / (1.0 - cutoff);
	};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Notch12)
};
