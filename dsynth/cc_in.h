//Always use include guards
#ifndef CC_IN_H
#define CC_IN_H


//CC IN Value global
extern byte kVal;

//handle cc calbacks
void ccHandler(byte ch, byte ctrl, byte val);

//set cc defualts
void setDefaults();



#endif 
