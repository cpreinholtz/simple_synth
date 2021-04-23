#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>

#include "clk.h"

// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

#define NUM_LEDS_PER_STRIP 16
#define NUM_STRIPS 8
#define NUM_LEDS (NUM_LEDS_PER_STRIP * NUM_STRIPS)

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];


void setupOcto(){
    
    //delay( 300 ); // power-up safety delay
    LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
    LEDS.setBrightness(5);
    FastLED.setDither( 0 );
    randomSeed(analogRead(0)); 
    clearAll();
    setNum();
    show();
}




////////////////////////////////////////////////////
//
//sets all led values to 0, does not effect pix objects stored memory
void clearAll(){
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(0,0,0);      
    }
}


///////////////////////////////////////////////////////
//Utility  
// Set the first n leds on each strip to show which strip it is
void setNum(){    
    int sec=3;
    for(int i = 0; i < NUM_STRIPS; i++) {
        for(int j = 0; j <= i; j++) {
            leds[(i*NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
        }
    }
}

void show(){
    //leds;  
    //if (millis()-startMillis<10000) setNum();
    LEDS.show();
}




///////////////////////////////////////////////////////
//Utility  
// Set the first n leds on each strip to show which strip it is

bool willFire [stepsPerEpoch]; //White? (add green)
bool window [stepsPerEpoch];  //Blue
bool inNumSteps [stepsPerEpoch];  //black outside, red inside


void setStep(int strip, bool * willFire, bool * window, bool *inNumSteps, int isNow = -1 ){    
    int sec=3;
    for(int j = 0; j < stepsPerEpoch ; j++) {
        if (j==isNow) { leds[(strip*NUM_LEDS_PER_STRIP) + j] = CRGB::Yellow; } 
        else if (willFire[j])  { leds[(strip*NUM_LEDS_PER_STRIP) + j] = CRGB::White; }
        else if (window[j])  { leds[(strip*NUM_LEDS_PER_STRIP) + j] = CRGB::Purple; }
        else if (inNumSteps[j])  { leds[(strip*NUM_LEDS_PER_STRIP) + j] = CRGB::Red; }
        else { leds[(strip*NUM_LEDS_PER_STRIP) + j] = CRGB::Black; }
    }
}
