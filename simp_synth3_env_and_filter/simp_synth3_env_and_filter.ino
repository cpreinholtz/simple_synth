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
AudioSynthKarplusStrong  string1;        //xy=258.4126968383789,797.4603118896484
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
AudioAmplifier           amp10; //xy=1822.6986083984375,412.69847869873047
AudioMixer4              mixer2; //xy=1947.1311569213867,186.0595588684082
AudioAmplifier           amp14; //xy=1968.889030456543,649.8413467407227
AudioMixer4              mixer4; //xy=2217.9169998168945,411.3095817565918
AudioSynthNoiseWhite     noise1;         //xy=2300.6666564941406,337.66666412353516
AudioSynthSimpleDrum     drum2; //xy=2306.666816711426,286.6666650772095
AudioSynthSimpleDrum     drum1;          //xy=2329.269847869873,234.76195335388184
AudioSynthNoiseWhite     noise2;         //xy=2356.666820526123,378.6666660308838
AudioAmplifier           ampDrum2; //xy=2471.333251953125,267.6666564941406
AudioEffectEnvelope      envelopeD3;      //xy=2534.6666564941406,367.66666412353516
AudioAmplifier           ampDrum1;           //xy=2604.3336486816406,229.66667938232422
AudioEffectDigitalCombine combine1;       //xy=2628.6666564941406,290.6666650772095
AudioMixer4              mixerFinalL; //xy=3231.333251953125,59.66666793823242
AudioMixer4              mixerFinalR; //xy=3242.333251953125,379.6666564941406
AudioOutputAnalogStereo  dacs1;          //xy=3323.9289016723633,199.76204299926758
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
AudioConnection          patchCord21(string1, 0, mixer11, 3);
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
AudioConnection          patchCord59(mixer2, 0, mixerFinalL, 1);
AudioConnection          patchCord60(amp14, 0, mixer2, 3);
AudioConnection          patchCord61(amp14, 0, mixer4, 3);
AudioConnection          patchCord62(mixer4, 0, mixerFinalR, 1);
AudioConnection          patchCord63(noise1, 0, combine1, 1);
AudioConnection          patchCord64(drum2, ampDrum2);
AudioConnection          patchCord65(drum1, ampDrum1);
AudioConnection          patchCord66(noise2, envelopeD3);
AudioConnection          patchCord67(ampDrum2, 0, combine1, 0);
AudioConnection          patchCord68(envelopeD3, 0, mixerFinalL, 3);
AudioConnection          patchCord69(envelopeD3, 0, mixerFinalR, 3);
AudioConnection          patchCord70(ampDrum1, 0, mixerFinalL, 0);
AudioConnection          patchCord71(ampDrum1, 0, mixerFinalR, 0);
AudioConnection          patchCord72(combine1, 0, mixerFinalL, 2);
AudioConnection          patchCord73(combine1, 0, mixerFinalR, 2);
AudioConnection          patchCord74(mixerFinalL, 0, dacs1, 0);
AudioConnection          patchCord75(mixerFinalR, 0, dacs1, 1);
// GUItool: end automatically generated code





#include "cc_in.h"
#include "clk.h"

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
const int ledPin = 13;






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
    //string1.frequency(f);
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
    float f2 = getFreqFromDetune();
    setAllOsc2Freq(f2);
    envelope1.noteOn();
    envelope2.noteOn();
    envelope3.noteOn();
    envelope4.noteOn();
    string1.noteOn(f2, m127(velocity) );
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
    // initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT);
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
    //string1.amplitude(default_amp);
    


    
    initLookupTable();
    setDefaults();

}




void loop() {
    usbMIDI.read();
    checkTime();
}
