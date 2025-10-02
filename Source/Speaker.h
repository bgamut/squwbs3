/*
 ==============================================================================
 
 This is an automatically generated GUI class created by the Projucer!
 
 Be careful when adding custom code to these files, as only the code within
 the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
 and re-saved.
 
 Created with Projucer version: 5.2.1
 
 ------------------------------------------------------------------------------
 
 The Projucer is part of the JUCE library.
 Copyright (c) 2017 - ROLI Ltd.
 
 ==============================================================================
 */

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
 //[Comments]
 An auto-generated component, created by the Projucer.
 
 Describe your class and how it works here!
 //[/Comments]
 */
class Speaker  : public Component,
private Timer
{
public:
    //==============================================================================
    Speaker ();
    ~Speaker();
    
    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]
    
    
    void timerCallback() override;
    void setColour(Graphics& g, uint8* colour);
    void setColour(Graphics& g, uint8 red, uint8 blue, uint8 green);
    void setColour(Graphics& g, String colour);
    void setThickness(float thickness);
    void load(float input);
    float sample;
    int originX;
    int height;
    int originY;
    int width;
    int min;
    int amplitude1;
    int amplitude2;
    float lineThickness;
    int range;
    void setArea(double x, double y, double w, double h);
    void setArea(Rectangle<int> i);
    void setArea(Rectangle<float> i);
    Rectangle <int> getArea();
    Rectangle <int> area;
    void setCircle1(int x, int y, int w, int h);
    int circle1X;
    int circle1Y;
    int circle1MinRadius;
    int circle1Radius;
    Rectangle <float> getCircle1();
    Rectangle <float> circle1;
    void setCircle2(int x, int y, int w, int h);
    int circle2X;
    int circle2Y;
    int circle2MinRadius;
    int circle2Radius;
    Rectangle <float> getCircle2();
    Rectangle <float> circle2;
    void setBounds(Rectangle <int> x);
    
    
private:
    
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]
    
    //==============================================================================
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Speaker)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

