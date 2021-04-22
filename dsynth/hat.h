//Always use include guards
#ifndef HAT_H
#define HAT_H


//////////////////////////
//Globals
//extern byte hatMod1;
//extern byte hatOff1;
//extern bool hatPoly1;

//////////////////////////
//Functions
void ctrlHatMod();
void ctrlHatPoly();
void ctrlHatFirstStep();
void ctrlHatLastStep();
void ctrlHatNumStep();
void ctrlHatOffset();

void ctrlHatRes();
void ctrlHatLpCut();
void ctrlHatLpEnvAmnt();
void ctrlHatLpEnvDecay();

void ctrlHatHpCut();

void ctrlHatDecay();
void setHatDefaults();

#endif
