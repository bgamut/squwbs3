/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ThreeBandEQ.h"

//==============================================================================
/**
*/

class oneLP6 {
public:
  oneLP6() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  
  double buf0;
};
class oneLP12 {
public:
    oneLP12() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    
    double buf0;
    double buf1;
};
class oneLP24 {
public:
    oneLP24() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0),
	buf2(0.0),
    buf3(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    
    double buf0;
    double buf1;
	double buf2;
	double buf3;
};
class oneLP36 {
public:
  oneLP36() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;
};
class oneLP48 {
public:
  oneLP48() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0),
  buf6(0.0),
  buf7(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;
  double buf6;
  double buf7;
};
class oneHP12 {
public:
    oneHP12() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    double buf0;
    double buf1;
};
class oneHP24 {
public:
    oneHP24() :
    cutoff(0.1),
    resonance(0.0),
    buf0(0.0),
    buf1(0.0),
	buf2(0.0),
    buf3(0.0)
    {
        calculateFeedbackAmount();
    };
    double process(double inputValue);
    inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
    double cutoff;
    double resonance;
    double feedbackAmount;
    double buf0;
    double buf1;
	double buf2;
	double buf3;
};
class oneHP36 {
public:
  oneHP36() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;

};
class oneHP48 {
public:
  oneHP48() :
  cutoff(0.1),
  resonance(0.0),
  buf0(0.0),
  buf1(0.0),
  buf2(0.0),
  buf3(0.0),
  buf4(0.0),
  buf5(0.0),
  buf6(0.0),
  buf7(0.0)
  {
    calculateFeedbackAmount();
  };
  double process(double inputValue);
  inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
  inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
  inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance/(1.0 - cutoff); }
private:
  double cutoff;
  double resonance;
  double feedbackAmount;
  double buf0;
  double buf1;
  double buf2;
  double buf3;
  double buf4;
  double buf5;
  double buf6;
  double buf7;
};
class oneNotch {
public:
	oneNotch() :
		cutoff(0.1),
		resonance(1.0),
		buf0(0.0),
		buf1(0.0),
		buf2(0.0),
		buf3(0.0)
	{
		calculateFeedbackAmount();
	};
	double process(double inputValue);
	inline void set(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
	inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    inline void calculateFeedbackAmount() { feedbackAmount = resonance + resonance / (1.0 - cutoff); }
private:
	double cutoff;
	double resonance;
	double feedbackAmount;
	double buf0;
	double buf1;
	double buf2;
	double buf3;

};
class oneEq3{
public:
  oneEq3():
    lg(1.0),
    mg(powf(powf(2.0,1/6),(-10.5))),
    hg(1.0)
  {
    lf.setResonance(0.0);
    mf1.setResonance(0.0);
    mf2.setResonance(0.0);
    hf.setResonance(0.0);
  }
  double process(double inputValue);
  void set(int sampleRate);
private:
  oneLP24 lf;
  oneHP24 mf1;
  oneLP24 mf2;
  oneHP24 hf;
  double lg;
  double mg;
  double hg;
};
class oneClipper {
public:
	double process(double inputValue);
private:
	double k;
};
class oneLFO {
public:
	oneLFO() :
		out(0.0),
		mPI(2 * acos(0.0)),
		mFrequency(0.00001),
		mPhase(0.0),
		mSampleRate(44100.0) {
		updateIncrement();
	};
	void setFrequency(double Frequency);
	void setSampleRate(double sampleRate);
	void setPhase(double phase);
	double process(double inputValue);
private:
	const double mPI;
	double mFrequency;
	double mPhase;
	double mSampleRate;
	double mPhaseIncrement;
	void updateIncrement();
	double out;
};
class oneCompressor{
public:
  oneCompressor():
    peakOutput(0.0),
    peakB0Attack(1.0),
    outputGain(0.0),
    dynamicsAttackTime(0.0),
    dynamicsReleaseTime(0.5),
    dynamicsOutputGain(0.0) {
    set(44100);
  };
  void set(double sampleRate);
  double dynamics(double inputGain);
  double peakFinder(double inputValue);
private:
  double inputAbs;
  double peakfinderB0;
  double peakOutput;
  double fs;
  double peakfinderB0Attack;
  double peakfinderFinderA1;
  double peakfinderB0Release;
  double peakfinderReleaseTime;
  double peakB0Attack;
  double peakfinderA1;
  double outputGain;
  double dynamicsAttackTime;
  double dynamicsB0Attack;
  double dynamicsReleaseTime;
  double dynamicsB0Release;
  double dynamicsOutputGain;
  double dynamicsB0;
  
};
class oneEnvelopeFollower
{
public:
  oneEnvelopeFollower():
    envelope(0)
  {
    set(10.0,200.0,44100);
  };
  void set(double attackMs, double releaseMs, int sampleRate);
  void process(double input);
  double sidechain(double input, double sidechainSignal);
  double envelope;
private:
  double temp;
  double attack;
  double release;
};

class oneLimiter{
public:
  oneLimiter():
    attackCoeff(0.0),
    releaseCoeff(0.0),
    env(0.0),
    targetGain(1.0),
    currentGain(1.0),
    delayIndex(0)
  {
    set(0.001,400.0,-24.0,44100);
  };
  double process(double input);
  void set(double attackMs, double releaseMs, double thresholdDb,int sampleRate);
  void resetEnv();
private:
  double attackCoeff;
  double releaseCoeff;
  double env;
  double targetGain;
  double currentGain;
  int delayIndex;
  int delayLength;
  int sr;
  //double* delayLine;
  double threshold;
};
class oneGate{
public:
  oneGate():
  releaseTime(1.5),
  sr(44100),
  threshold(powf(powf(2.0,1/6),(-54.0))),
  outputValue(0.0),
  gain(1.0),
  holdTime(1.0),
  attackTime(0.01){
    set(44100.0);
  };
  double process(double inputValue);
  void set(double sampleRate);
private:
  double releaseTime;
  double sr;
  double release;
  double threshold;
  double outputValue;
  double gain;
  int tick;
  double hold;
  double holdTime;
  double attack;
  double attackTime;
};
class oneXcomp{
public:
  void set(int sampleRate);
  double process(double inputValue);
private:
  int sampleRate;
  double fRec2[2];
  double fRec1[2];
  double fRec0[2];
  double fConst0;
  double fConst1;
  double fConst2;
  double fConst3;
  double fConst4;
  double fTemp0;
  double fTemp1;
  double fTemp2;
  double output;
};

class oneXlimiter{
public:
  void set(int sampleRate);
  double process(double inputValue);
private:
  int sampleRate;
  double fRec2[2];
  double fRec1[2];
  double fRec0[2];
  double b1;
  double b2;
  double attack;
  double release;
  double temp;
  double mag;
  double env;
  double output;
};

class SquwbsAudioProcessor  : public juce::AudioProcessor,
                                public juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    SquwbsAudioProcessor();
    ~SquwbsAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    float leftNow=0.0;
    float rightNow=0.0;
    float monoNow=0.0;
    int lastUIWidth = 200;
    int lastUIHeight = 200;
    float monoLevel = 0.0;
    float l[8] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float r[8]= {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float mixleft = 0.0;
    float mixright = 0.0;
    /*
     double dpleft = 0.0;
     double dpright = 0.0;
     double dpmono = 0.0;
     double dpmonoLevel = 0.0;
     double dpmixleft = 0.0;
     double dpmixright = 0.0;
     double dpl[8] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
     double dpr[8] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
     */
    float FFTMagLeft[8] = { 0,0,0,0,0,0,0,0 };
    float FFTMagRight[8] = { 0,0,0,0,0,0,0,0 };
    float lrms = 0.0;
    float rrms = 0.0;
    int samplerate;
    int blocklength;
    ThreeBandEQ eq1;
    ThreeBandEQ eq2;
    //FourBandEQ eq3;
    //FourBandEQ eq4;
    bool fileSelected=false;
    AudioParameterFloat* depth;
    AudioParameterFloat* width;
    float currentDepth;
    float targetDepth;
    float ramp;
    void parameterChanged (const juce::String& parameterID, float newValue) override
        {
            // Your logic for when a parameter changes
            juce::ignoreUnused (parameterID, newValue); // Prevent unused parameter warnings
        }
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mix;
    juce::AudioProcessorValueTreeState parameters;
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SquwbsAudioProcessor)
    oneLP12 preLPLeft;
    oneLP12 preLPRight;
    oneLimiter monoLimiterLeft;
    oneLimiter monoLimiterRight;
    oneLP36 MsubLPLeft;
    oneLP36 MsubLPRight;
    oneHP36 MHP1Left;
    oneHP36 MHP1Right;
    oneLP36 MLP1Left;
    oneLP36 MLP1Right;
    oneLP36 MLP2Left;
    oneLP36 MLP2Right;
    oneHP36 SHP1Left;
    oneHP36 SHP1Right;
    oneLP24 SLP1Left;
    oneLP24 SLP1Right;
    oneLP24 LP1Left;
    oneLP24 LP1Right;
    oneEq3 SEQLeft;
    oneEq3 SEQRight;
    oneLimiter TLimiterLeft;
    oneLimiter TLimiterRight;
    oneGate TGateLeft;
    oneGate TGateRight;
    oneLimiter finalLimiterLeft;
    oneLimiter finalLimiterRight;
    oneHP48 preHPOneLeft;
    oneHP48 preHPOneRight;
    oneHP12 preHPTwoLeft;
    oneHP12 preHPTwoRight;
    oneLP12 preLPOneLeft;
    oneLP12 preLPOneRight;
    oneLP24 preLPTwoLeft;
    oneLP24 preLPTwoRight;
    oneClipper finalClipperLeft;
    oneClipper finalClipperRight;
    AudioDeviceManager manager;
    
    
};
