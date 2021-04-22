//Always use include guards
#ifndef CLK_H
#define CLK_H

//////////////////////////
//Constants
extern const int stepsPerEpoch;

//////////////////////////
//Globals
extern unsigned long nextStep;


//////////////////////////
//Functions


void checkTime();
void ctrlBpm();
void setBpm(int b);

#endif 
