
#include "common.h"
#include "clk.h"


/////////////////////////////////////////////////////////
//Modulation
/////////////////////////////////////////////////////////

void ctrlHatRes(){
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    filterHatLp.resonance(0.7+ 4*m127((lastVal)) );
    dbg("hat res"); 
}

void ctrlHatLpCut(){
    static byte lastVal =10; 
    lastVal = getNext(lastVal);  
    filterHatLp.frequency(100000*m127((lastVal)) );
    dbg("hat lp cut"); 
}

void ctrlHatLpEnvAmnt(){
    static byte lastVal =50; 
    lastVal = getNext(lastVal);  
    dcHatVcf.amplitude(m127((lastVal)) );
    dbg("hat env amnt"); 
}

void ctrlHatLpEnvDecay(){
    static byte lastVal =6; 
    lastVal = getNext(lastVal);  
    envelopeHatVcf.decay(1000* m127((lastVal)) );
    dbg("hat lp env decay"); 
}


void ctrlHatHpCut(){
    static byte lastVal =5; 
    lastVal = getNext(lastVal);  
    filterHatHp.frequency(100000*m127((lastVal)) );
    dbg("hat hp cut"); 
}



void ctrlHatDecay(){
    static byte lastVal =50; 
    lastVal = getNext(lastVal);  
    envelopeHatAmp.decay(1000* m127((lastVal)) );
    dbg("hat decay"); 
}


void ctrlHatVolume(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    noiseHat.amplitude(m127(lastVal)); 
    dbg("hat vol"); 
}

/////////////////////////////////////////////////////////
//Sequence
/////////////////////////////////////////////////////////

//fires every N steps
byte hatMod=4;

//controls poly(mod is absolute%mod) vs repeat (mod is based on the absolute%numSteps % mod)
//bool hatPoly=false;

//fire only if absolute%numSteps >= first
byte hatFirstStep=0;

//fire only if absolute%numSteps < last
byte hatLastStep=16;

//unused in poly
byte hatNumStep=16; 

//gets subtracted from absolute
byte hatOffset=0;


unsigned long gEpochStep = 0;




void ctrlHatMod(){
    static byte lastVal =90;
    lastVal = getNext(lastVal);
    hatMod = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal))); 
    dbg("hat mod"); 
    dbg(hatMod);
    checkActiveStepsRepeat();
}



void ctrlHatFirstStep(){
    static byte lastVal =20;
    lastVal = getNext(lastVal);
    hatFirstStep = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat first"); 
    dbg(hatFirstStep);
    checkActiveStepsRepeat();
}

void ctrlHatLastStep(){
    static byte lastVal =100;
    lastVal = getNext(lastVal);
    hatLastStep = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat last"); 
    dbg(hatLastStep);
    checkActiveStepsRepeat();
}

void ctrlHatNumStep(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    hatNumStep = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat nun step"); 
    dbg(hatNumStep);
    checkActiveStepsRepeat();
}


void ctrlHatOffset(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    hatOffset = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat offset");
    dbg(hatOffset);
    checkActiveStepsRepeat();
}



/////////////////////////////////////////////////////////
//Sequence
/////////////////////////////////////////////////////////
bool gWillFire [stepsPerEpoch]; //White? (add green)
bool gWindow [stepsPerEpoch];  //Blue
bool gInNumSteps [stepsPerEpoch];  //black outside, red inside


void checkActiveStepsRepeat(){

    //dummy check offset
    int tempOffset;
    if (hatOffset >= hatMod) {tempOffset = hatMod -1;}
    else {tempOffset = hatOffset;} 


    for ( int epochStep = 0; epochStep< stepsPerEpoch; epochStep++){    



        //in order to fire, a step must be less than num steps
        if (epochStep < hatNumStep){ 
            gInNumSteps[epochStep] = true;

            
            //And inside the gWindow
            if ( epochStep>=hatFirstStep and epochStep < hatLastStep){ 
                gWindow[epochStep] = true;

                //and epoch % modval ==offset to fire
                if (  epochStep % hatMod ==tempOffset){ gWillFire[epochStep] = true;}
                else { gWillFire[epochStep] = false; } 
                 
            } else { //not in gWindow
                gWindow[epochStep] = false; 
                gWillFire[epochStep] =false;
            }
            
        } else { //not in num steps
            gInNumSteps[epochStep] = false;
            gWindow[epochStep] = false; 
            gWillFire[epochStep] =false;
        }        
    }    

    gEpochStep = (nextStep ) % hatNumStep;

    //setStep(int strip, bool * gWillFire, bool * gWindow, bool *gInNumSteps  )
    setStep(4, gWillFire, gWindow, gInNumSteps, gEpochStep );

    
}





void hatActiveStep(){

    
    //dummy check offset
    int tempOffset;
    if (hatOffset >= hatMod) {tempOffset = hatMod -1;}
    else {tempOffset = hatOffset;} 


        
    gEpochStep = (nextStep ) % hatNumStep;
    //setStep(int strip, bool * gWillFire, bool * gWindow, bool *gInNumSteps  )
    setStep(4, gWillFire, gWindow, gInNumSteps, gEpochStep );
    
    if (gEpochStep >= hatFirstStep and gEpochStep < hatLastStep and gEpochStep % hatMod ==tempOffset){
        envelopeHatAmp.noteOn();  
        envelopeHatVcf.noteOn(); 
        dbg("hat repeat note on");



        dbg(nextStep);
        dbg(hatOffset);
        dbg(gEpochStep);
        dbg(hatMod);
        dbg(hatFirstStep);
        dbg(hatLastStep);
    } 
}


/////////////////////////////////////////////////////////
//Defaults
/////////////////////////////////////////////////////////
void setHatDefaults(){
    envelopeHatAmp.delay(0.0);   
    envelopeHatAmp.attack(1.0);
    envelopeHatAmp.hold(0.0);
    envelopeHatAmp.sustain(0.0);
    envelopeHatAmp.decay(100.0);    
    envelopeHatAmp.release(0.0);

    filterHatHp.resonance(0.7 );
    filterHatLp.octaveControl(2.0);


    envelopeHatVcf.delay(0.0);   
    envelopeHatVcf.attack(1.0);
    envelopeHatVcf.hold(0.0);
    envelopeHatVcf.sustain(0.0);
    envelopeHatVcf.decay(10.0);    
    envelopeHatVcf.release(0.0);

    noiseHat.amplitude(1.0);
    dbg("setHatDefaults");
}
