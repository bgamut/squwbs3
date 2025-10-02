/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/
#include <math.h>
#include "PluginProcessor.h"
#include "PluginEditor.h"

double oneLP6::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  return buf0;
}
double oneLP12::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  return buf1;
}
double oneLP24::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  return buf3;
}
double oneLP36::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  buf4 += cutoff * (buf3 - buf4);
  buf5 += cutoff * (buf4 - buf5);
  return buf5;
}
double oneLP48::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  buf4 += cutoff * (buf3 - buf4);
  buf5 += cutoff * (buf4 - buf5);
  buf6 += cutoff * (buf5 - buf6);
  buf7 += cutoff * (buf6 - buf7);
  return buf7;
}
double oneHP12::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  return inputValue - buf1;
}
double oneHP24::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  return inputValue - buf3;
}
double oneHP36::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  buf4 += cutoff * (buf3 - buf4);
  buf5 += cutoff * (buf4 - buf5);
  return inputValue - buf5;
}
double oneHP48::process(double inputValue) {
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  buf4 += cutoff * (buf3 - buf4);
  buf5 += cutoff * (buf4 - buf5);
  buf6 += cutoff * (buf5 - buf6);
  buf7 += cutoff * (buf6 - buf7);
  return inputValue - buf7;
}
double oneNotch::process(double inputValue){
  buf0 += cutoff * (inputValue - buf0);
  buf1 += cutoff * (buf0 - buf1);
  buf2 += cutoff * (buf1 - buf2);
  buf3 += cutoff * (buf2 - buf3);
  return inputValue - (buf0 - buf3);
}
void oneEq3::set(int sampleRate){
  lf.set(250*2*sin((M_PI)/sampleRate));
  mf1.set(250*2*sin((M_PI)/sampleRate));
  mf2.set(2500*2*sin((M_PI)/sampleRate));
  hf.set(2500*2*sin((M_PI)/sampleRate));
}
double oneEq3::process(double input){
  return (lg*lf.process(input))+(mg*mf2.process(mf1.process(input)))+(hg*hf.process(input));
}
void oneLFO::setFrequency(double frequency) {
  mFrequency = frequency;
  updateIncrement();
}
void oneLFO::setSampleRate(double sampleRate){
  mSampleRate = sampleRate;
  updateIncrement();
}
void oneLFO::setPhase(double Phase) {
  mPhase = Phase;
}
void oneLFO::updateIncrement() {
  mPhaseIncrement = mFrequency * 2 * 3.141952 / mSampleRate;
}
double oneLFO::process(double inputValue) {
  if (inputValue == 0.0) {
    return 0.0;
  }
  else {
    out = inputValue+sin(mPhase)/16;
    mPhase += mPhaseIncrement;
    if (mPhase >= (2 * 3.141952)) {
      mPhase -= (2 * 3.141952);
      return out;
    }
    else{
      return out;
    }
  }
}
double oneClipper::process(double inputValue){
  //k = inputValue*pow (atan (pow(abs (inputValue), 100)),1/100);
  //k=inputValue*pow (atan (pow(fabs (inputValue), 5)),1/13);
  //k= atan(pow((inputValue),(5/13)));
  k=atanf(inputValue)/atanf(1.0);
  return k;
}

double oneCompressor::peakFinder(double inputValue){
  inputAbs = fabs(inputValue);
  if(inputAbs>peakOutput){
    peakfinderB0=peakfinderB0Attack;
  }
  else{
    peakfinderB0=peakfinderB0Release;
  }
  peakOutput+=peakfinderB0*(inputAbs-peakOutput);
  return peakOutput;
}
void oneCompressor::set(double sampleRate){
  fs=sampleRate;
  peakOutput=0.0;
  peakB0Attack=1.0;
  peakfinderA1=exp(-1.0/(peakfinderReleaseTime*fs));
  peakfinderB0Release=1.0-peakfinderA1;
  outputGain=0.0;
  dynamicsAttackTime=0.0;
  dynamicsB0Attack= 1.0-exp(-1.0/(dynamicsAttackTime*fs));
  dynamicsReleaseTime=0.5;
  dynamicsB0Release=1.0-exp(-1.0/(dynamicsReleaseTime*fs));
  dynamicsOutputGain=0.0;
}
double oneCompressor::dynamics(double inputGain){
  if(inputGain<dynamicsOutputGain){
    dynamicsB0=dynamicsB0Attack;
  }
  else{
    dynamicsB0=dynamicsB0Release;
  }
  dynamicsOutputGain += dynamicsB0*(inputGain-dynamicsOutputGain);
  return dynamicsOutputGain;
}
void oneGate::set(double sampleRate){
  sr=sampleRate;
  releaseTime=0.3;
  attackTime=0.02;
  threshold=0.001;
  release=1.0-exp(-1.0/(releaseTime*sr));
  hold=holdTime*sr;
  //attack=1.0-exp(-1.0/(attackTime*sr));
  attack=1.0-exp(-1.0/1.0);
}
double oneGate::process(double inputValue){
  if(tick>int(hold)){
    if(threshold>(inputValue*inputValue)){
      gain*=release;
    }
    else{
      tick=0;
      gain*=attack;
    }
  }
  else{
    tick+=1;
    gain=1.0;
  }
  outputValue=inputValue*gain;
  return inputValue;
}
void oneEnvelopeFollower::set(double attackMs, double releaseMs, int sampleRate){
  attack=pow( 0.01, 1.0 / ( attackMs * sampleRate * 0.001 ) );
  release=pow( 0.01, 1.0 / ( releaseMs * sampleRate * 0.001 ) );
  
}
void oneEnvelopeFollower::process(double input){
  temp=fabs(input);
  if(temp>envelope)
    envelope=attack*(envelope-temp)+temp;
  else
    envelope=release*(envelope-temp)+temp;
}
void oneLimiter::set(double attackMs, double releaseMs,double thresholdDb,int sampleRate){
  attackCoeff=exp(-1*(attackMs*double(sampleRate)*1000.0));
  releaseCoeff=exp(-1*(releaseMs*double(sampleRate)*1000.0));
  delayIndex=0;
  env=0.0;
  threshold=powf(powf(2.0,1/6),(thresholdDb-6.0));
  sr=sampleRate;
  currentGain=1.0;
  targetGain=1.0;
}
/*
double Limiter::process(double input){
    delayLine[delayIndex]=input;
    delayIndex=(delayIndex+1)%delayLength;
    env *= releaseCoeff;
    env = MAX(fabs(input), env);
    if (env>threshold){
      targetGain=(1+threshold-env);
    }
    else{
      targetGain=1.0;
    }
    currentGain=currentGain*attackCoeff+targetGain*(1-attackCoeff);
    return delayLine[delayIndex]*currentGain;
}
*/

double oneLimiter::process(double input){
  delayIndex=(delayIndex+1)%(2*sr);
  env = fmax(fabs(input), env);
  if (env>threshold){
    targetGain=(2*threshold/env)-1.0;
  }
  else{
    targetGain=1.0;
  }
  env *= releaseCoeff;
  if (delayIndex==0){
    env=1.0;
  }
  currentGain=currentGain*attackCoeff+targetGain*(1-attackCoeff);
  return (input*targetGain);
}
void oneLimiter::resetEnv(){
  env=0.0;
}
void oneXcomp::set(int sampleRate){
  sampleRate = sampleRate;
		fConst0 = fmin(192000.0, fmax(1000.0, double(sampleRate)));
		fConst1 = expf((0.0 - (2500.0 / fConst0)));
		fConst2 = (1.0 - fConst1);
		fConst3 = expf((0.0 - (1250.0 / fConst0)));
		fConst4 = expf((0.0 - (2.0 / fConst0)));
    fTemp0=0.0;
    fTemp1=0.0;
    fTemp2=0.0;
    for (int i =0; i<2; ++i){
      fRec0[i]=0.0;
      fRec1[i]=0.0;
      fRec2[i]=0.0;
    }
  
}
double oneXcomp::process(double input){
  fTemp0=input;
  fTemp1=fabs(fTemp0);
  fTemp2 = ((fRec1[1]>fTemp1)?fConst4:fConst3);
  fRec2[0] = ((fRec2[1] * fTemp2) + ((1.0f - fTemp2) * fTemp1));
  fRec1[0] = fRec2[0];
  fRec0[0] = ((fConst1 * fRec0[1]) + (fConst2 * (0.0 - (0.949999988 * fmax(((20.0 * log10f(fRec1[0])) + 30.0), 0.0)))));
  output = double((powf(10.0, (0.0500000007 * fRec0[0])) * fTemp0));
  fRec2[1] = fRec2[0];
  fRec1[1] = fRec1[0];
  fRec0[1] = fRec0[0];
  return output;
}
//==============================================================================
SquwbsAudioProcessor::SquwbsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
    ,parameters(*this,nullptr,"Parameters",
                {
                     std::make_unique<juce::AudioParameterFloat>("mix","Mix",0.0f,100.0f,50.0f)
                 })

#endif
{
}

SquwbsAudioProcessor::~SquwbsAudioProcessor()
{
}

//==============================================================================
const String SquwbsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SquwbsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SquwbsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SquwbsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SquwbsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SquwbsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SquwbsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SquwbsAudioProcessor::setCurrentProgram (int index)
{
}

const String SquwbsAudioProcessor::getProgramName (int index)
{
    return {};
}

void SquwbsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SquwbsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    /*
    AudioDeviceManager deviceManager;
    AudioDeviceManager::AudioDeviceSetup deviceSetup = AudioDeviceManager::AudioDeviceSetup();
    deviceSetup.sampleRate = sampleRate;
    deviceManager.initialise (2,2,0,true,String::empty,&deviceSetup);
    deviceSetup.useDefaultInputChannels=true;
    */
    preLPLeft.set(2*sin((M_PI)*10000.0/sampleRate));
    preLPRight.set(2*sin((M_PI)*10000.0/sampleRate));
    monoLimiterLeft.set(0.00001,1500.0,-24.0,sampleRate);
    monoLimiterRight.set(0.00001,1500.0,-24.0,sampleRate);
    
    TLimiterLeft.set(0.00001,1500.0,-24.0,sampleRate);
    TLimiterRight.set(0.00001,1500.0,-24.0,sampleRate);
    
    finalLimiterLeft.set(0.00001,1500.0,-6.0,sampleRate);
    finalLimiterRight.set(0.00001,1500.0,-6.0,sampleRate);
    
    MsubLPLeft.set(2*sin((M_PI)*750.0/sampleRate));
    MsubLPRight.set(2*sin((M_PI)*750.0/sampleRate));
    
    MHP1Left.set(2*sin((M_PI)*40.0/sampleRate));
    MHP1Right.set(2*sin((M_PI)*40.0/sampleRate));
    
    MHP1Left.calculateFeedbackAmount();
    MHP1Right.calculateFeedbackAmount();
    
    MLP1Left.set(2*sin((M_PI)*11200.0/sampleRate));
    MLP1Right.set(2*sin((M_PI)*11200.0/sampleRate));
    
    MLP2Left.set(2*sin((M_PI)*6000.0/sampleRate));
    MLP2Right.set(2*sin((M_PI)*6000.0/sampleRate));
    
    MLP1Left.calculateFeedbackAmount();
    MLP1Right.calculateFeedbackAmount();
    
    MLP2Left.calculateFeedbackAmount();
    MLP2Right.calculateFeedbackAmount();
    
    SHP1Left.set(2*sin((M_PI)*750.0/sampleRate));
    SHP1Right.set(2*sin((M_PI)*750.0/sampleRate));
    
    SHP1Left.calculateFeedbackAmount();
    SHP1Right.calculateFeedbackAmount();
    
    SLP1Left.set(2*sin((M_PI)*10000.0/sampleRate));
    SLP1Right.set(2*sin((M_PI)*10000.0/sampleRate));
    
    SLP1Left.calculateFeedbackAmount();
    SLP1Right.calculateFeedbackAmount();
    
    SEQLeft.set(sampleRate);
    SEQRight.set(sampleRate);
    
    TGateLeft.set(sampleRate);
    TGateRight.set(sampleRate);
    
    LP1Left.set(2*sin((M_PI)*15000.0/sampleRate));
    LP1Right.set(2*sin((M_PI)*15000.0/sampleRate));
    eq1.setSampleRate(sampleRate);
    eq2.setSampleRate(sampleRate);
    
    preHPOneLeft.set(2*sin((M_PI)*44.0/sampleRate));
    preHPOneRight.set(2*sin((M_PI)*44.0/sampleRate));
    preHPTwoLeft.set(2*sin((M_PI)*75.0/sampleRate));
    preHPTwoRight.set(2*sin((M_PI)*75.0/sampleRate));
    preLPOneLeft.set(2*sin((M_PI)*2500.0/sampleRate));
    preLPOneRight.set(2*sin((M_PI)*2500.0/sampleRate));
    preLPTwoLeft.set(2*sin((M_PI)*7000.0/sampleRate));
    preLPTwoRight.set(2*sin((M_PI)*7000.0/sampleRate));
    
    
    
    
    
}

void SquwbsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SquwbsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SquwbsAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    float mixFloat = *parameters.getRawParameterValue("mix");
    juce::AudioSampleBuffer main = getBusBuffer(buffer, true, 0);

    
    if (main.getNumChannels() == 1)
    {
        
        for (int j = 0; j<main.getNumSamples(); ++j)
        {

            
            float left = main.getSample(0, j);
            float right = main.getSample(0, j);
            
            monoNow = (abs(left)+abs(right))/2.0;
            
            main.setSample(0, j, finalLimiterLeft.process(finalClipperLeft.process(eq1.match(left,right)[0]*mixFloat/4.0+left*(1.0-(mixFloat/100.0)))));
            main.setSample(1, j,
                finalLimiterRight.process(finalClipperRight.process(eq2.match(left,right)[1]*mixFloat/4.0+right*(1.0-(mixFloat/100.0)))));
        }
    }
        
        
    
    else if (main.getNumChannels() == 2)
    {

        for (int j = 0; j<main.getNumSamples(); ++j)
        {
            float left = main.getSample(0, j);
            float right = main.getSample(1, j);
            
            monoNow = (abs(left)+abs(right))/2.0;
            
            main.setSample(0, j, finalLimiterLeft.process(finalClipperLeft.process(eq1.match(left,right)[0]*mixFloat/4.0+left*(1.0-(mixFloat/100.0)))));
            main.setSample(1, j,
                finalLimiterRight.process(finalClipperRight.process(eq2.match(left,right)[1]*mixFloat/4.0+right*(1.0-(mixFloat/100.0)))));
        }
    }
/*
    AudioSampleBuffer main = getBusBuffer(buffer, true, 0);

    
    if (main.getNumChannels() == 1)
    {
        
        for (int j = 0; j<main.getNumSamples(); ++j)
        {
            
            
            float left = preLPTwoLeft.process(preLPOneLeft.process(preHPTwoLeft.process(preHPOneLeft.process(preLPLeft.process(main.getSample(0, j))))));
            float right = preLPTwoRight.process(preLPOneRight.process(preHPTwoRight.process(preHPOneRight.process(preLPRight.process(main.getSample(0, j))))));
            
            float mono = monoLimiterLeft.process((left + right)*0.35481338923357547/ 2.0);
            float monoprocessed = MLP2Right.process(MLP1Right.process(MHP1Left.process(MsubLPLeft.process(mono)+mono)));
            left = left - mono;
            right = right - mono;
            
            {
                
                float mixleft = SEQLeft.process  (SLP1Left.process (SHP1Left.process (left*0.38 )))+monoprocessed;
                float mixright = SEQRight.process(SLP1Right.process(SHP1Right.process(right*0.38)))+monoprocessed;
                
                //float* sample = eq1.match(,);
                leftNow = (TGateLeft.process(mixleft)+TLimiterLeft.process (mixleft ));
                rightNow = (TGateLeft.process(mixright)+TLimiterLeft.process(mixright));
                monoNow = (abs(leftNow)+abs(rightNow))/2.0;
                main.setSample(0, j, finalLimiterLeft.process (leftNow/2.0));
                main.setSample(1, j, finalLimiterRight.process(rightNow/2.0));

            }
        }
        
        
    }
    else if (main.getNumChannels() == 2)
    {
        for (int j = 0; j<main.getNumSamples(); ++j)
        {
            float left = preLPTwoLeft.process(preLPOneLeft.process(preHPTwoLeft.process(preHPOneLeft.process(preLPLeft.process(main.getSample(0, j))))));
            float right = preLPTwoRight.process(preLPOneRight.process(preHPTwoRight.process(preHPOneRight.process(preLPRight.process(main.getSample(1, j))))));

            float mono = monoLimiterLeft.process((left + right)/ 2.0);
            float monoprocessed = MLP2Right.process(MLP1Right.process(MHP1Left.process(MsubLPLeft.process(mono)+mono)));
            left=left-mono;
            right=right-mono;
            
            {
                
                float mixleft  =  SEQLeft.process(SLP1Left.process (SHP1Left.process (left*0.38 )))+monoprocessed;
                float mixright = SEQRight.process(SLP1Right.process(SHP1Right.process(right*0.38)))+monoprocessed;
                //float* sample = eq1.match(,);
                leftNow = (TGateLeft.process(mixleft)+TLimiterLeft.process (mixleft ));
                rightNow = (TGateLeft.process(mixright)+TLimiterLeft.process(mixright));
                monoNow = (abs(leftNow)+abs(rightNow))/2.0;
                main.setSample(0, j, finalLimiterLeft.process (leftNow/2.0));
                main.setSample(1, j, finalLimiterRight.process(rightNow/2.0));
                
            }
        }
    }
    */
}

//==============================================================================
bool SquwbsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SquwbsAudioProcessor::createEditor()
{
    return new SquwbsAudioProcessorEditor (*this);
}

//==============================================================================
void SquwbsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SquwbsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SquwbsAudioProcessor();
}
