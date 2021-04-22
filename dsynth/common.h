//Always use include guards
#ifndef COMMON_H
#define COMMON_H



///////////////////////////
//Globals
///////////////////////////
extern float midiLookUp[127];

///////////////////////////
//Defs
///////////////////////////


///////////////////////////
//Functions
///////////////////////////

void initLookupTable();

byte getNext(byte lastVal);

float m127(byte val);

void dbg(char * printMe);

#endif 
