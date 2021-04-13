////////////////////////////////////////////////////////////////
//Definitions
////////////////////////////////////////////////////////////////








////////////////////////////////////////////////////////////////
//Globals
////////////////////////////////////////////////////////////////
byte kCh;
byte kVal=0x40;
byte kCtrl;
int kPage =1;

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
    mixer3.gain(0, m127( lastVal) );
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
        ctrlOsc1LfoAmmount, ctrlOsc1LfoFrequency,  ctrlOsc1LfoSmod2, ctrlOsc1LfoSmod3,
        ctrlOsc1LfoFmod1, ctrlOsc1LfoFmod2, ctrlOsc1LfoFmod3,  ctrlOsc1LfoVcfmod,
        noop, noop, noop, noop,
        noop, noop, noop, noop
    }

};

//ctrlOsc1LfoAmmount, ctrlOsc1LfoFrequency,  ctrlOsc1LfoSmod2, ctrlOsc1LfoSmod3,
//ctrlOsc1LfoFmod1, ctrlOsc1LfoFmod2, ctrlOsc1LfoFmod3,  ctrlOsc1LfoVcfmod


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
}










/*

////////////////////////////////////////////////////////////////
// OSC 2
////////////////////////////////////////////////////////////////
void ctrlOsc2Mix(byte ch, byte ctrl, byte kVal){
    mixer3.gain(1,((float)kVal)/127.0 );
}


void ctrlOsc2SubMix(byte ch, byte ctrl, byte kVal, int wave){
    mixer11.gain(wave,((float)kVal)/127.0 );
}

void ctrlOsc2Detune(byte ch, byte ctrl, byte kVal){
    kDetune = kVal;  
    setAllOsc2Freq(getFreqFromDetune());
}



            
            
///////////////////////////////////////////////
//VCA
///////////////////////////////////////////////
        case CTRL_VCA_A:
            envelope1.attack( 2000 * ((float)kVal)/127.0 );
            break;      
        case CTRL_VCA_D:
            envelope1.decay(  2000 * ((float)kVal)/127.0 );
            break;      
        case CTRL_VCA_S:
            envelope1.sustain(((float)kVal)/127.0 );
            break;      
        case CTRL_VCA_R:
            envelope1.release( 2000 * ((float)kVal)/127.0 );
            break;

///////////////////////////////////////////////
//VCA 2
///////////////////////////////////////////////
        case CTRL_2VCA_A:
            envelope3.attack( 2000 * ((float)kVal)/127.0 );
            break;      
        case CTRL_2VCA_D:
            envelope3.decay(  2000 * ((float)kVal)/127.0 );
            break;      
        case CTRL_2VCA_S:
            envelope3.sustain(((float)kVal)/127.0 );
            break;      
        case CTRL_2VCA_R:
            envelope3.release( 2000 * ((float)kVal)/127.0 );
            break;


///////////////////////////////////////////////
//FILTER 2
///////////////////////////////////////////////
        case CTRL_2FILT_CUTOFF:
            filter2SetFreqFromVal(kVal);
            break;
        case CTRL_2VCF_AMNT:
            filter2SetAmmountFromVal(kVal);
            break;     
        case CTRL_2VCF_A:
            envelope2.attack( 2000 * ((float)kVal)/127.0 );
            break;      
        case CTRL_2VCF_D:
            envelope2.decay(  2000 * ((float)kVal)/127.0 );
            break;      
        case CTRL_2VCF_S:
            envelope2.sustain(((float)kVal)/127.0 );
            break;      
        case CTRL_2VCF_R:
            envelope2.release( 2000 * ((float)kVal)/127.0 );
            break;

///////////////////////////////////////////////
//EFFECTS DRY
///////////////////////////////////////////////
        case CTRL_FX_DRY_MIX_L:
            mixer2.gain(0, (float)kVal/127.0);
            break;
        case CTRL_FX_DRY_MIX_R:
            mixer4.gain(0, (float)kVal/127.0);
            break;


///////////////////////////////////////////////
//EFFECTS REVERB
///////////////////////////////////////////////
        case CTRL_FX_REVERB_SIZE:
            freeverbs1.roomsize((float)kVal/127.0);
            break;
        case CTRL_FX_REVERB_DAMP:
            freeverbs1.damping((float)kVal/127.0);
            break;            
        case CTRL_FX_REVERB_MIX_L:
            mixer2.gain(1, (float)kVal/127.0);
            break;
        case CTRL_FX_REVERB_MIX_R:
            mixer4.gain(1,(float)kVal/127.0);
            break;
            



///////////////////////////////////////////////
//EFFECTS BC
///////////////////////////////////////////////
   
        case CTRL_FX_BC_MIX_L:
            mixer2.gain(2, (float)kVal/127.0);
            break;
        case CTRL_FX_BC_MIX_R:
            mixer4.gain(2, (float)kVal/127.0);
            break;     
        case CTRL_FX_BC_BITS:
            bitcrusher1.bits( (int)(16*(float)kVal/127.0));
            break;
        case CTRL_FX_BC_RATE:
            bitcrusher1.sampleRate( (int)(44000*(float)kVal/127.0) );
            break;

///////////////////////////////////////////////
//EFFECTS Delay
///////////////////////////////////////////////
            

        case CTRL_FX_DLYMIX_L:
            mixer2.gain(3, (float)kVal/127.0);
            break;
        case CTRL_FX_DLYMIX_R:
            mixer4.gain(3, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY1_S:
            delay1.delay(0, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY1_L:
            mixer5.gain(0, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY1_R:
            mixer7.gain(0, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY2_S:
            delay1.delay(1, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY2_L:
            mixer5.gain(1, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY2_R:
            mixer7.gain(1, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY3_S:
            delay1.delay(2, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY3_L:
            mixer5.gain(2, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY3_R:
            mixer7.gain(2, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY4_S:
            delay1.delay(3, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY4_L:
            mixer5.gain(3, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY4_R:
            mixer7.gain(3, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY5_S:
            delay1.delay(4, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY5_L:
            mixer6.gain(0, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY5_R:
            mixer8.gain(0, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY6_S:
            delay1.delay(5, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY6_L:
            mixer6.gain(1, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY6_R:
            mixer8.gain(1, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY7_S:
            delay1.delay(6, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY7_L:
            mixer6.gain(2, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY7_R:
            mixer8.gain(2, (float)kVal/127.0);
            break;

        case CTRL_FX_DLY8_S:
            delay1.delay(7, DELAY_SCALE* (float)kVal/127.0);
            break;
        case CTRL_FX_DLY8_L:
            mixer6.gain(3, (float)kVal/127.0);
            break;
        case CTRL_FX_DLY8_R:
            mixer8.gain(3, (float)kVal/127.0);
            break;



///////////////////////////////////////////////
//LFO 2
///////////////////////////////////////////////
        case CTRL_2LFO_A:
            sine2.amplitude(((float)kVal)/127.0);
            break;
        case CTRL_2LFO_F:
            sine2.frequency(60 * ((float)kVal)/127.0);
            break;     
                        
        case CTRL_2LFO_FMOD1:
            amp6.gain(((float)kVal)/127.0 );
            break;  
        case CTRL_2LFO_FMOD2:
            amp7.gain(((float)kVal)/127.0 );
            break;    
        case CTRL_2LFO_FMOD3:
            amp8.gain(((float)kVal)/127.0 );
            break;    
            
        case CTRL_2LFO_SMOD2:
            amp9.gain(((float)kVal)/127.0 );
            break;    
                  
        case CTRL_2LFO_VCFMOD:
            mixer12.gain(1,((float)kVal)/127.0 );
            break; 
///////////////////////////////////////////////
//DEFAULT
///////////////////////////////////////////////
        default:
#ifdef DEBUG_ENABLE
            Serial.println("default switch");
#endif       
            break;
            
  }  
}



*/
