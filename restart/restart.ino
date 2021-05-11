#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dcOsc2Shape;  //xy=235.515625,1095.515625
AudioSynthWaveformDc     dcOsc1Shape;            //xy=241.01565551757812,969.5157747268677
AudioMixer4              mixerOsc2Shape; //xy=481.515625,1110.515625
AudioMixer4              mixerOsc1Shape;         //xy=487.5156364440918,1011.5156307220459
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
AudioFilterStateVariable filterVcf;        //xy=1998,994.3333129882812
AudioMixer4              mixerVcf;         //xy=2018.0000953674316,1276.3333911895752
AudioSynthWaveformSine   sineLfoVcf;          //xy=2098.000114440918,1499.3333973884583
AudioMixer4              mixerLpassHpass;        //xy=2214.0000953674316,1128.3332691192627
AudioMixer4              mixerDelayFb;         //xy=2479,1432.3333129882812
AudioEffectDelay         delay1;         //xy=2642.00040435791,1436.3333234786987
AudioEffectBitcrusher    bitcrusher1;    //xy=3074.000476837158,1570.3333387374878
AudioEffectFreeverbStereo freeverbs1;     //xy=3096.0000495910645,1257.3332624435425
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
AudioConnection          patchCord1(dcOsc2Shape, 0, mixerOsc2Shape, 0);
AudioConnection          patchCord2(dcOsc1Shape, 0, mixerOsc1Shape, 0);
AudioConnection          patchCord3(mixerOsc2Shape, 0, waveformMod1Osc2Voice1, 1);
AudioConnection          patchCord4(mixerOsc2Shape, 0, waveformMod2Osc2Voice1, 1);
AudioConnection          patchCord5(mixerOsc2Shape, 0, waveformMod3Osc2Voice1, 1);
AudioConnection          patchCord6(mixerOsc2Shape, 0, waveformMod4Osc2Voice1, 1);
AudioConnection          patchCord7(mixerOsc1Shape, 0, waveformMod1Osc1Voice1, 1);
AudioConnection          patchCord8(mixerOsc1Shape, 0, waveformMod2Osc1Voice1, 1);
AudioConnection          patchCord9(mixerOsc1Shape, 0, waveformMod3Osc1Voice1, 1);
AudioConnection          patchCord10(mixerOsc1Shape, 0, waveformMod4Osc1Voice1, 1);
AudioConnection          patchCord11(waveformMod3Osc2Voice1, 0, mixerOsc2Voice1, 2);
AudioConnection          patchCord12(waveformMod4Osc2Voice1, 0, mixerOsc2Voice1, 3);
AudioConnection          patchCord13(waveformMod1Osc2Voice1, 0, mixerOsc2Voice1, 0);
AudioConnection          patchCord14(waveformMod2Osc2Voice1, 0, mixerOsc2Voice1, 1);
AudioConnection          patchCord15(waveformMod1Osc1Voice1, 0, mixerOsc1Voice1, 0);
AudioConnection          patchCord16(waveformMod2Osc1Voice1, 0, mixerOsc1Voice1, 1);
AudioConnection          patchCord17(waveformMod4Osc1Voice1, 0, mixerOsc1Voice1, 3);
AudioConnection          patchCord18(waveformMod3Osc1Voice1, 0, mixerOsc1Voice1, 2);
AudioConnection          patchCord19(pinkVoice1, 0, mixerVoice1, 2);
AudioConnection          patchCord20(mixerOsc2Voice1, 0, mixerVoice1, 1);
AudioConnection          patchCord21(mixerOsc1Voice1, 0, mixerVoice1, 0);
AudioConnection          patchCord22(mixerVoice1, envelopeVoice1);
AudioConnection          patchCord23(envelopeVoice1, 0, mixerAllVoices, 0);
AudioConnection          patchCord24(mixerAllVoices, 0, filterVcf, 0);
AudioConnection          patchCord25(dcVcfEnvAmmount, envelopeVcf);
AudioConnection          patchCord26(envelopeVcf, 0, mixerVcf, 0);
AudioConnection          patchCord27(filterVcf, 0, mixerLpassHpass, 0);
AudioConnection          patchCord28(filterVcf, 2, mixerLpassHpass, 1);
AudioConnection          patchCord29(mixerVcf, 0, filterVcf, 1);
AudioConnection          patchCord30(sineLfoVcf, 0, mixerVcf, 1);
AudioConnection          patchCord31(mixerLpassHpass, 0, mixerDelayFb, 0);
AudioConnection          patchCord32(mixerDelayFb, delay1);
AudioConnection          patchCord33(delay1, 0, mixerDelayFb, 3);
AudioConnection          patchCord34(delay1, 0, freeverbs1, 0);
AudioConnection          patchCord35(delay1, 0, bitcrusher1, 0);
AudioConnection          patchCord36(delay1, 0, mixerFxL, 0);
AudioConnection          patchCord37(delay1, 0, mixerFxR, 0);
AudioConnection          patchCord38(bitcrusher1, 0, mixerFxR, 2);
AudioConnection          patchCord39(bitcrusher1, 0, mixerFxL, 2);
AudioConnection          patchCord40(freeverbs1, 0, mixerFxL, 1);
AudioConnection          patchCord41(freeverbs1, 1, mixerFxR, 1);
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

//#include "timer.h"





///////////////////////////////////////////////
//SETUP / LOOP
///////////////////////////////////////////////


void setup() {

#ifdef DEBUG_ENABLE
    Serial.begin(9600);
#endif
    AudioMemory(400);

    initKnobPoller();




}




void loop() {
    //usbMIDI.read();
    serviceKnobPoller();    
}
