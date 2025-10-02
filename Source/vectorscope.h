/*
  ==============================================================================

    vectorscope.h
    Created: 28 Feb 2018 7:47:44pm
    Author:  Bernard Ahn

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
//==============================================================================
/*
*/
class vectorscope    : public Component
{
public:
    vectorscope()
    {
        SampleSlots=8;
        //float* x= new float[SampleSlots];
        //float* y= new float[SampleSlots];
        dropShadow.colour=Colour((uint8)256,(uint8)256,(uint8)256,(uint8)256);
        dropShadow.radius=0.5;
        dropShadow.offset=Point <int> (0.0,0.0);
        for (int i=0; i<SampleSlots; i++){
            x[i]=0.0;
            y[i]=0.0;
        }
    }

    ~vectorscope()
    {   
        //delete x;
        //delete y;
    }

    void paint (Graphics& g) override
    {
        originX=getWidth()/2;
        originY=getHeight()/2;

        //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

        //g.setColour (Colours::grey);
        //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

        //g.setColour (Colours::white);
        //g.setFont (14.0f);
        //g.drawText ("vectorscope", getLocalBounds(),Justification::centred, true);   // draw some placeholder text
        amplitude = fmin(getWidth(),getHeight());
        gate=false;
        //line.startNewSubPath(originX+x[0],originY+y[0]);
        line.startNewSubPath(originX,originY);
        //line.lineTo(originX+x[1],originY+y[1]);
        for(int i = 0; i<SampleSlots; i++){
            line.cubicTo(originX+x[i-2],originY+y[i-2],originX+x[i-1],originY+y[i-1],originX+x[i],originY+y[i]);
        }
        g.setColour(Colour((int)color,(int)color,(int)color));
        g.strokePath(line,PathStrokeType(6.0f));
        g.setColour(Colours::white);
        g.strokePath(line,PathStrokeType(2.0f));
        //dropShadow.drawForPath(g,line);
        
        gate=true;
        line.clear();
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }
    void load(float left, float right)
    {
        float range = fmin(getLocalBounds().getWidth()/2.0,getLocalBounds().getHeight()/2.0);
        for(int i = SampleSlots-2; 0<i; i--){
            
            //x[i+1]= x[i]*(i/(i+1.0));
            //y[i+1]= y[i]*(i/(i+1.0));
            
            x[i+1]= x[i];
            y[i+1]= y[i];
        }
        x[1]=x[0]*range;
        y[1]=y[0]*range;
        
        if(fabs(left)==fabs(right)){
            x[0]=0.0;
        }
        else if(fabs(left)>fabs(right)){
            x[0]=sin((float_Pi/2.0)*(-1.0)*fabs(left));
            //x[0]=(-1.0)*fabs(left);
        }
        else{
            x[0]=sin((float_Pi/2.0)*fabs(right));
            //x[0]=fabs(right);
        }
        y[0]=sin((float_Pi/2.0)*(left+right)/2.0);
        color=256-fmax(fabs(left),fabs(right))*128;
        /*
        int range = 12;
        uint8 number = (uint8)(256.0-range+abs(sin((float_Pi/2.0)*((left)+(right))/2.0))*range);
        dropShadow.colour=Colour(number,number,number);
         */
    }
         

private:
    float SampleSlots;
    //float* x;
    //float* y;
    float x[8];
    float y[8];
    Path line;
    bool gate;
    float amplitude;
    float color;
    int originX;
    int originY;
    DropShadow dropShadow;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (vectorscope)
};
