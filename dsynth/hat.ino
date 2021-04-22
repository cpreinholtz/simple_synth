
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
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    filterHatLp.frequency(100000*m127((lastVal)) );
    dbg("hat lp cut"); 
}

void ctrlHatLpEnvAmnt(){
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    dcHatVcf.amplitude(m127((lastVal)) );
    dbg("hat env amnt"); 
}

void ctrlHatLpEnvDecay(){
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    envelopeHatVcf.decay(1000* m127((lastVal)) );
    dbg("hat lp env decay"); 
}


void ctrlHatHpCut(){
    static byte lastVal =0; 
    lastVal = getNext(lastVal);  
    filterHatHp.frequency(100000*m127((lastVal)) );
    dbg("hat hp cut"); 
}



void ctrlHatDecay(){
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    envelopeHatAmp.decay(1000* m127((lastVal)) );
    dbg("hat decay"); 
}


/////////////////////////////////////////////////////////
//Sequence
/////////////////////////////////////////////////////////
byte hatMod=4;
bool hatPoly=false;
byte hatFirstStep=0;
byte hatLastStep=16;
byte hatNumStep=16; 
byte hatOffset=16;


void ctrlHatMod(){
    static byte lastVal =82;
    lastVal = getNext(lastVal);
    hatMod = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal))); 
    dbg("hat mod"); 
   
}

void ctrlHatPoly(){
    static byte lastVal =82;
    lastVal = getNext(lastVal);
    if (lastVal>=64){
        hatPoly = true;
    } else {
        hatPoly = false;
    }  
    dbg("hat poly"); 
}

void ctrlHatFirstStep(){
    static byte lastVal =32;
    lastVal = getNext(lastVal);
    hatFirstStep = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat first"); 

}

void ctrlHatLastStep(){
    static byte lastVal =32;
    lastVal = getNext(lastVal);
    hatLastStep = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat last"); 
}

void ctrlHatNumStep(){
    static byte lastVal =32;
    lastVal = getNext(lastVal);
    hatNumStep = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat nstep"); 
}


void ctrlHatOffset(){
    static byte lastVal =32;
    lastVal = getNext(lastVal);
    hatOffset = stepsPerEpoch - (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    dbg("hat offset");  
}



/////////////////////////////////////////////////////////
//Sequence
/////////////////////////////////////////////////////////




void hatActiveStep(){
    if (hatPoly ==true){
        if ( (nextStep + (unsigned long)hatOffset) % (unsigned long)hatMod  ==0) {
            envelopeHatAmp.noteOn();  
            envelopeHatVcf.noteOn();  
            dbg("hat poly note on");         
        }
    } else { 
        unsigned long epochStep = (nextStep +hatOffset ) % hatNumStep;
        if (epochStep >= hatFirstStep and epochStep < hatLastStep and epochStep % hatMod ==0){
            envelopeHatAmp.noteOn();  
            envelopeHatVcf.noteOn(); 
            dbg("hat repeat note on");
        }
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
