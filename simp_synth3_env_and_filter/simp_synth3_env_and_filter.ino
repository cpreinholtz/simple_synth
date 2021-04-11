#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioAmplifier           amp4; //xy=60.000003814697266,302.50000381469727
AudioAmplifier           amp3; //xy=61.25,263.75000381469727
AudioAmplifier           amp5; //xy=61.25,343.75
AudioAmplifier           amp2; //xy=62.5,217.5
AudioAmplifier           amp1;           //xy=65.50000762939453,169.25000190734863
AudioSynthWaveformSine   sine1;          //xy=75.00000381469727,118.50000190734863
AudioSynthNoisePink      pink1;          //xy=221.00000381469727,378.7500009536743
AudioSynthWaveformModulated waveformMod3; //xy=242.25000381469727,302.00000381469727
AudioSynthWaveformModulated waveformMod1;   //xy=243.00000381469727,202.75000095367432
AudioSynthWaveformModulated waveformMod2; //xy=246.00000381469727,250.75000095367432
AudioSynthWaveformDc     dc1;            //xy=330.00000381469727,501.7500009536743
AudioMixer4              mixer1;         //xy=421.00000381469727,296.7500009536743
AudioEffectEnvelope      envelope2; //xy=484.00000381469727,440.7500009536743
AudioEffectEnvelope      envelope1;      //xy=512.0000038146973,200.75000095367432
AudioMixer4              mixer3; //xy=610,492.5
AudioFilterStateVariable filter1;        //xy=664.0000038146973,298.7500009536743
AudioEffectDelay         delay1;         //xy=742.8571739196777,568.5714340209961
AudioEffectBitcrusher    bitcrusher1;    //xy=905.8928565979004,435.3571548461914
AudioEffectFreeverbStereo freeverbs1;     //xy=944.6428527832031,380.3571529388428
AudioMixer4              mixer7; //xy=1030,684.2857055664062
AudioMixer4              mixer8; //xy=1030,764.2857055664062
AudioMixer4              mixer6; //xy=1037.1429443359375,609.9999961853027
AudioMixer4              mixer5; //xy=1042.857105255127,515.7143096923828
AudioMixer4              mixer2; //xy=1167.9644393920898,249.39287567138672
AudioMixer4              mixer10; //xy=1180,725.7142944335938
AudioMixer4              mixer9; //xy=1188.5714111328125,577.1428833007812
AudioMixer4              mixer4; //xy=1360.178409576416,504.6428871154785
AudioOutputAnalogStereo  dacs1;          //xy=1367.1428184509277,323.57146167755127
AudioConnection          patchCord1(amp4, 0, waveformMod2, 1);
AudioConnection          patchCord2(amp3, 0, waveformMod3, 0);
AudioConnection          patchCord3(amp5, 0, waveformMod3, 1);
AudioConnection          patchCord4(amp2, 0, waveformMod2, 0);
AudioConnection          patchCord5(amp1, 0, waveformMod1, 0);
AudioConnection          patchCord6(sine1, amp1);
AudioConnection          patchCord7(sine1, amp2);
AudioConnection          patchCord8(sine1, amp3);
AudioConnection          patchCord9(sine1, amp4);
AudioConnection          patchCord10(sine1, amp5);
AudioConnection          patchCord11(sine1, 0, mixer3, 1);
AudioConnection          patchCord12(pink1, 0, mixer1, 3);
AudioConnection          patchCord13(waveformMod3, 0, mixer1, 2);
AudioConnection          patchCord14(waveformMod1, 0, mixer1, 0);
AudioConnection          patchCord15(waveformMod2, 0, mixer1, 1);
AudioConnection          patchCord16(dc1, envelope2);
AudioConnection          patchCord17(mixer1, envelope1);
AudioConnection          patchCord18(envelope2, 0, mixer3, 0);
AudioConnection          patchCord19(envelope1, 0, filter1, 0);
AudioConnection          patchCord20(mixer3, 0, filter1, 1);
AudioConnection          patchCord21(filter1, 0, mixer2, 0);
AudioConnection          patchCord22(filter1, 0, mixer4, 0);
AudioConnection          patchCord23(filter1, 0, freeverbs1, 0);
AudioConnection          patchCord24(filter1, 0, bitcrusher1, 0);
AudioConnection          patchCord25(filter1, 0, delay1, 0);
AudioConnection          patchCord26(delay1, 0, mixer5, 0);
AudioConnection          patchCord27(delay1, 0, mixer7, 0);
AudioConnection          patchCord28(delay1, 1, mixer5, 1);
AudioConnection          patchCord29(delay1, 1, mixer7, 1);
AudioConnection          patchCord30(delay1, 2, mixer5, 2);
AudioConnection          patchCord31(delay1, 2, mixer7, 2);
AudioConnection          patchCord32(delay1, 3, mixer5, 3);
AudioConnection          patchCord33(delay1, 3, mixer7, 3);
AudioConnection          patchCord34(delay1, 4, mixer6, 0);
AudioConnection          patchCord35(delay1, 4, mixer8, 0);
AudioConnection          patchCord36(delay1, 5, mixer6, 1);
AudioConnection          patchCord37(delay1, 5, mixer8, 1);
AudioConnection          patchCord38(delay1, 6, mixer6, 2);
AudioConnection          patchCord39(delay1, 6, mixer8, 2);
AudioConnection          patchCord40(delay1, 7, mixer6, 3);
AudioConnection          patchCord41(delay1, 7, mixer8, 3);
AudioConnection          patchCord42(bitcrusher1, 0, mixer2, 2);
AudioConnection          patchCord43(bitcrusher1, 0, mixer4, 2);
AudioConnection          patchCord44(freeverbs1, 0, mixer2, 1);
AudioConnection          patchCord45(freeverbs1, 1, mixer4, 1);
AudioConnection          patchCord46(mixer7, 0, mixer10, 0);
AudioConnection          patchCord47(mixer8, 0, mixer10, 1);
AudioConnection          patchCord48(mixer6, 0, mixer9, 1);
AudioConnection          patchCord49(mixer5, 0, mixer9, 0);
AudioConnection          patchCord50(mixer2, 0, dacs1, 0);
AudioConnection          patchCord51(mixer10, 0, mixer4, 3);
AudioConnection          patchCord52(mixer9, 0, mixer2, 3);
AudioConnection          patchCord53(mixer4, 0, dacs1, 1);
// GUItool: end automatically generated code






///////////////////////////////////////////////
//CONSTANTS
///////////////////////////////////////////////

#define DEBUG_ENABLE

const float VCF_SCALE = 10000;
const int VCF_MAX = 127;
const float DELAY_SCALE = 1000.0;

//lookup table
float midiLookUp[127];


//CONTROL CHANNELS
const byte CTRL_MASTER_FREQ = 99;

const byte CTRL_SAW_MIX = 100;
const byte CTRL_SQ_MIX = 101;
const byte CTRL_SIN_MIX = 102;
const byte CTRL_NOISE_MIX = 103;





const byte CTRL_VCA_A = 109;
const byte CTRL_VCA_D = 110;
const byte CTRL_VCA_S = 111;
const byte CTRL_VCA_R = 112;


const byte CTRL_FILT_CUTOFF = 104;
const byte CTRL_FILT_MIX = 105;

const byte CTRL_VCF_A = 113;
const byte CTRL_VCF_D = 114;
const byte CTRL_VCF_S = 115;
const byte CTRL_VCF_R = 116;
const byte CTRL_VCF_AMNT = 117;


const byte CTRL_LFO_F = 118;
const byte CTRL_LFO_A = 119;
const byte CTRL_LFO_FMOD1 = 120;
const byte CTRL_LFO_FMOD2 = 121;
const byte CTRL_LFO_FMOD3 = 122;
const byte CTRL_LFO_SMOD2 = 123;
const byte CTRL_LFO_SMOD3 = 124;
const byte CTRL_LFO_VCFMOD = 125;



const byte CTRL_FX_DRY_MIX_L = 99;
const byte CTRL_FX_DRY_MIX_R = 98;

const byte CTRL_FX_BC_MIX_L = 97;
const byte CTRL_FX_BC_MIX_R = 96;
const byte CTRL_FX_BC_BITS = 95;
const byte CTRL_FX_BC_RATE = 94;


const byte CTRL_FX_REVERB_MIX_L = 93;
const byte CTRL_FX_REVERB_MIX_R = 92;
const byte CTRL_FX_REVERB_SIZE = 91;
const byte CTRL_FX_REVERB_DAMP = 90;


const byte CTRL_FX_DLYMIX_L = 38;
const byte CTRL_FX_DLYMIX_R = 39;

const byte CTRL_FX_DLY1_S = 60;
const byte CTRL_FX_DLY1_L = 61;
const byte CTRL_FX_DLY1_R = 62;

const byte CTRL_FX_DLY2_S = 63;
const byte CTRL_FX_DLY2_L = 64;
const byte CTRL_FX_DLY2_R = 65;

const byte CTRL_FX_DLY3_S = 66;
const byte CTRL_FX_DLY3_L = 67;
const byte CTRL_FX_DLY3_R = 68;

const byte CTRL_FX_DLY4_S = 69;
const byte CTRL_FX_DLY4_L = 70;
const byte CTRL_FX_DLY4_R = 71;

const byte CTRL_FX_DLY5_S = 72;
const byte CTRL_FX_DLY5_L = 73;
const byte CTRL_FX_DLY5_R = 74;

const byte CTRL_FX_DLY6_S = 75;
const byte CTRL_FX_DLY6_L = 76;
const byte CTRL_FX_DLY6_R = 77;

const byte CTRL_FX_DLY7_S = 78;
const byte CTRL_FX_DLY7_L = 79;
const byte CTRL_FX_DLY7_R = 80;

const byte CTRL_FX_DLY8_S = 81;
const byte CTRL_FX_DLY8_L = 82;
const byte CTRL_FX_DLY8_R = 83;







///////////////////////////////////////////////
//globals
///////////////////////////////////////////////
byte lastNote=0;

byte lastValidVcfCutoff=0;
byte lastValidVcfAmmount=0;



///////////////////////////////////////////////
//Helper functions
///////////////////////////////////////////////
void setAllOscFreq(float f){    
    waveformMod1.frequency(f);
    waveformMod2.frequency(f);
    waveformMod3.frequency(f);
}


//AMMOUNT + CUTOFF cannot exceed MAX or filter gets noizy
void filterSetFreqFromVal(byte val){
    if ((int)val + (int) lastValidVcfAmmount > VCF_MAX) {
        val = VCF_MAX - lastValidVcfAmmount;
    }
    filter1.frequency(VCF_SCALE * (float)val / 127.0);
    lastValidVcfCutoff = val;
}

void filterSetAmmountFromVal(byte val){
    if ((int)val + (int) lastValidVcfCutoff > VCF_MAX) {
        val = VCF_MAX - lastValidVcfCutoff;
    }
    dc1.amplitude((float)val / 127.0);
    lastValidVcfAmmount = val;
}



///////////////////////////////////////////////
//CALLBACKS
///////////////////////////////////////////////


//with this scheme we get a new envelope every time a new note is hit,
//and the envelope realses only when that new note is released
void handleNoteOn(byte channel, byte note, byte velocity){
    Serial.println("note on");
    setAllOscFreq(midiLookUp[note]);
    envelope1.noteOn();
    envelope2.noteOn();
    lastNote = note;
}


void handleNoteOff(byte channel, byte note, byte velocity){
    Serial.println("note off");
    if (note == lastNote){
        envelope1.noteOff();
        envelope2.noteOff();
    }
}





void ctrlChange(byte ch, byte ctrl, byte val){
#ifdef DEBUG_ENABLE
    Serial.println("ctrl change hit");
    Serial.println(ctrl);
    Serial.println(val);
#endif
    
    switch (ctrl) {
///////////////////////////////////////////////
//OSCILLATOR MIX
///////////////////////////////////////////////
        case CTRL_SAW_MIX:
            mixer1.gain(0,((float)val)/127.0 );
            break;      
        case CTRL_SQ_MIX:
            mixer1.gain(1,((float)val)/127.0 );
            break;      
        case CTRL_SIN_MIX:
            mixer1.gain(2,(2.0*(float)val)/127.0 );
            break;      
        case CTRL_NOISE_MIX:
            mixer1.gain(3,((float)val)/127.0 );
            break;
///////////////////////////////////////////////
//VCA
///////////////////////////////////////////////
        case CTRL_VCA_A:
            envelope1.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCA_D:
            envelope1.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCA_S:
            envelope1.sustain(((float)val)/127.0 );
            break;      
        case CTRL_VCA_R:
            envelope1.release( 2000 * ((float)val)/127.0 );
            break;

///////////////////////////////////////////////
//FILTER
///////////////////////////////////////////////
        case CTRL_FILT_CUTOFF:
            filterSetFreqFromVal(val);
            break;
        case CTRL_VCF_AMNT:
            filterSetAmmountFromVal(val);
            break;     
        case CTRL_VCF_A:
            envelope2.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCF_D:
            envelope2.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_VCF_S:
            envelope2.sustain(((float)val)/127.0 );
            break;      
        case CTRL_VCF_R:
            envelope2.release( 2000 * ((float)val)/127.0 );
            break;

///////////////////////////////////////////////
//EFFECTS DRY
///////////////////////////////////////////////
        case CTRL_FX_DRY_MIX_L:
            mixer2.gain(0, (float)val/127.0);
            break;
        case CTRL_FX_DRY_MIX_R:
            mixer4.gain(0, (float)val/127.0);
            break;


///////////////////////////////////////////////
//EFFECTS REVERB
///////////////////////////////////////////////
        case CTRL_FX_REVERB_SIZE:
            freeverbs1.roomsize((float)val/127.0);
            break;
        case CTRL_FX_REVERB_DAMP:
            freeverbs1.damping((float)val/127.0);
            break;            
        case CTRL_FX_REVERB_MIX_L:
            mixer2.gain(1, (float)val/127.0);
            break;
        case CTRL_FX_REVERB_MIX_R:
            mixer4.gain(1,(float)val/127.0);
            break;
            



///////////////////////////////////////////////
//EFFECTS BC
///////////////////////////////////////////////
   
        case CTRL_FX_BC_MIX_L:
            mixer2.gain(2, (float)val/127.0);
            break;
        case CTRL_FX_BC_MIX_R:
            mixer4.gain(2, (float)val/127.0);
            break;     
        case CTRL_FX_BC_BITS:
            bitcrusher1.bits( (int)(16*(float)val/127.0));
            break;
        case CTRL_FX_BC_RATE:
            bitcrusher1.sampleRate( (int)(44000*(float)val/127.0) );
            break;

///////////////////////////////////////////////
//EFFECTS Delay
///////////////////////////////////////////////
            

        case CTRL_FX_DLYMIX_L:
            mixer2.gain(3, (float)val/127.0);
            break;
        case CTRL_FX_DLYMIX_R:
            mixer4.gain(3, (float)val/127.0);
            break;

        case CTRL_FX_DLY1_S:
            delay1.delay(0, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY1_L:
            mixer5.gain(0, (float)val/127.0);
            break;
        case CTRL_FX_DLY1_R:
            mixer7.gain(0, (float)val/127.0);
            break;

        case CTRL_FX_DLY2_S:
            delay1.delay(1, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY2_L:
            mixer5.gain(1, (float)val/127.0);
            break;
        case CTRL_FX_DLY2_R:
            mixer7.gain(1, (float)val/127.0);
            break;

        case CTRL_FX_DLY3_S:
            delay1.delay(2, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY3_L:
            mixer5.gain(2, (float)val/127.0);
            break;
        case CTRL_FX_DLY3_R:
            mixer7.gain(2, (float)val/127.0);
            break;

        case CTRL_FX_DLY4_S:
            delay1.delay(3, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY4_L:
            mixer5.gain(3, (float)val/127.0);
            break;
        case CTRL_FX_DLY4_R:
            mixer7.gain(3, (float)val/127.0);
            break;

        case CTRL_FX_DLY5_S:
            delay1.delay(4, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY5_L:
            mixer6.gain(0, (float)val/127.0);
            break;
        case CTRL_FX_DLY5_R:
            mixer8.gain(0, (float)val/127.0);
            break;

        case CTRL_FX_DLY6_S:
            delay1.delay(5, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY6_L:
            mixer6.gain(1, (float)val/127.0);
            break;
        case CTRL_FX_DLY6_R:
            mixer8.gain(1, (float)val/127.0);
            break;

        case CTRL_FX_DLY7_S:
            delay1.delay(6, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY7_L:
            mixer6.gain(2, (float)val/127.0);
            break;
        case CTRL_FX_DLY7_R:
            mixer8.gain(2, (float)val/127.0);
            break;

        case CTRL_FX_DLY8_S:
            delay1.delay(7, DELAY_SCALE* (float)val/127.0);
            break;
        case CTRL_FX_DLY8_L:
            mixer6.gain(3, (float)val/127.0);
            break;
        case CTRL_FX_DLY8_R:
            mixer8.gain(3, (float)val/127.0);
            break;



///////////////////////////////////////////////
//LFO
///////////////////////////////////////////////
        case CTRL_LFO_A:
            sine1.amplitude(((float)val)/127.0);
            break;
        case CTRL_LFO_F:
            sine1.frequency(60 * ((float)val)/127.0);
            break;     
                        
        case CTRL_LFO_FMOD1:
            amp1.gain(((float)val)/127.0 );
            break;  
        case CTRL_LFO_FMOD2:
            amp2.gain(((float)val)/127.0 );
            break;    
        case CTRL_LFO_FMOD3:
            amp3.gain(((float)val)/127.0 );
            break;    
            
        case CTRL_LFO_SMOD2:
            amp4.gain(((float)val)/127.0 );
            break;    
        case CTRL_LFO_SMOD3:
            amp5.gain(((float)val)/127.0 );
            break; 
                  
        case CTRL_LFO_VCFMOD:
            mixer3.gain(1,((float)val)/127.0 );
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


void initLookupTable(){
    float a = 440; // a is 440 hz...
    for (int x = 0; x < 127; ++x)
    {
        midiLookUp[x] = (a / 32.0) * ( pow(2,(((float)x - 9.0) / 12.0)) )  ;
#ifdef DEBUG_ENABLE
            Serial.println("setting note to ");
            Serial.println(x);
            Serial.println(midiLookUp[x]);
#endif           
        
    }
}



///////////////////////////////////////////////
//SETUP / LOOP
///////////////////////////////////////////////


void setup() {
    // initialize serial communications at 9600 bps:
    //
#ifdef DEBUG_ENABLE
    Serial.begin(9600);
#endif
    usbMIDI.setHandleControlChange(ctrlChange);
    usbMIDI.setHandleNoteOn(handleNoteOn);
    usbMIDI.setHandleNoteOff(handleNoteOff);
    AudioMemory(200);


//OSC
    int default_freq = 200;
    float default_amp = .25;
    float default_pw = .15;
    waveformMod1.begin(default_amp,default_freq, WAVEFORM_SAWTOOTH);    
    waveformMod2.begin(default_amp, default_freq, WAVEFORM_PULSE);    
    waveformMod3.begin(default_amp, default_freq ,WAVEFORM_TRIANGLE_VARIABLE);    
    pink1.amplitude(default_amp);
    mixer1.gain(0 , 1.0);
    mixer1.gain(1 , 1.0);
    mixer1.gain(2 , 1.0);
    mixer1.gain(3 , 1.0);
    
//VCA
    envelope1.delay(0);
    envelope1.attack(0);
    envelope1.hold(0);
    envelope1.decay(100);
    envelope1.sustain(.5);
    envelope1.release(100);

//VCF
    envelope2.delay(0);
    envelope2.attack(0);
    envelope2.hold(0);
    envelope2.decay(0);
    envelope2.sustain(1.0);
    envelope2.release(100);


    filter1.octaveControl(3);
    filterSetFreqFromVal(50);
    filterSetAmmountFromVal(0);

//Panning mixers
    mixer2.gain(0 , 1.0);
    mixer2.gain(1 , 0.0);
    mixer2.gain(2 , 0.0);
    mixer2.gain(3 , 0.0);
    
    mixer4.gain(0 , 1.0);
    mixer4.gain(1 , 0.0);
    mixer4.gain(2 , 0.0);
    mixer4.gain(3 , 0.0);

    
//Delay mixers
    mixer5.gain(0 , 0.0);
    mixer5.gain(1 , 0.0);
    mixer5.gain(2 , 0.0);
    mixer5.gain(3 , 0.0);
    
    mixer6.gain(0 , 0.0);
    mixer6.gain(1 , 0.0);
    mixer6.gain(2 , 0.0);
    mixer6.gain(3 , 0.0);

    mixer7.gain(0 , 0.0);
    mixer7.gain(1 , 0.0);
    mixer7.gain(2 , 0.0);
    mixer7.gain(3 , 0.0);

    mixer8.gain(0 , 0.0);
    mixer8.gain(1 , 0.0);
    mixer8.gain(2 , 0.0);
    mixer8.gain(3 , 0.0);

    mixer9.gain(0 , 1.0);
    mixer9.gain(1 , 1.0);
    mixer9.gain(2 , 0.0);
    mixer9.gain(3 , 0.0);

    mixer10.gain(0 , 1.0);
    mixer10.gain(1 , 1.0);
    mixer10.gain(2 , 0.0);
    mixer10.gain(3 , 0.0);
    
    //LFO
    sine1.frequency(1.0);
    sine1.amplitude(0.0);
    amp1.gain(0.0);
    amp2.gain(0.0);
    amp3.gain(0.0);
    amp4.gain(0.0);
    amp5.gain(0.0);
    
    mixer3.gain(0 , 1.0);
    mixer3.gain(1 , 0.0);
    mixer3.gain(2 , 0.0);
    mixer3.gain(3 , 0.0);

    initLookupTable();

}




void loop() {
    usbMIDI.read();
}
