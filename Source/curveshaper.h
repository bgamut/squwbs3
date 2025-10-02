/*
  ==============================================================================

    curveshaper.h
    Created: 11 Jan 2019 11:12:32am
    Author:  Bernard Ahn

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
//==============================================================================
/*
*/
class curveshaper    : public Component
{
public:
    curveshaper():
    coefficient(1.0)
    {
        calculateFeedbackAmount();
    }

    ~curveshaper()
    {
    }

    float process(float inputValue){
        if(coefficient == 1.0){
            return inputValue
        }
        else{
            if(inputValue>0){
                return ((pow(coeff,inputValue)-1))/(coeff-1)
            }
            else(){
                return(-1.0*(pow(coeff,fabf(inputValue))-1))/(coeff-1)
            }
        }
    }
    void setCoefficient(float newCoefficient) {
        
        coefficient = fabsf(newCoefficient)
        
    }

private:
    float coefficient;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HP12)
};