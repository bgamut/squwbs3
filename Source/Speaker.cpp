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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Speaker.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Speaker::Speaker() :
circle1MinRadius(0),
circle2MinRadius(0),
circle1Radius(0),
circle2Radius(0),
circle1X(0),
circle1Y(0),
circle2X(0),
circle2Y(0)
{
    
    load(sample);
    setThickness(1.0);
    
}

Speaker::~Speaker()
{
    
}
void Speaker::timerCallback()  {
    
}




void Speaker::setArea(Rectangle<int> i){
    area.setBounds(i.getX(),i.getY(),i.getX()+i.getWidth(),i.getY()+i.getHeight());
}
void Speaker::setArea(Rectangle<float> i){
    area.setBounds(i.getX(),i.getY(),i.getX()+i.getWidth(),i.getY()+i.getHeight());
}
void Speaker::setCircle1(int x, int y, int w, int h) {
    
    circle1.setBounds((float) x, (float) y, (float) w, (float) h);
}
void Speaker::setCircle2(int x, int y, int w, int h) {
    circle2.setBounds((float)x, (float)y, (float)w, (float)h);
}
Rectangle<int> Speaker::getArea() {
    return area;
}
Rectangle<float> Speaker::getCircle1() {
    return circle1;
}
Rectangle<float> Speaker::getCircle2() {
    return circle2;
}


void Speaker::setColour(Graphics& g, uint8* colour) {
    g.setColour(Colour(colour[0], colour[1], colour[2]));
    
}
void Speaker::setColour(Graphics& g, uint8 red, uint8 blue, uint8 green) {
    g.setColour(Colour(red, blue, green));
    
}
void Speaker::setColour(Graphics& g, String color) {
    g.setColour(Colours::white);
    
}

void Speaker::setThickness(float thickness) {
    lineThickness = thickness;
}
void Speaker::setBounds(Rectangle <int> bounds) {
    width = (int)bounds.getWidth();
    height = (int)bounds.getHeight();
    if (width <= height) {
        min = width * 231 / 256;
    }
    else {
        min = height * 231 / 256;
    }
    range = min * 25/256;
    //inner x and y
    originX = bounds.getCentreX() - min / 2.0;
    originY = bounds.getCentreY() - min / 2.0;
    setArea(originX, originY, min, min);
    circle1MinRadius = min-range;
    circle2MinRadius = circle1Radius * 11/32;
}
void Speaker::load(float input)
{
    
    sample = sin(2.0*input/(MathConstants< float >::pi))/2.0;
    
   
    amplitude2 = (int)(sample * (float)range);
    amplitude1 = (amplitude2 * 11 / 16);
    
    circle1X = area.getCentreX() - (circle1MinRadius / 2) - (amplitude1 / 2);
    circle1Y = area.getCentreY() - (circle1MinRadius / 2) - (amplitude1 / 2);
    circle1Radius = circle1MinRadius + amplitude1;
    
    setCircle1(circle1X, circle1Y, circle1Radius, circle1Radius);
    
    circle2X = area.getCentreX() - (circle2MinRadius / 2) - (amplitude2 / 2);
    circle2Y = area.getCentreY() - (circle2MinRadius / 2) - (amplitude2 / 2);
    circle2Radius = circle2MinRadius + amplitude2;
    
    setCircle2(circle2X, circle2Y, circle2Radius, circle2Radius);
    
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --
 
 This is where the Projucer stores the metadata that describe this GUI layout, so
 make changes in here at your peril!
 
 BEGIN_JUCER_METADATA
 
 <JUCER_COMPONENT documentType="Component" className="Speaker" componentName=""
 parentClasses="public Component" constructorParams="" variableInitialisers=""
 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
 fixedSize="0" initialWidth="600" initialHeight="400">
 <BACKGROUND backgroundColour="ff323e44"/>
 </JUCER_COMPONENT>
 
 END_JUCER_METADATA
 */
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

