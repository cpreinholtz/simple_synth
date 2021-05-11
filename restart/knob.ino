#include "util.h"

float gVal;

void setNoise(){
    dbg("noise");
    dbg(gVal);
    pinkVoice1.amplitude(gVal);
}



void setOsc1Shape(){
    dbg("Osc1Shape");
    dbg(gVal);
    dcOsc1Shape.amplitude(gVal);
}

void setOsc2Shape(){
    dbg("Osc2Shape");
    dbg(gVal);
    dcOsc2Shape.amplitude(gVal);
}



tHandlerList myKnobs = {
    setNoise, setOsc1Shape, setOsc2Shape
};
