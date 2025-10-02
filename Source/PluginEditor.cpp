/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
struct scientificNumberType
{
    explicit scientificNumberType(T number, int decimalPlaces) : number(number), decimalPlaces(decimalPlaces) {}
    
    T number;
    int decimalPlaces;
};

template<typename T>
scientificNumberType<T> scientificNumber(T t, int decimalPlaces)
{
    return scientificNumberType<T>(t, decimalPlaces);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const scientificNumberType<T>& n)
{
    double numberDouble = n.number;
    
    int eToThe = 0;
    for(; numberDouble > 9; ++eToThe)
    {
        numberDouble /= 10;
    }
    
    // memorize old state
    std::ios oldState(nullptr);
    oldState.copyfmt(os);
    
    os << std::fixed << std::setprecision(n.decimalPlaces) << numberDouble << "e" << eToThe;
    
    // restore state
    os.copyfmt(oldState);
    
    return os;
}
//==============================================================================
SquwbsAudioProcessorEditor::SquwbsAudioProcessorEditor (SquwbsAudioProcessor& owner)
    : AudioProcessorEditor (&owner),audioProcessor(owner)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    mixSlider.setColour(Slider::thumbColourId, juce::Colours::transparentBlack);
    //otherLookAndFeel.setColour(Slider::thumbColourId, juce::Colour(248,248,248));
        //otherLookAndFeel.setColour(Slider::backgroundColourId, Colour(135, 135, 135));
    mixSlider.setColour(Slider::backgroundColourId, Colour(135,135,135));
    //otherLookAndFeel.setColour(Slider::trackColourId, Colour(248, 248, 248));
    mixSlider.setColour(Slider::trackColourId, Colour(135,135,135));
    mixSlider.setColour(Slider::rotarySliderFillColourId, Colour(75,75,75));
    mixSlider.setColour(Slider::rotarySliderOutlineColourId, Colour(186,186,186));
    mixSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    mixSlider.setRange(0.0,100.0,0.1);
    mixSlider.setTextBoxStyle(juce::Slider::NoTextBox,false,0,0);
    mixSlider.setValue(100.0);
    addAndMakeVisible(mixSlider);
    setResizeLimits(100, 100, 3840, 2240);
    setResizable(true,true);
    //speaker.setColour(Colour(135,135,135));
    addChildComponent(testLabel1);
    addChildComponent(speaker);
    //addChildComponent(button);
    addChildComponent(vectorscope);
//    const OwnedArray<AudioProcessorParameter>& params = owner.getParameters();
//    for(int i=0; i<params.size(); ++i)
//    {
//
//        if (const AudioParameterFloat* param = dynamic_cast<AudioParameterFloat*> (params[i]))
//        {
//            if(param->name=="Depth")
//            {
//                depthknob.setRange (param->range.start, param->range.end);
//                //aSlider->setSliderStyle (Slider::LinearHorizontal);
//                depthknob.setSliderStyle (Slider::Rotary);
//                depthknob.setTextBoxStyle(Slider::NoTextBox,true,0,0);
//                depthknob.setLookAndFeel(&otherLookAndFeel);
//                depthknob.setValue (*param);
//                depthknob.addListener (this);
//                addChildComponent (depthknob);
//            }
            /*
             else if(param->name=="Width")
             {
             widthknob.setRange (param->range.start, param->range.end);
             //aSlider->setSliderStyle (Slider::LinearHorizontal);
             widthknob.setSliderStyle (Slider::Rotary);
             widthknob.setTextBoxStyle(Slider::NoTextBox,true,0,0);
             widthknob.setLookAndFeel(&otherLookAndFeel);
             widthknob.setValue (*param);
             widthknob.addListener (this);
             addChildComponent (widthknob);
             }
             */
//        }
//        
//    }
    startTimerHz(60);
}

SquwbsAudioProcessorEditor::~SquwbsAudioProcessorEditor()
{
}
void SquwbsAudioProcessorEditor::timerCallback() {
    
    
    repaint();
    
}
//==============================================================================
void SquwbsAudioProcessorEditor::paint (Graphics& g)
{
    
    //g.fillAll(Colours::white);
    g.fillAll(Colour(135,135,135));
    //vectorscope.load(getProcessor().left,getProcessor().right);
    
    if(isnan(getProcessor().monoNow)){
        speaker.load(0.0);
       // button.load(0.0);
    }
    else {
        speaker.load(getProcessor().monoNow);
        //button.load(getProcessor().monoNow);
    }
    
    /*
     speaker.load(0.0);
     button.load(0.0);
     */
    i=getBounds();
    
    //i.removeFromTop(i.getHeight()*201/256);
    cone=getBounds();
    //cone.removeFromBottom(cone.getHeight()*55/256);
    g.setColour(Colour(135,135,135));
    g.fillRect(i);
    
    //button.setBounds(i);
    //button.setVisible(true);
    //i.removeFromBottom(i.getHeight()*1/3);
    g.setColour(Colours::red);
    
    
    g.setColour(Colours::grey);
    //g.setColour(Colours::white);
    g.setColour(Colour(135,135,135));
    vectorscope.setBounds(cone.getX(),cone.getY()+(cone.reduced(speaker.min*119/1024).getHeight()*25/256),cone.getWidth(),cone.getHeight());
    vectorscope.setVisible(false);
    depthknob.setBounds(cone.getX(),cone.getY()+(cone.reduced(speaker.min*119/1024).getHeight()*25/256),cone.getWidth(),cone.getHeight());
    //depthknob.setVisible(true);
    widthknob.setBounds(cone.reduced(speaker.min*119/1024).getX(),cone.reduced(speaker.min*119/1024).getY()+(cone.reduced(speaker.min*119/1024).getHeight()*25/256),cone.reduced(speaker.min*119/1024).getWidth(),cone.reduced(speaker.min*119/1024).getHeight());
    speaker.setBounds(cone.getX(),cone.getY()+3,cone.getWidth(),cone.getHeight());
    //speaker.setBounds(cone.reduced(speaker.min*119/512).getX(),cone.reduced(speaker.min*119/512).getY()+(cone.reduced(speaker.min*119/1024).getHeight()*25/256),cone.reduced(speaker.min*119/512).getWidth(),cone.reduced(speaker.min*119/512).getHeight());
    //vectorscope.load((getProcessor().left+((float)rand()/(float)(RAND_MAX)*0.25)),(getProcessor().right+((float)rand()/(float)(RAND_MAX)*0.25)),speaker.min/2.0);
    vectorscope.load(getProcessor().leftNow,getProcessor().rightNow);
    speaker.setVisible(true);
    speaker.toBack();
    //g.setColour(Colour(248, 248, 248));
    //g.setColour(Colour(135, 135, 135));
    g.setColour(Colour(75,75,75));
    //testLabel1.setColour(1, Colours::black);
    //testLabel1.setBounds(i);
    //testLabel1.setText(String(i.getHeight()) + String(i.getWidth()), dontSendNotification);
    //testLabel1.setText("hello",dontSendNotification);
    //testLabel1.toFront;
    //testLabel1.setVisible(true);
    
    
    g.setColour(Colours::black);
    g.setFont (14.0f);
    testLabel1.setVisible(false);
    
    //std::cout<<std::to_string(getProcessor().leftNow)<<std::endl;
}
void SquwbsAudioProcessorEditor::mouseDown(const MouseEvent& e){
    lastMousePosition=e.position;
    mouseDrag(e);
}
void SquwbsAudioProcessorEditor::mouseDrag(const MouseEvent& e){

}
void SquwbsAudioProcessorEditor::mouseUp(const MouseEvent& e){
    mouseDrag(e);
}
void SquwbsAudioProcessorEditor::sliderValueChanged(Slider* slider){

}
void SquwbsAudioProcessorEditor::sliderDragStarted(Slider* slider){
    
}
void SquwbsAudioProcessorEditor::sliderDragEnded(Slider* slider){
    
}
void SquwbsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
