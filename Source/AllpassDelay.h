/*
  ==============================================================================

    AllpassDelay.h
    Created: 4 Feb 2018 4:11:32pm
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AllpassDelay.h"
#include "Clipper.h"
#include "Gate.h"
#include "HP12.h"
#include "HP24.h"
#include "HP36.h"
#include "LP12.h"
#include "LP24.h"
#include "LP36.h"
#include "Notch12.h"
#include "Phaser.h"
#include "ForwardFFT.h"
#include "ThreeBandEQ.h"
#include "math.h"
#include "FourBandEQ.h"

//==============================================================================
/*
*/
class AllpassDelay    : public Component
{
public:
    AllpassDelay():
    a1(0.0),
    zm1(0.0)
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

    }

    ~AllpassDelay()
    {
    }

    void Delay( float delay ){
        a1 = (1.0 - delay) / (1.0 + delay);
    }
    float process(float inputValue){
        output = inputValue * (-1.0)*a1 + zm1;
        zm1 = output * a1 + inputValue;
        return output;
    }
	float output;
private:
	float a1, zm1;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AllpassDelay)
};
