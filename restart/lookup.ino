#include "util.h"


//lookup table
float midiLookUp[128];


void initLookupTable(){
    float a = 440; // a is 440 hz...
    for (unsigned int x = 0; x < ARRAY_SIZE(midiLookUp); ++x)
    {
        midiLookUp[x] = (a / 32.0) * ( pow(2,(((float)x - 9.0) / 12.0)) )  ;
#ifdef DEBUG_ENABLE
            Serial.println("setting note to ");
            Serial.println(x);
            Serial.println(midiLookUp[x]);
#endif           
        
    }
}



/*

float getFreqFromDetune(){
    return map(kDetune, 0, 127, lastMasterFrequency/2, lastMasterFrequency);
}

*/
