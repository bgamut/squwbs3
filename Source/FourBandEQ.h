/*
  ==============================================================================

    ThreeBandEQ.h
    Created: 7 Feb 2018 4:29:39pm
    Author:  cumbe

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "HP12.h"
#include "LP12.h"
#include "Clipper.h"
#include "Gate.h"
#include "Phaser.h"
#include "LP24.h"
//==============================================================================
/*

*/

class FourBandEQ    : public Component
{
public:
    FourBandEQ()
	{
        setSampleRate(44100);
        setGains(1.0,1.0,1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
        //setRatios(0.75, 0.75, 0.5, 0.5, 0.25, 0.25),
        setRatios(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
        setMidHP(20.0);
        setSideHP(200.0);
        setMidLMC(175.0);
        setSideLMC(175.0);
        setMidMHC(2750.0);
        setSideMHC(2750.0);
        setMidTOP(10000.0);
        setSideTOP(10000.0);
        setMidLP(2250.0);
        setSideLP(6000.0);
        resetMatch();
        //setGoals(0.068,0.031,0.039,0.043,0.035,0.038,0.031,0.031,0.031,0.063,0.063,0.063);
        setGoals(0.09,0.146,0.236,0.618,
                 0.073,0.146,0.236,0.38,
                 0.09,0.09,0.031,0.031,
                 0.09,0.09,0.031,0.0);
        
        reset();
        //below is the data from eot
        
        
		//setGoals(0.03008, 0.068, 0.031, 0.039, 0.05383, 0.043, 0.035, 0.038, 0.031, 0.031, 0.031, 0.031, 0.063, 0.063, 0.063, 0.063);

		//setGoals(0.003008, 0.068, 0.108080, 0.112189, 0.005383, 0.043, 0.043991, 0.011409, 0.031, 0.031, 0.031, 0.031, 0.063, 0.063, 0.063, 0.063);
		//below is the data from starbucks jongro(rms/160000.0)
        /*
        gate1.setThreshold(0.00000026875);
        gate2.setThreshold(0.00000021875);
        gate3.setThreshold(0.0000002375);
        gate4.setThreshold(0.000000425);
        gate5.setThreshold(0.00000019375);
        gate6.setThreshold(0.00000024375);
        gate7.setThreshold(0.00000026875);
        gate8.setThreshold(0.00000021875);
        gate9.setThreshold(0.0000002375);
        */
        
	}

    ~FourBandEQ()
    {
    }

void setMidHP(float freq) {
	midHP.set(freq);
}
void setSideHP(float freq) {
	leftHP.set(freq);
	rightHP.set(freq);
}

void setMidLP(float freq) {
	midLP.set(freq);
}
void setSideLP(float freq) {
	leftLP.set(freq);
	rightLP.set(freq);
}
void setMidLMC(float freq){
    midLPL.set(freq);
    midHPM.set(freq);
}
void setSideLMC(float freq){
    leftLPL.set(freq);
    rightLPL.set(freq);
    leftHPM.set(freq);
    rightHPM.set(freq);
}

void setMidMHC(float freq){
    midLPM.set(freq);
    midHPH.set(freq);
}
void setSideMHC(float freq){
    leftLPM1.set(freq);
    leftLPM2.set(freq);
    rightLPM1.set(freq);
    rightLPM2.set(freq);
    leftHPH.set(freq);
    rightHPH.set(freq);
}

void setMidTOP(float freq){
    midHPT.set(freq);
    midLPH.set(freq);
}

void setSideTOP(float freq){
    leftHPT.set(freq);
    rightHPT.set(freq);    
    leftLPH.set(freq);
    rightLPH.set(freq);

}


float mid(float left, float right){
    return (left+right)/2.0;
}

float leftOnly(float left, float right){
    return left-mid(left,right);
}

float rightOnly(float left, float right){
    return right-mid(left,right);
}
void reset() {
	leftlowtmp = 0;
	leftmidtmp = 0;
	lefthightmp = 0;
	lefttoptmp=0;
	midlowtmp = 0;
	midmidtmp = 0;
	midhightmp = 0;
	midtoptmp = 0;
	rightlowtmp = 0;
	rightmidtmp = 0;
	righthightmp = 0;
	righttoptmp = 0;
	sidelowrms = 0;
	sidemidrms = 0;
	sidehighrms = 0;
	sidetoprms = 0;
	midlowrms = 0;
	midmidrms = 0;
	midhighrms = 0;
	midtoprms = 0;
	sidelowsd = 0;
	sidemidsd = 0;
	sidehighsd = 0;
	sidetopsd = 0;
	m=0;
	l = 0;
	r = 0;
	midt = 0;
	midh = 0;
	midm = 0;
	midl = 0;
	leftt = 0;
	lefth = 0;
	leftm = 0;
	leftl = 0;
	rightt = 0;
	righth = 0;
	rightm = 0;
	rightl = 0;
	pltrms = 0;
	plhrms = 0;
	plmrms = 0;
	pllrms = 0;
	pmtrms = 0;
	pmhrms = 0;
	pmmrms = 0;
	pmlrms = 0;
	prtrms = 0;
	prhrms = 0;
	prmrms = 0;
	prlrms = 0;
	pltsd = 0;
	plhsd = 0;
	plmsd = 0;
	pllsd = 0;
	pmtsd = 0;
	pmhsd = 0;
	pmmsd = 0;
	pmlsd = 0;
	prtsd = 0;
	prhsd = 0;
	prmsd = 0;
	prlsd = 0;
	for (int i = 0; i < 8; i++) {
	    processlefttop[i] = 0.0;
		processlefthigh[i] = 0.0;
		processleftmid[i] = 0.0;
		processleftlow[i] = 0.0;
		processmidtop[i] = 0.0;
		processmidhigh[i] = 0.0;
		processmidmid[i] = 0.0;
		processmidlow[i] = 0.0;
		processrighttop[i] = 0.0;
		processrighthigh[i] = 0.0;
		processrightmid[i] = 0.0;
		processrightlow[i] = 0.0;
	};
	index = 0;
}
void setGains(float m, float s,float tm,float hm,float mm, float lm, float ts, float hs, float ms, float ls){
    midGain=m;
    sideGain=s;
	topMidGain=tm;
    highMidGain=hm;
    midMidGain=mm;
    lowMidGain=lm;
    topSideGain=ts;
    highSideGain=hs;
    midSideGain=ms;
    lowSideGain=ls;
}
void setRatios(float tm, float hm, float mm, float lm, float ts, float hs, float ms, float ls) {
	topMidRatio=1.0;
	topSideRatio=1.0;
    highMidRatio=1.0;
	highSideRatio=1.0;
	midMidRatio=1.0;
	midSideRatio=1.0;
	lowMidRatio=1.0;
	lowSideRatio=1.0;
}


void setSampleRate(float sr){
    leftLPL.setSampleRate(sr);
	rightLPL.setSampleRate(sr);
	midLPL.setSampleRate(sr);
    
	leftLPM1.setSampleRate(sr);
    leftLPM2.setSampleRate(sr);
    rightLPM1.setSampleRate(sr);
    rightLPM2.setSampleRate(sr);
	midLPM.setSampleRate(sr);
	
	leftLPH.setSampleRate(sr);
	rightLPH.setSampleRate(sr);
	midLPH.setSampleRate(sr);
    
	leftLP.setSampleRate(sr);
	rightLP.setSampleRate(sr);
	midLP.setSampleRate(sr);
    
	leftHPM.setSampleRate(sr);
	rightHPM.setSampleRate(sr);
	midHPM.setSampleRate(sr);
    
	leftHPH.setSampleRate(sr);
	rightHPH.setSampleRate(sr);
	midHPH.setSampleRate(sr);
	
	leftHPT.setSampleRate(sr);
	rightHPT.setSampleRate(sr);
	midHPT.setSampleRate(sr);
    
	phaser1.Rate(0.002, sr);
	phaser2.Rate(0.002, sr);
    gate1.set(sr);
    gate2.set(sr);
    gate3.set(sr);
    //gate4.set(sr);
    //gate5.set(sr);
    //gate6.set(sr);
    //gate7.set(sr);
    //gate8.set(sr);
    //gate9.set(sr);
    
}
    

void runStats(float* left, float*right, int length) {
	for (int i=0; i<length; i++){
		m = midHP.process(midLP.process(mid(left[i], right[i])));
		l = leftHP.process(leftOnly(left[i], right[i]));
		r = rightHP.process(rightOnly(left[i], right[i]));
        
		midt = midHPT.process(m);
		midh = midHPH.process(midLPT.process(m));
		midm = midHPM.process(midLPM.process(m));
		midl = midLPL.process((m));
        
		leftt = leftHPT.process(l);
		lefth = leftHPH.process(leftLPT.process(l));
		leftm = leftHPM.process(leftLPM1.process(l));
		leftl = leftLPL.process((l));
		rightt = rightHPT.process(r);
		righth = rightHPH.process(rightLPT.process(r));
		rightm = rightHPM.process(rightLPM1.process(r));
		rightl = rightLPL.process((r));
		
        sidetoprms += (abs(leftt/(2.0*float(length)))+abs(rightt/(2.0*float(length))));
		sidehighrms += (abs(lefth/(2.0*float(length)))+abs(righth/(2.0*float(length))));
		sidemidrms += (abs(leftm/(2.0*float(length)))+abs(rightm/(2.0*float(length))));
		sidelowrms += (abs(leftl/(2.0*float(length)))+abs(rightl/(2.0*float(length))));
        
		midtoprms += (abs(midt/float(length)));
		midhighrms += (abs(midh/float(length)));
		midmidrms += (abs(midm/float(length)));
		midlowrms += (abs(midl/float(length)));
        maximum = fmax(fabs(left[i]),fabs(right[i]));
	}
	for (int i = 0; i < length; i++) {
		sidetopsd += abs(abs(leftt)/(2.0*float(length)) + abs(rightt)/(2.0*float(length)) - (2 * sidetoprms)/(2.0*float(length)));
		sidehighsd += abs(abs(lefth)/(2.0*float(length)) + abs(righth)/(2.0*float(length)) - (2 * sidehighrms)/(2.0*float(length)));
		sidemidsd += abs(abs(leftm)/(2.0*float(length)) + abs(rightm)/(2.0*float(length)) - (2 * sidemidrms)/(2.0*float(length)));
		sidelowsd += abs(abs(leftl)/(2.0*float(length)) + abs(rightl)/(2.0*float(length)) - (2 * sidelowrms)/(2.0*float(length)));
		midtopsd += abs(abs(midt/ float(length)) - midtoprms/ float(length));
		midhighsd += abs(abs(midh/ float(length)) - midhighrms/ float(length));
		midmidsd += abs(abs(midm/ float(length)) - midmidrms/ float(length));
		midlowsd += abs(abs(midl/ float(length)) - midlowrms/ float(length));

	};


	

};
void setGoals(float gmtrms, float gmhrms, float gmmrms, float gmlrms, float gstrms, float gshrms, float gsmrms, float gslrms, float gmtsd, float gmhsd, float gmmsd, float gmlsd, float gstsd, float gshsd, float gsmsd, float gslsd ) {
	
    midtoprms = gmtrms;
	midhighrms = gmhrms;
	midmidrms = gmmrms;
	midlowrms = gmlrms;
	sidetoprms = gstrms;
	sidehighrms = gshrms;
	sidemidrms = gsmrms;
	sidelowrms = gslrms;
	midtopsd = gmtsd;
	midhighsd = gmhsd;
	midmidsd = gmmsd;
	midlowsd = gmlsd;
	sidetopsd = gstsd;
	sidehighsd = gshsd;
	sidemidsd = gsmsd;
	sidelowsd = gslsd;

}
float* match(float left, float right) {

    l = leftHP.process(leftOnly(left, right));
    m = midHP.process(midLP.process(mid(left, right)));
    r = rightHP.process(rightOnly(left, right));
    leftt = leftHPT.process(l);
    lefth = leftHPH.process(leftLPT.process(l));
    leftm = leftHPM.process(leftLPM1.process(l));
    leftl = leftLPL.process(l);
    midt = midHPT.process(m);
    midh = midHPH.process(midLPT.process(m));
    midm = midHPM.process(midLPM.process(m));
    midl = midLPL.process(m);
    rightt = rightHPT.process(r);
    righth = rightHPH.process(rightLPT.process(r));
    rightm = rightHPM.process(rightLPM1.process(r));
    rightl = rightLPL.process(r);
    
	if(index<8){
	    processlefttop[index] = leftt;
		processlefthigh[index] = lefth;
		processleftmid[index] = leftm;
		processleftlow[index] = leftl;
		processmidtop[index] = midt;
		processmidhigh[index] = midh;
		processmidmid[index] = midm;
		processmidlow[index] = midl;
		processrighttop[index] = rightt;
		processrighthigh[index] = righth;
		processrightmid[index] = rightm;
		processrightlow[index] = rightl;
		pltrms += (abs(leftt) / 8.0);
		plhrms += (abs(lefth) / 8.0);
		plmrms += (abs(leftm) / 8.0);
		pllrms += (abs(leftl) / 8.0);
		pmtrms += (abs(midt) / 8.0);
		pmhrms += (abs(midh) / 8.0);
		pmmrms += (abs(midm) / 8.0);
		pmlrms += (abs(midl) / 8.0);
		prtrms += (abs(rightt) / 8.0);
		prhrms += (abs(righth) / 8.0);
		prmrms += (abs(rightm) / 8.0);
		prlrms += (abs(rightl) / 8.0);
		
		index++;
	}
	else {
     
		for (int i = 0; i < 8; i++) {
		    pltsd += (abs(abs(processlefttop[i]/8.0) - (pltrms/8.0)));
			plhsd += (abs(abs(processlefthigh[i]/8.0) - (plhrms/8.0)));
			plmsd += (abs(abs(processleftmid[i]/8.0) - (plmrms / 8.0)));
			pllsd += (abs(abs(processleftlow[i]/8.0) - (pllrms / 8.0)));
			pmtsd += (abs(abs(processmidtop[i]/8.0) - (pmtrms / 8.0)));
			pmhsd += (abs(abs(processmidhigh[i]/8.0) - (pmhrms / 8.0)));
			pmmsd += (abs(abs(processmidmid[i]/8.0) - (pmmrms / 8.0)));
			pmlsd += (abs(abs(processmidlow[i]/8.0) - (pmlrms / 8.0)));
			prtsd += (abs(abs(processrighttop[i]/8.0) - (prtrms /8.0)));
			prhsd += (abs(abs(processrighthigh[i]/8.0) - (prhrms / 8.0)));
			prmsd += (abs(abs(processrightmid[i]/8.0) - (prmrms / 8.0)));
			prlsd += (abs(abs(processrightlow[i]/8.0) - (prlrms / 8.0)));
		}
    }
    setGains(1.0, 0.25, midtopsd/pmtsd, midhighsd / pmhsd, midmidsd / pmmsd, midlowsd / pmlsd, sidetopsd / (pltsd / 2.0 + prhsd / 2.0), sidehighsd / (plhsd / 2.0 + prhsd / 2.0), sidemidsd / (plmsd / 2.0 + prmsd / 2.0), sidelowsd / (pllsd / 2.0 + prlsd / 2.0));
    
    midt = matchBox(midt, pmtrms, midtoprms, midtopsd, pmtsd);
    midh = matchBox(midh, pmhrms, midhighrms, midhighsd, pmhsd);
    midm = matchBox(midm, pmmrms, midmidrms, midmidsd, pmmsd);
    midl = matchBox(midl, pmlrms, midlowrms, midlowsd, pmlsd);
    leftt = matchBox(leftt, pltrms, sidetoprms, sidetopsd, pltsd);
    lefth = matchBox(lefth, plhrms, sidehighrms, sidehighsd, plhsd);
    leftm = matchBox(leftm, plmrms, sidemidrms, sidemidsd, plmsd);
    leftl = matchBox(leftl, pllrms, sidelowrms, sidelowsd, pllsd);
    rightt = matchBox(rightt, prtrms, sidetoprms, sidetopsd, prtsd);
    righth = matchBox(righth, prhrms, sidehighrms, sidehighsd, prhsd);
    rightm = matchBox(rightm, prmrms, sidemidrms, sidemidsd, prmsd);
    rightl = matchBox(rightl, prlrms, sidelowrms, sidelowsd, prlsd);
    //std::cout<< std::to_string(sin(float_Pi/2.0*(highMidGain*(midh) + midMidGain * (midm) + lowMidGain * (midl))*midGain + (highSideGain * (lefth) + midSideGain * (leftm) + lowSideGain * (leftl))*sideGain))<<std::endl;
    resetMatch();
	
    
	output[0] = sin(float_Pi/2.0*(topMidGain * (midt) + highMidGain*(midh) + midMidGain * (midm) + lowMidGain * (midl)) * midGain + (topSideGain * (leftt) + highSideGain * (lefth) + midSideGain * (leftm) + lowSideGain * (leftl))*sideGain);
	output[1] = sin(float_Pi/2.0*(topMidGain * (midt) + highMidGain*(midh) + midMidGain * (midm) + lowMidGain * (midl)) * midGain + (topSideGain * (rightt) + highSideGain * (righth) + midSideGain * (rightm) + lowSideGain * (rightl))*sideGain);

	return output;
};
void resetMatch() {
    for (int i=0; i<8; i++){
        processlefttop[i] = 0.0;
        processlefthigh[i] = 0.0;
        processleftmid[i] = 0.0;
        processleftlow[i] = 0.0;
        processmidtop[i] = 0.0;
        processmidhigh[i] = 0.0;
        processmidmid[i] = 0.0;
        processmidlow[i] = 0.0;
        processrighttop[i] = 0.0;
        processrighthigh[i] = 0.0;
        processrightmid[i] = 0.0;
        processrightlow[i] = 0.0;
    }
        pltrms = 0.5;
        plhrms = 0.5;
        plmrms = 0.5;
        pllrms = 0.5;
        pmtrms = 0.5;
        pmhrms = 0.5;
        pmmrms = 0.5;
        pmlrms = 0.5;
        prtrms = 0.5;
        prhrms = 0.5;
        prmrms = 0.5;
        prlrms = 0.5;
        pltsd = 0.25;
        plhsd = 0.25;
        plmsd = 0.25;
        pllsd = 0.25;
        pmtsd = 0.25;
        pmhsd = 0.25;
        pmmsd = 0.25;
        pmlsd = 0.25;
        prtsd = 0.25;
        prhsd = 0.25;
        prmsd = 0.25;
        prlsd = 0.25;
        index = 0;
    }
float matchBox(float input, float originalRms, float targetRms, float sd1, float sd2) {

    if(targetRms>originalRms){
        if(input>0.0){
            return input-originalRms*sd1/sd2+targetRms;
        }
        else if(input<0.0){
            return input+originalRms*sd1/sd2-targetRms;
        }

        else{
            return input;
        }
    }
    else if(targetRms<originalRms){
        if(input>originalRms){
            return input-originalRms*sd1/sd2+targetRms;
        }
        else if(input<(-1.0)*(originalRms)){
            return input+originalRms*sd1/sd2-targetRms;
        }
        else{
            return input;
        }
    }
    else{
        return input;
    }

}

    float midGain;
    float sideGain;
    float midLMC;
    float sideLMC;
    float midMHC;
    float sideMHC;
    float midLPF;
    float sideLPF;
	float m;
	float l;
	float r;
	float midt;
	float midh;
	float midm;
	float midl;
	float leftt;
	float lefth;
	float leftm;
	float leftl;
	float rightt;
	float righth;
	float rightm;
	float rightl;
	float topMidGain;
	float topSideGain;
	float highMidGain;
	float highSideGain;
	float midMidGain;
	float midSideGain;
	float lowMidGain;
	float lowSideGain;
	float topMidRatio;
	float topSideRatio;
	float highMidRatio;
	float highSideRatio;
	float midMidRatio;
	float midSideRatio;
	float lowMidRatio;
	float lowSideRatio;
	float output[2];
	float leftlowtmp;
	float leftmidtmp;
	float lefthightmp;
	float lefttoptmp;
	float midlowtmp;
	float midmidtmp;
	float midhightmp;
	float midtoptmp;
	float rightlowtmp;
	float rightmidtmp;
	float righthightmp;
	float righttoptmp;
	float sidelowrms;
	float sidemidrms;
	float sidehighrms;
	float sidetoprms;
	float midlowrms;
	float midmidrms;
	float midhighrms;
	float midtoprms;
	float sidelowsd;
	float sidemidsd;
	float sidehighsd;
	float sidetopsd;
	float midlowsd;
	float midmidsd;
	float midhighsd;
	float midtopsd;
	float processlefttop[8];
	float processlefthigh[8];
	float processleftmid[8];
	float processleftlow[8];
	float processmidtop[8];
	float processmidhigh[8];
	float processmidmid[8];
	float processmidlow[8];
	float processrighttop[8];
	float processrighthigh[8];
	float processrightmid[8];
	float processrightlow[8];
	float pltrms;
	float plhrms;
	float plmrms;
	float pllrms;
	float pmtrms;
	float pmhrms;
	float pmmrms;
	float pmlrms;
	float prtrms;
	float prhrms;
	float prmrms;
	float prlrms;
	float pltsd;
	float plhsd;
	float plmsd;
	float pllsd;
	float pmtsd;
	float pmhsd;
	float pmmsd;
	float pmlsd;
	float prtsd;
	float prhsd;
	float prmsd;
	float prlsd;
    float maximum;
	int index;
private:
	LP24 midLP;
	LP12 leftLP;
	LP12 rightLP;

    LP12 leftLPL;
	LP12 rightLPL;
	LP12 midLPL;
    
	LP12 leftLPM1;
    LP12 leftLPM2;
    LP12 rightLPM1;
    LP12 rightLPM2;
	LP12 midLPM;
    
	LP12 leftLPH;
	LP12 rightLPH;
	LP12 midLPH;
	
	LP12 leftLPT;
	LP12 rightLPT;
	LP12 midLPT;
    
	HP12 midHP;
	HP12 leftHP;
	HP12 rightHP;
    
	HP12 leftHPM;
	HP12 rightHPM;
	HP12 midHPM;
    
	HP12 leftHPH;
	HP12 rightHPH;
	HP12 midHPH;
	
	HP12 leftHPT;
	HP12 rightHPT;
	HP12 midHPT;
	
	Gate gate1;
	Gate gate2;
    Gate gate3;
    //Gate gate4;
    //Gate gate5;
    //Gate gate6;
    //Gate gate7;
    //Gate gate8;
    //Gate gate9;
	Phaser phaser1;
	Phaser phaser2;
	Clipper clipper1;
	Clipper clipper2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FourBandEQ)
};
