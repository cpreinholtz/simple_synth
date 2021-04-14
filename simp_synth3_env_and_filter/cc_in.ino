////////////////////////////////////////////////////////////////
//Definitions
////////////////////////////////////////////////////////////////

#include "common.h"



////////////////////////////////////////////////////////////////
//Globals
////////////////////////////////////////////////////////////////
byte kCh;
byte kVal=0x40;
byte kCtrl;
int kPage =1;

byte d1M;
byte d1O;
byte d2M;
byte d2O;
byte d3M;
byte d3O;

//how many knobs are on yer controller
const int CTRL_PER_PAGE = 16;
const int NUM_PADS = 8;


//CC ctrl per knob in order from left to right then top to bottom
int ctrlIndexed [CTRL_PER_PAGE] ={0x7, 0x4A, 0x47, 0x4C, 0x4d, 0x5D, 0x49, 0x4B, 
                        0x72, 0x12, 0x13, 0x10, 0x11, 0x5B, 0x4F, 0x48 };

                        
//CC ctrl per knob in order from left to right then top to bottom
int pageIndexed [NUM_PADS] ={0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };
////////////////////////////////////////////////////////////////
//Helpers
////////////////////////////////////////////////////////////////
float m127(byte val){
    //return map(val, 0,127, 0.0 , 1.0);
    return  (  (float) val /127.0 );
}


void noop(){}

int getHelper(){
    int i;
    for ( i= 0; i < CTRL_PER_PAGE; i++){
        if (ctrlIndexed[i] == kCtrl){break;}
    }
    return i;
}

int getPage(){
    int i;
    for ( i= 0; i < NUM_PADS; i++){
        if (pageIndexed[i] == kCtrl){break;}
    }
    return i;
}



byte getNext(byte lastVal){
    
    //abs value of differnce of kval and 0x40
    byte diff;
    byte nextVal;
    byte limit;

    Serial.println("lastVal");
    Serial.println(lastVal);

    if (kVal > 0x40){
        diff  = kVal - 0x40;
        limit = 127 - lastVal;
        
        if (limit > diff) {
            nextVal = lastVal + diff;
        } else {
            nextVal = lastVal + limit;
        }
        
    //kVal<40
    } else {
        diff  = 0x40 - kVal;
        limit = lastVal;        
        if (limit > diff) {
            nextVal = lastVal - diff;
        } else {
            nextVal = lastVal - limit;
        }
    }
    Serial.println(nextVal);
    return nextVal;
    
}


////////////////////////////////////////////////////////////////
//OSC1
////////////////////////////////////////////////////////////////

void ctrlOsc1Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer13.gain(0, m127( lastVal) );
}





void ctrlOsc1Sub0Mix(){
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    mixer1.gain(0,m127((lastVal)) );
}
void ctrlOsc1Sub1Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer1.gain(1, m127((lastVal)) );
}
void ctrlOsc1Sub2Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer1.gain(2,m127((lastVal)) );
}
void ctrlOsc1Sub3Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer1.gain(3,m127((lastVal)) );
}


void ctrlOsc1VcaAttack(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    envelope1.attack( 2000 * m127((lastVal)) );
}     
void ctrlOsc1VcaDecay(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope1.decay(  2000 * m127((lastVal)) );
}         
void ctrlOsc1VcaSustain(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope1.sustain(m127((lastVal)) );
}       
void ctrlOsc1VcaRelease(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope1.release( 2000 * m127((lastVal)));
}


void ctrlOsc1FilterCutoff(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    filterSetFreqFromVal((lastVal));
}

void ctrlOsc1FilterResonance(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    filter1.resonance(m127((lastVal)));
}

void ctrlOsc1FilterVcfAmmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    filterSetAmmountFromVal((lastVal));
}

void ctrlOsc1FilterVcfAttack   (){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope2.attack( 2000 * m127((lastVal)) );           
}
void ctrlOsc1FilterVcfDecay  (){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope2.decay(  2000 * m127((lastVal)) ); 
}
void ctrlOsc1FilterVcfSustain   (){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope2.sustain(m127((lastVal)) );
}
void ctrlOsc1FilterVcfRelease(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope2.release( 2000 * m127((lastVal)) );   
}


////////////////////////////////////////////////////////////////
//LFO1
////////////////////////////////////////////////////////////////



void ctrlOsc1LfoAmmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    sine1.amplitude(m127(lastVal));
}

void ctrlOsc1LfoFrequency(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    sine1.frequency(60 * m127(lastVal));
}

void ctrlOsc1LfoFmod1(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp1.gain(m127(lastVal));
}

void ctrlOsc1LfoFmod2(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp2.gain(m127(lastVal));
}
void ctrlOsc1LfoFmod3(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp3.gain(m127(lastVal));
}

void ctrlOsc1LfoSmod2(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp4.gain(m127(lastVal));
}
void ctrlOsc1LfoSmod3(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp5.gain(m127(lastVal));
}                    
void ctrlOsc1LfoVcfmod(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    mixer3.gain(1,m127(lastVal) );
}       


            
////////////////////////////////////////////////////////////////
//Osc2
////////////////////////////////////////////////////////////////

void ctrlOsc2Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer13.gain(1, m127( lastVal) );
}


void ctrlOsc2Detune(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    kDetune = lastVal;  
    setAllOsc2Freq(getFreqFromDetune());
}




void ctrlOsc2Sub0Mix(){
    static byte lastVal =127; 
    lastVal = getNext(lastVal);  
    mixer11.gain(0,m127((lastVal)) );
}
void ctrlOsc2Sub1Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer11.gain(1, m127((lastVal)) );
}
void ctrlOsc2Sub2Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer11.gain(2,m127((lastVal)) );
}
void ctrlOsc2Sub3Mix(){
    static byte lastVal =127;
    lastVal = getNext(lastVal);
    mixer11.gain(3,m127((lastVal)) );
}


void ctrlOsc2VcaAttack(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    envelope3.attack( 2000 * m127((lastVal)) );
}     
void ctrlOsc2VcaDecay(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope3.decay(  2000 * m127((lastVal)) );
}         
void ctrlOsc2VcaSustain(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope3.sustain(m127((lastVal)) );
}       
void ctrlOsc2VcaRelease(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope3.release( 2000 * m127((lastVal)));
}


void ctrlOsc2FilterCutoff(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    filter2SetFreqFromVal((lastVal));
}

void ctrlOsc2FilterResonance(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    filter2.resonance(m127((lastVal)));
}

void ctrlOsc2FilterVcfAmmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    filter2SetAmmountFromVal((lastVal));
}

void ctrlOsc2FilterVcfAttack   (){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope4.attack( 2000 * m127((lastVal)) );           
}
void ctrlOsc2FilterVcfDecay  (){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope4.decay(  2000 * m127((lastVal)) ); 
}
void ctrlOsc2FilterVcfSustain   (){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope4.sustain(m127((lastVal)) );
}
void ctrlOsc2FilterVcfRelease(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelope4.release( 2000 * m127((lastVal)) );   
}

////////////////////////////////////////////////////////////////
//LFO2
////////////////////////////////////////////////////////////////



void ctrlOsc2LfoAmmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    sine2.amplitude(m127(lastVal));
}

void ctrlOsc2LfoFrequency(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    sine2.frequency(60 * m127(lastVal));
}

void ctrlOsc2LfoFmod1(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp6.gain(m127(lastVal));
}

void ctrlOsc2LfoFmod2(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp7.gain(m127(lastVal));
}
void ctrlOsc2LfoFmod3(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp8.gain(m127(lastVal));
}

void ctrlOsc2LfoSmod2(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp9.gain(m127(lastVal));
}

void ctrlOsc2LfoVcfmod(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    mixer3.gain(1,m127(lastVal) );
}       



///////////////////////////////////////////////
//EFFECTS DRY
///////////////////////////////////////////////
void ctrlFxDryAmmount(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    amp13.gain(m127(lastVal));
}    

void ctrlFxDryPan(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    mixer2.gain(0,1.0- m127(lastVal));
    mixer4.gain(0, m127(lastVal));
}    

///////////////////////////////////////////////
//EFFECTS Rvb
///////////////////////////////////////////////

void ctrlFxReverbAmmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp11.gain( m127(lastVal));
    amp12.gain(m127(lastVal));
}    

void ctrlFxReverbPan(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    mixer2.gain(1,1.0- m127(lastVal));
    mixer4.gain(1, m127(lastVal));
}    

void ctrlFxReverbSize(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    freeverbs1.roomsize( m127(lastVal));
}    

void ctrlFxReverbDamping(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    freeverbs1.damping( m127(lastVal));
}    






///////////////////////////////////////////////
//EFFECTS BC
///////////////////////////////////////////////

void ctrlFxBcAmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp10.gain(m127(lastVal));
}  
    
void ctrlFxBcPan(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    mixer2.gain(2,1.0- m127(lastVal));
    mixer4.gain(2, m127(lastVal));
}  

void ctrlFxBcRate(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    bitcrusher1.sampleRate((int) (44000* m127(lastVal) ) );
}    

void ctrlFxBcBits(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    bitcrusher1.bits( (int)( 16*(1.0- m127(lastVal) ) )  );
}    

///////////////////////////////////////////////
//EFFECTS Delay
///////////////////////////////////////////////
void ctrlFxDelayAmount(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    amp14.gain(m127(lastVal));
}  
    
void ctrlFxDelayPan(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    mixer2.gain(3,1.0- m127(lastVal));
    mixer4.gain(3, m127(lastVal));
}  

void ctrlFxDelayFeedback(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    mixer5.gain(3, 0.9* m127(lastVal));
}  

void ctrlFxDelaySpeed(){
    static byte lastVal =63;
    lastVal = getNext(lastVal);
    delay1.delay(0, 1000.0* (1.01 - m127(lastVal) ) );
}  



///////////////////////////////////////////////
//Drum
///////////////////////////////////////////////
void ctrlDrum1Amplitude(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    ampDrum1.gain( m127(lastVal) );
}  
void ctrlDrum1Frequency(){
    static byte lastVal =20;
    lastVal = getNext(lastVal);
    drum1.frequency( midiLookUp[lastVal]);
    
}
void ctrlDrum1Mod(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d1M = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal))); 

    Serial.println("d1M");     
    Serial.println(d1M);     
}

void ctrlDrum1Offset(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d1O = (byte) ( (float)stepsPerEpoch*m127(lastVal));  
    Serial.println("d1O");     
    Serial.println(d1O);  
}


void ctrlDrum2Amplitude(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    ampDrum2.gain( m127(lastVal) );
    noise1.amplitude(m127(lastVal));
}  
void ctrlDrum2Frequency(){
    static byte lastVal =20;
    lastVal = getNext(lastVal);
    drum2.frequency( midiLookUp[lastVal]);
    
}
void ctrlDrum2Mod(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d2M = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal)));        
}

void ctrlDrum2Offset(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d2O = (byte) ( (float)stepsPerEpoch*m127(lastVal));    
}



void ctrlDrum3Amplitude(){
    static byte lastVal =0;
    lastVal = getNext(lastVal);
    noise2.amplitude(m127(lastVal));
}  

void ctrlDrum3Length(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    envelopeD3.attack(10*m127(lastVal) );
    envelopeD3.decay(100*m127(lastVal) );
}



void ctrlDrum3Mod(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d3M = 1+ (byte) ( (float)stepsPerEpoch*(1.0-m127(lastVal)));       
}

void ctrlDrum3Offset(){
    static byte lastVal =10;
    lastVal = getNext(lastVal);
    d3O = (byte) ( (float)stepsPerEpoch*m127(lastVal));    
}

void ctrlBpm(){
    static byte lastVal =40;
    lastVal = getNext(lastVal);
    setBpm(( (int)lastVal+1 )*2 );
}

////////////////////////////////////////////////////////////////
//Pages
////////////////////////////////////////////////////////////////

//tCcHandlerList is a list of pointers to functions with no args and that return void
typedef void (*tCcHandlerList[CTRL_PER_PAGE]) ();


#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))


//Handlers per knob in order from left to right then top to bottom
tCcHandlerList handleMePlease [] = {
    {
        ctrlOsc1Sub0Mix,            ctrlOsc1Sub1Mix,            ctrlOsc1Sub2Mix,                ctrlOsc1Sub3Mix, 
        ctrlOsc1VcaAttack,          ctrlOsc1VcaDecay,           ctrlOsc1VcaSustain,             ctrlOsc1VcaRelease,
        ctrlOsc1Mix,                ctrlOsc1FilterCutoff,       ctrlOsc1FilterResonance,        ctrlOsc1FilterVcfAmmount,
        ctrlOsc1FilterVcfAttack,    ctrlOsc1FilterVcfDecay,     ctrlOsc1FilterVcfSustain,       ctrlOsc1FilterVcfRelease
    },
    {
        ctrlOsc2Sub0Mix,            ctrlOsc2Sub1Mix,            ctrlOsc2Sub2Mix,                ctrlOsc2Sub3Mix, 
        ctrlOsc2VcaAttack,          ctrlOsc2VcaDecay,           ctrlOsc2VcaSustain,             ctrlOsc2VcaRelease,
        ctrlOsc2Detune,             ctrlOsc2FilterCutoff,       ctrlOsc2FilterResonance,        ctrlOsc2FilterVcfAmmount,
        ctrlOsc2FilterVcfAttack,    ctrlOsc2FilterVcfDecay,     ctrlOsc2FilterVcfSustain,       ctrlOsc2FilterVcfRelease
    }, //ctrlOsc2Mix unused!
    
    {
        ctrlOsc1LfoAmmount,         ctrlOsc1LfoFrequency,       ctrlOsc1LfoSmod2,               ctrlOsc1LfoSmod3,
        ctrlOsc1LfoFmod1,           ctrlOsc1LfoFmod2,           ctrlOsc1LfoFmod3,               ctrlOsc1LfoVcfmod,
        ctrlOsc2LfoAmmount,         ctrlOsc2LfoFrequency,       ctrlOsc2LfoSmod2,               noop,
        ctrlOsc2LfoFmod1,           ctrlOsc2LfoFmod2,           ctrlOsc2LfoFmod3,               ctrlOsc2LfoVcfmod,
    },
    {
        ctrlFxDryAmmount,           ctrlFxDryPan,               ctrlOsc1LfoAmmount,             ctrlOsc2LfoAmmount,
        ctrlFxReverbAmmount,        ctrlFxReverbPan,            ctrlFxReverbDamping,            ctrlFxReverbSize,
        ctrlFxBcAmount,             ctrlFxBcPan,                ctrlFxBcRate,                   ctrlFxBcBits,
        ctrlFxDelayAmount,          ctrlFxDelayPan,             ctrlFxDelayFeedback,            ctrlFxDelaySpeed
    },
    {
        ctrlDrum1Amplitude,         ctrlDrum1Frequency,         ctrlDrum1Mod,                   ctrlDrum1Offset,
        ctrlDrum2Amplitude,         ctrlDrum2Frequency,         ctrlDrum2Mod,                   ctrlDrum2Offset,
        ctrlDrum3Amplitude,         ctrlDrum3Length,            ctrlDrum3Mod,                   ctrlDrum3Offset,
        ctrlBpm,                    noop,                       noop,                           noop
    }

};






void ccHandler(byte ch, byte ctrl, byte val){

    if (val == 0x40) {return;}    
    Serial.println(" cc");
    
    kCh = ch;    
    kCtrl = ctrl;
    kVal = val;


    int ctrlKnob = getHelper();
    if( ctrlKnob >=0 and ctrlKnob < CTRL_PER_PAGE ){
        Serial.println("ctrlKnob");
        Serial.println(ctrlKnob);
        //use the current page, and the ctrl Knob CC to call the correct handler
        handleMePlease[kPage][ctrlKnob]();           
    } else {
        int page = getPage();
        if( page >=0 and page < NUM_PADS and page < ARRAY_SIZE(handleMePlease) ){
            Serial.println("page");
            Serial.println(page);
            //switch the current page
            kPage = page;            
        } else {
            Serial.println("unrecognised cc");        
            Serial.println(kCtrl);
        }
    }    
}




void setDefaults(){
    kVal = 0x40;
    for (byte page = 0; page < ARRAY_SIZE(handleMePlease); page ++){
        for (int ctrlKnob = 0; ctrlKnob < CTRL_PER_PAGE; ctrlKnob++){
            handleMePlease[page][ctrlKnob]();
        }
    }

    

    //this stuff never changes, is not part of any page


    mixerFinalL.gain(1, 1.0 );
    mixerFinalR.gain(1, 1.0 );

    mixerFinalL.gain(2, 1.0 );
    mixerFinalR.gain(2, 1.0 );
    
    mixerFinalL.gain(3, 1.0 );
    mixerFinalR.gain(3, 1.0 );


    //filter env (controlled by DC)
    mixer12.gain(0, 1.0);
    //filter env (controlled by DC)
    mixer3.gain(0, 1.0);

    //bank osc mix  //ctrlOsc2Mix(); ctrlOsc1Mix();
    mixer13.gain(0, 1.0);    mixer13.gain(1, 1.0);     mixer13.gain(2, 0.0);     mixer13.gain(3, 0.0);

    envelopeD3.sustain(0.0);
    envelopeD3.delay(0.0);
    envelopeD3.hold(0.0);

    combine1.setCombineMode(AudioEffectDigitalCombine::AND);
    drum1.length(100);
    drum2.length(75);
    
}
