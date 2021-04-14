//Always use include guards
#ifndef COMMON_H
#define COMMON_H


void setBpm(int b);


extern const int stepsPerEpoch;



//lookup table
extern float midiLookUp[127];

extern byte d1M;
extern byte d1O;
extern byte d2M;
extern byte d2O;
extern byte d3M;
extern byte d3O;


#endif 
