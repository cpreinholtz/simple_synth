#include <ADC.h>
#include <ADC_util.h>

#include "timer.h"

///////////////////////////////////
//global
///////////////////////////////////
ADC *adc = new ADC(); // adc object;

Timer knobTimer(50);


float lastVals [ARRAY_SIZE(myKnobs)];

///////////////////////////////////
//constants
///////////////////////////////////
//pins
const int s8a = 0;
const int s8b = 1;
const int s8c = 2;
const int s64a = 3;
const int s64b = 4;
const int s64c = 5;
const int kIn = A1;

int gThisPin=0;
int gThisChip=0;

//
const unsigned long kPollingPeriodMicros = 50;//1000000;  //50 uS nominal

///////////////////////////////////
//functions
///////////////////////////////////
//init
void initKnobPoller(){
    pinMode(s8a, OUTPUT);
    pinMode(s8b, OUTPUT);
    pinMode(s8c, OUTPUT);
    pinMode(s64a, OUTPUT);
    pinMode(s64b, OUTPUT);
    pinMode(s64c, OUTPUT);

    pinMode(kIn, INPUT);
    
    adc->adc0->setReference(ADC_REFERENCE::REF_3V3);    
    adc->adc0->setAveraging(16); // set number of averages
    adc->adc0->setResolution(16); // set bits of resolution
    adc->adc0->setConversionSpeed(ADC_CONVERSION_SPEED::MED_SPEED); // change the conversion speed
    adc->adc0->setSamplingSpeed(ADC_SAMPLING_SPEED::MED_SPEED); // change the sampling speed


    knobTimer.setPeriodMicros(kPollingPeriodMicros);
    dbg("init knobs");
    for (int i =0; i<  ARRAY_SIZE(myKnobs); i++ ){
        setChipAndPin(i);
        setSelect(gThisChip,gThisPin);
        while (1){
            if (knobTimer.pollAndReset()) {
                break;
            }
        }

        lastVals[i] = adcToFloat(adc->adc0->analogRead(kIn));

        dbg("init knobs");
        dbg(gThisChip);
        dbg(gThisPin);   
        dbg(lastVals[i]); 
    }
    
    setChipAndPin(0);
    setSelect(gThisChip,gThisPin); //gThisPin = 0; //gThisChip = 0;
    
    
}






///////////////////////////////////
//if ready, read ADC value, perform knob operation, update select lines and reset timer
void serviceKnobPoller(){
    if (knobTimer.pollAndReset()){
        int thisIndex = getIndex( gThisChip, gThisPin);

        //TODO grab ADC val here
        //gVal = 0.45;
        gVal = adcToFloat(adc->adc0->analogRead(kIn));
        if (abs(gVal- lastVals[thisIndex]) > 0.05) {
            //perform handler operation
            myKnobs[thisIndex]();
            lastVals[thisIndex] = gVal;
        }



        //update index
        setChipAndPin( (thisIndex+1) % ARRAY_SIZE(myKnobs) );


        //set the select and restart timer
        setSelect(gThisChip,gThisPin);
    }
}



///////////////////////////////////
//UTILS
///////////////////////////////////

//set mux select lines
void setSelect(int chip, int pin){
    if (chip >7 or chip <0 or pin >7 or pin <0) {
        return;
    } else {
        digitalWrite(s8a, chip && 0x1 != 0);
        digitalWrite(s8b, chip && 0x2 != 0);
        digitalWrite(s8c, chip && 0x4 != 0);
        
        digitalWrite(s64a, pin && 0x1 != 0);
        digitalWrite(s64b, pin && 0x2 != 0);
        digitalWrite(s64c, pin && 0x4 != 0);

        //dont remove or I will break
        knobTimer.startTick();
    }
}



//knob index from chip, pin
int getIndex(int chip, int pin){
    return 8*chip + pin;
}

//chip, pin from knobIndex
int setChipAndPin(int thisIndex){
    gThisChip = thisIndex / 8;
    gThisPin = thisIndex % 8;
}

///////////////////////////////////
//accepts full scale ADC integer
//returns a float from 0.0 to 1.0
float adcToFloat(int readVal){
    float convertedVal = ((float)readVal /(float)adc->adc0->getMaxValue());    
    dbg(convertedVal);
    return convertedVal;
}
