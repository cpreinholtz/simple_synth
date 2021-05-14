#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformModulated waveformMod3Osc2Voice1;   //xy=771.3333358764648,1141.0000114440918
AudioSynthWaveformModulated waveformMod4Osc2Voice1;   //xy=783.3333358764648,1212.000072479248
AudioSynthWaveformModulated waveformMod1Osc2Voice1;   //xy=787.3333206176758,1026.0000734329224
AudioSynthWaveformModulated waveformMod2Osc2Voice1;   //xy=789.3333511352539,1087.0000734329224
AudioSynthWaveformModulated waveformMod1Osc1Voice1;   //xy=796.0002517700195,794.3335084915161
AudioSynthWaveformModulated waveformMod2Osc1Voice1;   //xy=797.0002517700195,844.3335084915161
AudioSynthWaveformModulated waveformMod4Osc1Voice1;   //xy=801.3334808349609,942.000072479248
AudioSynthWaveformModulated waveformMod3Osc1Voice1;   //xy=804.0002517700195,890.3334159851074
AudioSynthNoisePink      pinkVoice1;          //xy=1052.6667366027832,1331.0000381469727
AudioMixer4              mixerOsc2Voice1;         //xy=1067.333480834961,1061.0000305175781
AudioMixer4              mixerOsc1Voice1;         //xy=1098.0003967285156,822.333438873291
AudioMixer4              mixerVoice1;         //xy=1327.3334121704102,994.0000267028809
AudioEffectEnvelope      envelopeVoice1;      //xy=1460.0000839233398,911.3333597183228
AudioMixer4              mixerAllVoices;         //xy=1804.515625,904.515625
AudioSynthWaveformDc     dcVcfEnvAmmount;            //xy=1806.0001220703125,1518.3333740234375
AudioEffectEnvelope      envelopeVcf;      //xy=1816.0002784729004,1405.3334169387817
AudioAmplifier           ampVcf;           //xy=1987.515625,832.515625
AudioFilterStateVariable filterVcf;        //xy=1998,994.3333129882812
AudioMixer4              mixerVcf;         //xy=2018.0000953674316,1276.3333911895752
AudioSynthWaveformSine   sineLfoVcf;          //xy=2098.000114440918,1499.3333973884583
AudioMixer4              mixerLpassHpass;        //xy=2214.0000953674316,1128.3332691192627
AudioAmplifier           ampDry;           //xy=2438.015625,1180.515625
AudioMixer4              mixerDelayFb;         //xy=2479,1432.3333129882812
AudioEffectDelay         delay1;         //xy=2642.00040435791,1436.3333234786987
AudioAmplifier           ampDly;           //xy=2841.0156784057617,1448.5157623291016
AudioMixer4              mixerDelayFf; //xy=2916.515739440918,1344.515640258789
AudioEffectBitcrusher    bitcrusher1;    //xy=3074.000476837158,1570.3333387374878
AudioEffectFreeverbStereo freeverbs1;     //xy=3096.0000495910645,1257.3332624435425
AudioAmplifier           ampRvbL;           //xy=3200.015625,1317.515625
AudioAmplifier           ampRvbR;           //xy=3234.015625,1362.515625
AudioAmplifier           ampBc;           //xy=3257.015625,1590.515625
AudioMixer4              mixerFxL;         //xy=3320.0000495910645,1231.3333234786987
AudioMixer4              mixerFxR;         //xy=3512.000232696533,1444.3332681655884
AudioSynthSimpleDrum     drumSnare;          //xy=3622.0003662109375,1287.3334035873413
AudioSynthNoiseWhite     noiseSnare;         //xy=3644.000244140625,1336.3333129882812
AudioSynthNoiseWhite     noiseHat;         //xy=3665.0001220703125,1390.3332815170288
AudioSynthSimpleDrum     drumKick;          //xy=3754.0001220703125,1234.3333730697632
AudioAmplifier           ampSnare;       //xy=3844.0003700256348,1282.3333740234375
AudioFilterStateVariable filterHat; //xy=3895.5156745910645,1387.5156354904175
AudioAmplifier           ampKick;       //xy=3965.000244140625,1206.3334035873413
AudioEffectDigitalCombine combine1;       //xy=4001.0000495910645,1335.3333234786987
AudioEffectEnvelope      envelopeHAt;     //xy=4060.0001258850098,1390.3333129882812
AudioMixer4              mixerFinalL;    //xy=4320.000049591064,1112.333343744278
AudioMixer4              mixerFinalR;    //xy=4615.000049591064,1424.3333234786987
AudioOutputAnalogStereo  dacs1;          //xy=4696.000049591064,1244.3333234786987
AudioConnection          patchCord1(waveformMod3Osc2Voice1, 0, mixerOsc2Voice1, 2);
AudioConnection          patchCord2(waveformMod4Osc2Voice1, 0, mixerOsc2Voice1, 3);
AudioConnection          patchCord3(waveformMod1Osc2Voice1, 0, mixerOsc2Voice1, 0);
AudioConnection          patchCord4(waveformMod2Osc2Voice1, 0, mixerOsc2Voice1, 1);
AudioConnection          patchCord5(waveformMod1Osc1Voice1, 0, mixerOsc1Voice1, 0);
AudioConnection          patchCord6(waveformMod2Osc1Voice1, 0, mixerOsc1Voice1, 1);
AudioConnection          patchCord7(waveformMod4Osc1Voice1, 0, mixerOsc1Voice1, 3);
AudioConnection          patchCord8(waveformMod3Osc1Voice1, 0, mixerOsc1Voice1, 2);
AudioConnection          patchCord9(pinkVoice1, 0, mixerVoice1, 2);
AudioConnection          patchCord10(mixerOsc2Voice1, 0, mixerVoice1, 1);
AudioConnection          patchCord11(mixerOsc1Voice1, 0, mixerVoice1, 0);
AudioConnection          patchCord12(mixerVoice1, envelopeVoice1);
AudioConnection          patchCord13(envelopeVoice1, 0, mixerAllVoices, 0);
AudioConnection          patchCord14(mixerAllVoices, ampVcf);
AudioConnection          patchCord15(dcVcfEnvAmmount, envelopeVcf);
AudioConnection          patchCord16(envelopeVcf, 0, mixerVcf, 0);
AudioConnection          patchCord17(ampVcf, 0, filterVcf, 0);
AudioConnection          patchCord18(filterVcf, 0, mixerLpassHpass, 0);
AudioConnection          patchCord19(filterVcf, 2, mixerLpassHpass, 1);
AudioConnection          patchCord20(mixerVcf, 0, filterVcf, 1);
AudioConnection          patchCord21(sineLfoVcf, 0, mixerVcf, 1);
AudioConnection          patchCord22(mixerLpassHpass, 0, mixerDelayFb, 0);
AudioConnection          patchCord23(mixerLpassHpass, ampDry);
AudioConnection          patchCord24(mixerLpassHpass, 0, mixerDelayFf, 0);
AudioConnection          patchCord25(ampDry, 0, mixerFxL, 3);
AudioConnection          patchCord26(ampDry, 0, mixerFxR, 3);
AudioConnection          patchCord27(mixerDelayFb, delay1);
AudioConnection          patchCord28(delay1, 0, mixerDelayFb, 3);
AudioConnection          patchCord29(delay1, 0, ampDly, 0);
AudioConnection          patchCord30(ampDly, 0, mixerFxL, 0);
AudioConnection          patchCord31(ampDly, 0, mixerFxR, 0);
AudioConnection          patchCord32(ampDly, 0, mixerDelayFf, 1);
AudioConnection          patchCord33(mixerDelayFf, freeverbs1);
AudioConnection          patchCord34(mixerDelayFf, bitcrusher1);
AudioConnection          patchCord35(bitcrusher1, ampBc);
AudioConnection          patchCord36(freeverbs1, 0, ampRvbL, 0);
AudioConnection          patchCord37(freeverbs1, 1, ampRvbR, 0);
AudioConnection          patchCord38(ampRvbL, 0, mixerFxL, 1);
AudioConnection          patchCord39(ampRvbR, 0, mixerFxR, 1);
AudioConnection          patchCord40(ampBc, 0, mixerFxL, 2);
AudioConnection          patchCord41(ampBc, 0, mixerFxR, 2);
AudioConnection          patchCord42(mixerFxL, 0, mixerFinalL, 1);
AudioConnection          patchCord43(mixerFxR, 0, mixerFinalR, 1);
AudioConnection          patchCord44(drumSnare, ampSnare);
AudioConnection          patchCord45(noiseSnare, 0, combine1, 1);
AudioConnection          patchCord46(noiseHat, 0, filterHat, 0);
AudioConnection          patchCord47(drumKick, ampKick);
AudioConnection          patchCord48(ampSnare, 0, combine1, 0);
AudioConnection          patchCord49(filterHat, 0, envelopeHAt, 0);
AudioConnection          patchCord50(ampKick, 0, mixerFinalL, 0);
AudioConnection          patchCord51(ampKick, 0, mixerFinalR, 0);
AudioConnection          patchCord52(combine1, 0, mixerFinalL, 2);
AudioConnection          patchCord53(combine1, 0, mixerFinalR, 2);
AudioConnection          patchCord54(envelopeHAt, 0, mixerFinalL, 3);
AudioConnection          patchCord55(envelopeHAt, 0, mixerFinalR, 3);
AudioConnection          patchCord56(mixerFinalL, 0, dacs1, 0);
AudioConnection          patchCord57(mixerFinalR, 0, dacs1, 1);
// GUItool: end automatically generated code




//#include <ADC.h>
//#include <ADC_util.h>

#include "util.h"
#include "voice.h"




///////////////////////////////////////////////
//SETUP / LOOP
///////////////////////////////////////////////
bool gNoteOn [128];
float glideTimeMillis;
float gLastFrequency = 100;
float gDetune;

Voice voice1(& waveformMod3Osc1Voice1, & waveformMod4Osc1Voice1, &  waveformMod1Osc1Voice1, & waveformMod2Osc1Voice1,
    & waveformMod3Osc2Voice1, & waveformMod4Osc2Voice1, &  waveformMod1Osc2Voice1, & waveformMod2Osc2Voice1
);


void setup() {

#ifdef DEBUG_ENABLE
    Serial.begin(9600);
#endif
    AudioMemory(400);

    setConstantSettings();    
    initKnobPoller();
    initLookupTable();
    for( int i=0; i<128 ; i++){
        gNoteOn[i] = false;
    }
}





//with this scheme we get a new envelope every time a new note is hit,
//and the envelope realses only when that new note is released
void handleNoteOn(byte channel, byte note, byte velocity){
    Serial.println("note on");
    voice1.noteOn(channel, note, velocity);
    voice1.setStepFreuequency(true);


    int totalOn = 0;
    for( unsigned int i = 0 ; i< ARRAY_SIZE(gNoteOn); i++){
        if (gNoteOn[i]) {
            totalOn = totalOn+1;
        }
    }    
    if(totalOn ==0) {//todo update when I have more voices
        envelopeVcf.noteOn();
        envelopeVoice1.noteOn();
    }
    gNoteOn[note] = true;  
        
    
}


void handleNoteOff( byte channel, byte note, byte velocity){
    Serial.println("note off");
    gNoteOn[note] = false;

    //search
    int firstTrue = -1;
    for( unsigned int i = 0 ; i< ARRAY_SIZE(gNoteOn); i++){
        if (gNoteOn[i]) {
            firstTrue=i;            
        }
    }
    
    //decide if continuing or what
    if(firstTrue ==-1) {//todo update when I have more voices
        envelopeVcf.noteOff();
        envelopeVoice1.noteOff();
    } else {
        voice1.noteOn( channel,  note,  velocity);
        voice1.setStepFreuequency(true);        
    }

    
}



void loop() {
    //usbMIDI.read();
    serviceKnobPoller();   
    voice1.setStepFreuequency(); 
}
