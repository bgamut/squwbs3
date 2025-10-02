/*
  ==============================================================================

    basic_functions.h
    Created: 2 Mar 2018 8:13:11am
    Author:  Bernard Ahn

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class basic_functions    : public Component
{
public:
    basic_functions()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

    }

    ~basic_functions()
    {
    }


    float LinearToDB(float linear)
    {
        float db;
    
        if (linear != 0.0f)
            db = 20.0f * log10(linear);
        else
            db = -144.0f;  // effectively minus infinity
    
        return db;
    }
    
    float DBToLinear(float decibel)
    {
        return pow((decibel/20),10);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (basic_functions)
};
