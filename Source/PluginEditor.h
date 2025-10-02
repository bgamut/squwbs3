/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "click.h"
#include "Speaker.h"
#include "cone.h"
#include "vectorscope.h"
//==============================================================================
/**
*/
class SquwbsAudioProcessorEditor  : public AudioProcessorEditor, private Timer, public Slider::Listener
{
public:
    SquwbsAudioProcessorEditor (SquwbsAudioProcessor&);
    ~SquwbsAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    void sliderDragStarted(Slider* slider) override;
    void sliderDragEnded(Slider* slider) override;
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent&) override;
    cone speaker;
    Slider depthknob;
    Slider widthknob;
    MenuBarComponent menu;
    Path Circle1;
    Path Circle2;
    Path fftCircle1;
    Path fftCircle2;
    Path vectorscope1;
    Path vectorscope2;
    Path vectorscope3;
    //Path* vectorscope4;
    //float leftEQ[order];
    //float rightEQ[order];
    Label testLabel1;
    Label testLabel2;
    Label testLabel3;
    Label testLabel4;
    Label testLabel5;
    Label testLabel6;
    Label testLabel7;
    Label testLabel8;
    DropShadow logoShadow;
    //LogoComponent logo;
    //click click;
    //chooser chooser;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    //knob knob;
    //Speaker speaker;
    //AudioBuffer<int> analysisBuffer;
    AffineTransform transform;
    Point<float> deltaY;
    juce::Slider mixSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    void timerCallback() override;
    vectorscope vectorscope;
    //logoButton button;
    Rectangle<int> i;
    ApplicationCommandManager manager;
    Rectangle<int> pathBounds;
    Rectangle<int> r;
    Rectangle<int> cone;
    int coneMin;
    //Rectangle<int> logo;
    int logoMin;
    int logoSubMinW;
    int logoSubMinH;
    String left;
    String right;
    
    float x = 0.0;
    float y = 0.0;
    float div = 6.18;
    LookAndFeel_V4 otherLookAndFeel;
    //Image original = ImageCache::getFromMemory(BinaryData::Logo_png, BinaryData::Logo_pngSize);
    Image tiny = ImageCache::getFromMemory(BinaryData::tinyLogo_png, BinaryData::tinyLogo_pngSize);
    
    class ParameterSlider : public Slider,
    private Timer
    {
    public:
        ParameterSlider(AudioProcessorParameter& p)
        : Slider(p.getName(256)), param(p)
        {
            setRange(0.0, 1.0, 0.0);
            startTimerHz(60);
            updateSliderPos();
        }
        
        void valueChanged() override
        {
            if (isMouseButtonDown())
                param.setValueNotifyingHost((float)Slider::getValue());
            else
                param.setValue((float)Slider::getValue());
        }
        
        void timerCallback() override { updateSliderPos(); }
        
        void startedDragging() override { param.beginChangeGesture(); }
        void stoppedDragging() override { param.endChangeGesture(); }
        
        double getValueFromText(const String& text) override { return param.getValueForText(text); }
        String getTextFromValue(double value) override { return param.getText((float)value, 1024); }
        OwnedArray<Slider> paramSliders;
        void updateSliderPos()
        {
            const float newValue = param.getValue();
            
            if (newValue != (float)Slider::getValue() && !isMouseButtonDown())
                Slider::setValue(newValue);
        }
        
        AudioProcessorParameter& param;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterSlider)
    };
    
    //OwnedArray<Slider> paramSliders;
    
    AudioParameterFloat* getParameterForSlider(Slider* slider);
    //ScopedPointer<ParameterSlider> gainSlider;
    //AudioProcessorUndoAttachment audioProcessorUndoAttachment();
    UndoManager* undoMangaer;
    Point<float> lastMousePosition;
    juce::Slider mix;
    SquwbsAudioProcessor& audioProcessor;
    
    SquwbsAudioProcessor& getProcessor() const
    
    {
        return static_cast<SquwbsAudioProcessor&> (processor);
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SquwbsAudioProcessorEditor)
};
