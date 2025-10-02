/*
  ==============================================================================

    cone.h
    Created: 22 Feb 2018 9:45:30am
    Author:  Bernard Ahn

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class cone    : public Component,
                private Timer
{
public:
    cone()
    {
        startTimerHz(60);
        for (int i = 0; i<8; i++){
            sample[i]=0.0;
        }
    }

    ~cone()
    {
    }
    void timerCallback() override{
        repaint();
    }
    void paint (Graphics& g) override
    {
        local=getLocalBounds();
        width=local.getWidth();
        height=local.getHeight();
        min=fmin(width,height);
        range1=min*125/4096*rms;
        range2=min*125/4096*peak;
        radius1=min/2;
        radius2=min*11/32;
        
        if(width>height){
            local.removeFromLeft((width-min)/2);
            local.removeFromRight((width-min)/2);
        }
        else{
            local.removeFromTop((height-min)/2);
            local.removeFromBottom((height-min)/2);
        }
   
        circle1.setBounds(local.getX()+min*25/512-range1,local.getY()+min*25/512-range1,local.getWidth()-min*25/256+range1*2,local.getHeight()-min*25/256+range1*2);
        circle2.setBounds(local.getX()+radius2-range2,local.getY()+radius2-range2,local.getWidth()-radius2*2+range2*2,local.getHeight()-radius2*2+range2*2);
        

        //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   
        g.setColour (Colour(255,255,255));
        //g.drawRect (local, 1);
        //g.drawRect(area,1);
        //g.setColour (Colour(135,135,135));
        g.fillEllipse(circle1);
        //g.setColour (Colour(255,255,255));
        g.setColour (Colour(135,135,135));
        g.drawEllipse(circle1,2.0);
        g.drawEllipse(circle2,2.0);
        g.setFont (14.0f);
        //g.drawText (String(sample), getLocalBounds(),Justification::centred, true);   // draw some placeholder text
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }
    void load(float input)
    {
        for (int i=7; i>0; i--){
            rmstemp+=sample[i]/8.0;
            sample[i]=sample[i-1];
        }
        if(input){
            sample[0]=fabs(sin((float_Pi/2.0)*(float)input));
            rmstemp+=(float)(sample[0])/8.0;
        }
        rms=rmstemp;
        rmstemp=0.0;
        peak=input/2.0;
    }
    int min;
private:
    Rectangle <int> area;
    Rectangle <float> circle1;
    Rectangle <float> circle2;
    Rectangle <int> local;
    int height;
    int width;
    int x1;
    int x2;
    int y1;
    int y2;
    int radius1;
    int radius2;
    float range1;
    float range2;
    float sample[8];
    float rmstemp=0.0;
    float rms = 0.0;
    float peak;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (cone)
};
