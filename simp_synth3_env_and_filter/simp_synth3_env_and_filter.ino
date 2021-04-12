#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine2; //xy=55,506.75000953674316
AudioAmplifier           amp9; //xy=95.41668319702148,720.7499980926514
AudioAmplifier           amp8; //xy=96.66667938232422,681.9999980926514
AudioAmplifier           amp7; //xy=97.91667938232422,635.7499942779541
AudioAmplifier           amp6; //xy=100.91668701171875,587.4999961853027
AudioSynthWaveformSine   sine1;          //xy=166.25000381469727,107.25000190734863
AudioAmplifier           amp4; //xy=185,336.25000190734863
AudioAmplifier           amp3; //xy=186.24999618530273,297.50000190734863
AudioAmplifier           amp5; //xy=186.24999618530273,377.49999809265137
AudioAmplifier           amp2; //xy=187.49999618530273,251.24999809265137
AudioAmplifier           amp1;           //xy=190.50000381469727,203
AudioSynthNoisePink      pink2; //xy=256.4166831970215,796.9999952316284
AudioSynthWaveformModulated waveformMod6; //xy=277.6666831970215,720.2499980926514
AudioSynthWaveformModulated waveformMod4; //xy=278.4166831970215,620.9999952316284
AudioSynthWaveformModulated waveformMod5; //xy=281.4166831970215,668.9999952316284
AudioSynthNoisePink      pink1;          //xy=346,412.4999990463257
AudioSynthWaveformModulated waveformMod3; //xy=367.25,335.75000190734863
AudioSynthWaveformModulated waveformMod1;   //xy=368,236.49999904632568
AudioSynthWaveformModulated waveformMod2; //xy=371,284.4999990463257
AudioSynthWaveformDc     dc2; //xy=555.4166984558105,716.2500047683716
AudioMixer4              mixer11; //xy=593.9166946411133,625
AudioSynthWaveformDc     dc1;            //xy=645.0000152587891,331.75000858306885
AudioMixer4              mixer1;         //xy=683.5000114440918,240.50000381469727
AudioEffectEnvelope      envelope4; //xy=724.4167022705078,697.7500047683716
AudioEffectEnvelope      envelope2; //xy=814.0000190734863,313.25000858306885
AudioMixer4              mixer12; //xy=850.4166984558105,749.5000038146973
AudioEffectEnvelope      envelope3; //xy=884.916690826416,560.2500038146973
AudioMixer4              mixer3; //xy=940.0000152587891,365.00000762939453
AudioEffectEnvelope      envelope1;      //xy=974.5000076293945,175.75000762939453
AudioFilterStateVariable filter2; //xy=1036.916690826416,658.2500038146973
AudioFilterStateVariable filter1;        //xy=1133.1666717529297,277.0833339691162
AudioMixer4              mixer13; //xy=1326.6666793823242,465
AudioEffectDelay         delay1;         //xy=1522.0238914489746,505.2381172180176
AudioEffectBitcrusher    bitcrusher1;    //xy=1685.0595741271973,372.0238380432129
AudioEffectFreeverbStereo freeverbs1;     //xy=1723.8095703125,317.02383613586426
AudioMixer4              mixer7; //xy=1809.1667175292969,620.9523887634277
AudioMixer4              mixer8; //xy=1809.1667175292969,700.9523887634277
AudioMixer4              mixer6; //xy=1816.3096618652344,546.6666793823242
AudioMixer4              mixer5; //xy=1822.0238227844238,452.3809928894043
AudioMixer4              mixer2; //xy=1947.1311569213867,186.0595588684082
AudioMixer4              mixer10; //xy=1959.1667175292969,662.3809776306152
AudioMixer4              mixer9; //xy=1967.7381286621094,513.8095664978027
AudioMixer4              mixer4; //xy=2139.345127105713,441.3095703125
AudioOutputAnalogStereo  dacs1;          //xy=2209.6429901123047,246.90481090545654
AudioConnection          patchCord1(sine2, amp6);
AudioConnection          patchCord2(sine2, amp7);
AudioConnection          patchCord3(sine2, amp8);
AudioConnection          patchCord4(sine2, amp9);
AudioConnection          patchCord5(sine2, 0, mixer12, 1);
AudioConnection          patchCord6(amp9, 0, waveformMod5, 1);
AudioConnection          patchCord7(amp8, 0, waveformMod6, 0);
AudioConnection          patchCord8(amp7, 0, waveformMod5, 0);
AudioConnection          patchCord9(amp6, 0, waveformMod4, 0);
AudioConnection          patchCord10(sine1, amp1);
AudioConnection          patchCord11(sine1, amp2);
AudioConnection          patchCord12(sine1, amp3);
AudioConnection          patchCord13(sine1, amp4);
AudioConnection          patchCord14(sine1, amp5);
AudioConnection          patchCord15(sine1, 0, mixer3, 1);
AudioConnection          patchCord16(amp4, 0, waveformMod2, 1);
AudioConnection          patchCord17(amp3, 0, waveformMod3, 0);
AudioConnection          patchCord18(amp5, 0, waveformMod3, 1);
AudioConnection          patchCord19(amp2, 0, waveformMod2, 0);
AudioConnection          patchCord20(amp1, 0, waveformMod1, 0);
AudioConnection          patchCord21(pink2, 0, mixer11, 3);
AudioConnection          patchCord22(waveformMod6, 0, mixer11, 2);
AudioConnection          patchCord23(waveformMod4, 0, mixer11, 0);
AudioConnection          patchCord24(waveformMod5, 0, mixer11, 1);
AudioConnection          patchCord25(pink1, 0, mixer1, 3);
AudioConnection          patchCord26(waveformMod3, 0, mixer1, 2);
AudioConnection          patchCord27(waveformMod1, 0, mixer1, 0);
AudioConnection          patchCord28(waveformMod2, 0, mixer1, 1);
AudioConnection          patchCord29(dc2, envelope4);
AudioConnection          patchCord30(mixer11, envelope3);
AudioConnection          patchCord31(dc1, envelope2);
AudioConnection          patchCord32(mixer1, envelope1);
AudioConnection          patchCord33(envelope4, 0, mixer12, 0);
AudioConnection          patchCord34(envelope2, 0, mixer3, 0);
AudioConnection          patchCord35(mixer12, 0, filter2, 1);
AudioConnection          patchCord36(envelope3, 0, filter2, 0);
AudioConnection          patchCord37(mixer3, 0, filter1, 1);
AudioConnection          patchCord38(envelope1, 0, filter1, 0);
AudioConnection          patchCord39(filter2, 0, mixer13, 1);
AudioConnection          patchCord40(filter1, 0, mixer13, 0);
AudioConnection          patchCord41(mixer13, 0, mixer2, 0);
AudioConnection          patchCord42(mixer13, freeverbs1);
AudioConnection          patchCord43(mixer13, 0, mixer4, 0);
AudioConnection          patchCord44(mixer13, bitcrusher1);
AudioConnection          patchCord45(mixer13, delay1);
AudioConnection          patchCord46(delay1, 0, mixer5, 0);
AudioConnection          patchCord47(delay1, 0, mixer7, 0);
AudioConnection          patchCord48(delay1, 1, mixer5, 1);
AudioConnection          patchCord49(delay1, 1, mixer7, 1);
AudioConnection          patchCord50(delay1, 2, mixer5, 2);
AudioConnection          patchCord51(delay1, 2, mixer7, 2);
AudioConnection          patchCord52(delay1, 3, mixer5, 3);
AudioConnection          patchCord53(delay1, 3, mixer7, 3);
AudioConnection          patchCord54(delay1, 4, mixer6, 0);
AudioConnection          patchCord55(delay1, 4, mixer8, 0);
AudioConnection          patchCord56(delay1, 5, mixer6, 1);
AudioConnection          patchCord57(delay1, 5, mixer8, 1);
AudioConnection          patchCord58(delay1, 6, mixer6, 2);
AudioConnection          patchCord59(delay1, 6, mixer8, 2);
AudioConnection          patchCord60(delay1, 7, mixer6, 3);
AudioConnection          patchCord61(delay1, 7, mixer8, 3);
AudioConnection          patchCord62(bitcrusher1, 0, mixer2, 2);
AudioConnection          patchCord63(bitcrusher1, 0, mixer4, 2);
AudioConnection          patchCord64(freeverbs1, 0, mixer2, 1);
AudioConnection          patchCord65(freeverbs1, 1, mixer4, 1);
AudioConnection          patchCord66(mixer7, 0, mixer10, 0);
AudioConnection          patchCord67(mixer8, 0, mixer10, 1);
AudioConnection          patchCord68(mixer6, 0, mixer9, 1);
AudioConnection          patchCord69(mixer5, 0, mixer9, 0);
AudioConnection          patchCord70(mixer2, 0, dacs1, 0);
AudioConnection          patchCord71(mixer10, 0, mixer4, 3);
AudioConnection          patchCord72(mixer9, 0, mixer2, 3);
AudioConnection          patchCord73(mixer4, 0, dacs1, 1);
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

const byte CTRL_OSC1_MIX = 16;
const byte CTRL_SAW_MIX = 100;
const byte CTRL_SQ_MIX = 101;
const byte CTRL_SIN_MIX = 102;
const byte CTRL_NOISE_MIX = 103;


const byte CTRL_VCA_A = 109;
const byte CTRL_VCA_D = 110;
const byte CTRL_VCA_S = 111;
const byte CTRL_VCA_R = 112;

const byte CTRL_FILT_CUTOFF = 104;

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

const byte CTRL_OSC2_MIX = 17;
const byte CTRL_2SIN_DISTORT = 18;
const byte CTRL_DETUNE_FREQ = 19;
const byte CTRL_2SAW_MIX = 20;
const byte CTRL_2SQ_MIX = 21;
const byte CTRL_2SIN_MIX = 22;
const byte CTRL_2NOISE_MIX = 23;

const byte CTRL_2VCA_A = 24;
const byte CTRL_2VCA_D = 25;
const byte CTRL_2VCA_S = 26;
const byte CTRL_2VCA_R = 27;

const byte CTRL_2FILT_CUTOFF = 28;

const byte CTRL_2VCF_A = 30;
const byte CTRL_2VCF_D = 31;
const byte CTRL_2VCF_S = 32;
const byte CTRL_2VCF_R = 33;
const byte CTRL_2VCF_AMNT = 34;


const byte CTRL_2LFO_F = 35;
const byte CTRL_2LFO_A = 36;
const byte CTRL_2LFO_FMOD1 = 37;
const byte CTRL_2LFO_FMOD2 = 38;
const byte CTRL_2LFO_FMOD3 = 39;
const byte CTRL_2LFO_SMOD2 = 40;
const byte CTRL_2LFO_VCFMOD = 41;




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


const byte CTRL_FX_DLYMIX_L = 58;
const byte CTRL_FX_DLYMIX_R = 59;

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

byte lastValidVcf2Cutoff=0;
byte lastValidVcf2Ammount=0;
float lastMasterFrequency=200;

byte kDetune = 0;

///////////////////////////////////////////////
//Helper functions
///////////////////////////////////////////////
void setAllOscFreq(float f){    
    waveformMod1.frequency(f);
    waveformMod2.frequency(f);
    waveformMod3.frequency(f);
    lastMasterFrequency = f;
}

void setAllOsc2Freq(float f){ 
    waveformMod4.frequency(f);
    waveformMod5.frequency(f);
    waveformMod6.frequency(f);
}

float getFreqFromDetune(){
    return map(kDetune, 0, 127, lastMasterFrequency/2, lastMasterFrequency);
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

//AMMOUNT + CUTOFF cannot exceed MAX or filter gets noizy
void filter2SetFreqFromVal(byte val){
    if ((int)val + (int) lastValidVcf2Ammount > VCF_MAX) {
        val = VCF_MAX - lastValidVcf2Ammount;
    }
    filter2.frequency(VCF_SCALE * (float)val / 127.0);
    lastValidVcf2Cutoff = val;
}

void filter2SetAmmountFromVal(byte val){
    if ((int)val + (int) lastValidVcf2Cutoff > VCF_MAX) {
        val = VCF_MAX - lastValidVcf2Cutoff;
    }
    dc2.amplitude((float)val / 127.0);
    lastValidVcf2Ammount = val;
}


///////////////////////////////////////////////
//CALLBACKS
///////////////////////////////////////////////


//with this scheme we get a new envelope every time a new note is hit,
//and the envelope realses only when that new note is released
void handleNoteOn(byte channel, byte note, byte velocity){
    Serial.println("note on");
    setAllOscFreq(midiLookUp[note]);
    setAllOsc2Freq(getFreqFromDetune());
    envelope1.noteOn();
    envelope2.noteOn();
    envelope3.noteOn();
    envelope4.noteOn();
    
    lastNote = note;
}


void handleNoteOff(byte channel, byte note, byte velocity){
    Serial.println("note off");
    if (note == lastNote){
        envelope1.noteOff();
        envelope2.noteOff();

        envelope3.noteOff();
        envelope4.noteOff();
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
            
        case CTRL_OSC1_MIX:
            mixer13.gain(0,((float)val)/127.0 );
            break;

            
///////////////////////////////////////////////
//OSCILLATOR MIX 2
///////////////////////////////////////////////
        case CTRL_2SAW_MIX:
            mixer11.gain(0,((float)val)/127.0 );
            break;      
        case CTRL_2SQ_MIX:
            mixer11.gain(1,((float)val)/127.0 );
            break;      
        case CTRL_2SIN_MIX:
            mixer11.gain(2,(2.0*(float)val)/127.0 );
            break;      
        case CTRL_2NOISE_MIX:
            mixer11.gain(3,((float)val)/127.0 );
            break;
            
        case CTRL_OSC2_MIX:
            mixer13.gain(1,((float)val)/127.0 );
            break;

        case CTRL_DETUNE_FREQ:          
            kDetune = val;  
            setAllOsc2Freq(getFreqFromDetune());
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
//VCA 2
///////////////////////////////////////////////
        case CTRL_2VCA_A:
            envelope3.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCA_D:
            envelope3.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCA_S:
            envelope3.sustain(((float)val)/127.0 );
            break;      
        case CTRL_2VCA_R:
            envelope3.release( 2000 * ((float)val)/127.0 );
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
//FILTER 2
///////////////////////////////////////////////
        case CTRL_2FILT_CUTOFF:
            filter2SetFreqFromVal(val);
            break;
        case CTRL_2VCF_AMNT:
            filter2SetAmmountFromVal(val);
            break;     
        case CTRL_2VCF_A:
            envelope2.attack( 2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCF_D:
            envelope2.decay(  2000 * ((float)val)/127.0 );
            break;      
        case CTRL_2VCF_S:
            envelope2.sustain(((float)val)/127.0 );
            break;      
        case CTRL_2VCF_R:
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
//LFO 2
///////////////////////////////////////////////
        case CTRL_2LFO_A:
            sine2.amplitude(((float)val)/127.0);
            break;
        case CTRL_2LFO_F:
            sine2.frequency(60 * ((float)val)/127.0);
            break;     
                        
        case CTRL_2LFO_FMOD1:
            amp6.gain(((float)val)/127.0 );
            break;  
        case CTRL_2LFO_FMOD2:
            amp7.gain(((float)val)/127.0 );
            break;    
        case CTRL_2LFO_FMOD3:
            amp8.gain(((float)val)/127.0 );
            break;    
            
        case CTRL_2LFO_SMOD2:
            amp9.gain(((float)val)/127.0 );
            break;    
                  
        case CTRL_2LFO_VCFMOD:
            mixer12.gain(1,((float)val)/127.0 );
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
    AudioMemory(400);

    mixer13.gain(0, 1.0);
    mixer13.gain(1, 1.0);
    mixer13.gain(2, 0.0);
    mixer13.gain(3, 0.0);
    
//OSC 1
    int default_freq = 200;
    float default_amp = .25;
    float default_pw = .15;
    waveformMod1.begin(default_amp,default_freq, WAVEFORM_SAWTOOTH);    
    waveformMod2.begin(default_amp, default_freq, WAVEFORM_PULSE);    
    waveformMod3.begin(default_amp, default_freq ,WAVEFORM_TRIANGLE_VARIABLE);  
    lastMasterFrequency = (float)default_freq;  
    pink1.amplitude(default_amp);
    mixer1.gain(0 , 1.0);
    mixer1.gain(1 , 1.0);
    mixer1.gain(2 , 1.0);
    mixer1.gain(3 , 1.0);

//OSC2
    waveformMod4.begin(default_amp,default_freq, WAVEFORM_SAWTOOTH);    
    waveformMod5.begin(default_amp, default_freq, WAVEFORM_PULSE);    
    waveformMod6.begin(1.0, default_freq ,WAVEFORM_SINE); 
       
    pink2.amplitude(default_amp);
    mixer11.gain(0 , 1.0);
    mixer11.gain(1 , 1.0);
    mixer11.gain(2 , 1.0);
    mixer11.gain(3 , 1.0);
    
//VCA 1
    envelope1.delay(0);
    envelope1.attack(0);
    envelope1.hold(0);
    envelope1.decay(100);
    envelope1.sustain(.5);
    envelope1.release(100);

//VCA 2
    envelope3.delay(0);
    envelope3.attack(0);
    envelope3.hold(0);
    envelope3.decay(100);
    envelope3.sustain(.5);
    envelope3.release(100);

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

//VCF 2
    envelope4.delay(0);
    envelope4.attack(0);
    envelope4.hold(0);
    envelope4.decay(0);
    envelope4.sustain(1.0);
    envelope4.release(100);


    filter2.octaveControl(3);
    filter2SetFreqFromVal(50);
    filter2SetAmmountFromVal(0);


    
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
    
 //LFO 2
    sine2.frequency(1.0);
    sine2.amplitude(0.0);
    amp6.gain(0.0);
    amp7.gain(0.0);
    amp8.gain(0.0);
    amp9.gain(0.0);
    
    mixer12.gain(0 , 1.0);
    mixer12.gain(1 , 0.0);
    mixer12.gain(2 , 0.0);
    mixer12.gain(3 , 0.0);


    
    

//Panning mixers L , R
    mixer2.gain(0 , 1.0);
    mixer2.gain(1 , 0.0);
    mixer2.gain(2 , 0.0);
    mixer2.gain(3 , 0.0);
    
    mixer4.gain(0 , 1.0);
    mixer4.gain(1 , 0.0);
    mixer4.gain(2 , 0.0);
    mixer4.gain(3 , 0.0);

    
//Delay mixers L L R R
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

    
    initLookupTable();

}




void loop() {
    usbMIDI.read();
}
