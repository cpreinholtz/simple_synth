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
AudioAmplifier           amp13; //xy=1565.0795249938965,244.12698554992676
AudioEffectFreeverbStereo freeverbs1;     //xy=1589.5238952636719,328.4524116516113
AudioMixer4              mixer5; //xy=1614.6032447814941,715.5556106567383
AudioEffectBitcrusher    bitcrusher1;    //xy=1656.4880676269531,409.166711807251
AudioAmplifier           amp11; //xy=1730.7938270568848,292.6984062194824
AudioEffectDelay         delay1;         //xy=1763.4525985717773,696.6666793823242
AudioAmplifier           amp12; //xy=1775.0793266296387,331.26985359191895
AudioAmplifier           amp10; //xy=1798.412826538086,411.26988220214844
AudioMixer4              mixer2; //xy=1947.1311569213867,186.0595588684082
AudioAmplifier           amp14; //xy=1968.889030456543,649.8413467407227
AudioOutputAnalogStereo  dacs1;          //xy=2209.6429901123047,246.90481090545654
AudioMixer4              mixer4; //xy=2217.916759490967,429.8810043334961
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
AudioConnection          patchCord41(mixer13, freeverbs1);
AudioConnection          patchCord42(mixer13, bitcrusher1);
AudioConnection          patchCord43(mixer13, amp13);
AudioConnection          patchCord44(mixer13, 0, mixer5, 0);
AudioConnection          patchCord45(amp13, 0, mixer2, 0);
AudioConnection          patchCord46(amp13, 0, mixer4, 0);
AudioConnection          patchCord47(freeverbs1, 0, amp11, 0);
AudioConnection          patchCord48(freeverbs1, 1, amp12, 0);
AudioConnection          patchCord49(freeverbs1, 1, mixer5, 1);
AudioConnection          patchCord50(mixer5, delay1);
AudioConnection          patchCord51(bitcrusher1, amp10);
AudioConnection          patchCord52(bitcrusher1, 0, mixer5, 2);
AudioConnection          patchCord53(amp11, 0, mixer2, 1);
AudioConnection          patchCord54(delay1, 0, mixer5, 3);
AudioConnection          patchCord55(delay1, 0, amp14, 0);
AudioConnection          patchCord56(amp12, 0, mixer4, 1);
AudioConnection          patchCord57(amp10, 0, mixer2, 2);
AudioConnection          patchCord58(amp10, 0, mixer4, 2);
AudioConnection          patchCord59(mixer2, 0, dacs1, 0);
AudioConnection          patchCord60(amp14, 0, mixer2, 3);
AudioConnection          patchCord61(amp14, 0, mixer4, 3);
AudioConnection          patchCord62(mixer4, 0, dacs1, 1);
// GUItool: end automatically generated code


#include "cc_in.h"

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
    usbMIDI.setHandleControlChange(ccHandler);
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
    //float default_pw = .15;
    waveformMod1.begin(default_amp,default_freq, WAVEFORM_SAWTOOTH);    
    waveformMod2.begin(default_amp, default_freq, WAVEFORM_PULSE);    
    waveformMod3.begin(default_amp, default_freq ,WAVEFORM_TRIANGLE_VARIABLE);  
    lastMasterFrequency = (float)default_freq;  
    pink1.amplitude(default_amp);


//OSC2

    waveformMod4.begin(default_amp,default_freq, WAVEFORM_SAWTOOTH);    
    waveformMod5.begin(default_amp, default_freq, WAVEFORM_PULSE);    
    waveformMod6.begin(default_amp, default_freq ,WAVEFORM_SINE);   
    pink2.amplitude(default_amp);
    


    
    initLookupTable();
    setDefaults();

}




void loop() {
    usbMIDI.read();
}
